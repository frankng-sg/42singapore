package main

import (
	"bytes"
	"errors"
	"fmt"
	"github.com/fatih/color"
	"io/ioutil"
	"os"
	"os/exec"
	"strings"
	"time"
)

type Test struct {
	Desc              string
	Cmd1              string
	Cmd2              string
	InputFile         string
	OutputFile        string
	ExpectError       bool
	ExpectFileCreated bool
	ExpectFileOutput  string
	KeepOutputFile    bool
}

func NewTestSuite() []Test {
	return []Test{
		{
			Desc:        "Program should return error if there is 0 argument",
			ExpectError: true,
		},
		{
			Desc:        "Program should return error if there is 1 argument",
			InputFile:   "tests/input.txt",
			ExpectError: true,
		},
		{
			Desc:        "Program should return error if there is 2 argument",
			InputFile:   "tests/input.txt",
			Cmd1:        "cat",
			ExpectError: true,
		},
		{
			Desc:        "Program should return error if there is 3 argument",
			InputFile:   "tests/input.txt",
			Cmd1:        "cat",
			Cmd2:        "wc",
			ExpectError: true,
		},
		{
			Desc:              "Program should create correct output file in normal flow\ne.g `./pipex infile cat \"wc -w\" outfile`",
			InputFile:         "tests/input.txt",
			OutputFile:        "output.txt",
			Cmd1:              "cat",
			Cmd2:              "wc -w",
			ExpectFileCreated: true,
			ExpectFileOutput:  "423\n",
		},
		{
			Desc:              "Program should return error if input file does not exist",
			InputFile:         "not_exist.txt",
			OutputFile:        "output.txt",
			Cmd1:              "cat",
			Cmd2:              "wc -w",
			ExpectFileCreated: false,
			ExpectError:       true,
		},
		{
			Desc:              "Program should return error if output file exists and cannot be overwritten",
			InputFile:         "input.txt",
			OutputFile:        "no_permission.txt",
			Cmd1:              "cat",
			Cmd2:              "wc -w",
			ExpectFileCreated: false,
			ExpectError:       true,
			KeepOutputFile:    true,
		},
		{
			Desc:              "Program should create correct output file if a user-created command is used\ne.g `./pipex infile ../mycmd1 \"wc -w\" outfile`",
			InputFile:         "tests/input.txt",
			OutputFile:        "output.txt",
			Cmd1:              "tests/helloworld",
			Cmd2:              "wc -w",
			ExpectFileCreated: true,
			ExpectFileOutput:  "2\n",
		},
		{
			Desc:              "Program should create correct output file if command argument has double quotes\ne.g `./pipex infile cat 'grep \"hello world\"' outfile`",
			InputFile:         "tests/input.txt",
			OutputFile:        "output.txt",
			Cmd1:              `grep "Hello World"`,
			Cmd2:              "wc -w",
			ExpectFileCreated: true,
			ExpectFileOutput:  "9\n",
		},
		{
			Desc:              `Program should create correct output file if command argument has double quotes and a user-created command is used`,
			InputFile:         "tests/input.txt",
			OutputFile:        "output.txt",
			Cmd1:              `tests/helloworld`,
			Cmd2:              "grep \"Hello, World\"",
			ExpectFileCreated: true,
			ExpectFileOutput:  "Hello, World!\n",
		},
		{
			Desc:        "Program should return error if first command is not found",
			InputFile:   "tests/input.txt",
			Cmd1:        "not_found",
			Cmd2:        "wc",
			ExpectError: true,
		},
		{
			Desc:        "Program should return error if second command is not found",
			InputFile:   "tests/input.txt",
			Cmd1:        "cat",
			Cmd2:        "not_found",
			ExpectError: true,
		},
	}
}

func runCmd(command string, timeout time.Duration) (string, string, bool) {
	var stdout bytes.Buffer
	var stderr bytes.Buffer

	cmd := exec.Command("bash", "-c", command)
	cmd.Stdout = &stdout
	cmd.Stderr = &stderr

	goRunCmd := func() <-chan struct{} {
		done := make(chan struct{})
		go func() {
			defer close(done)
			cmd.Run()
		}()
		return done
	}

	select {
	case <-goRunCmd():
		return stdout.String(), stderr.String(), false
	case <-time.After(timeout):
		cmd.Process.Kill()
		return "", "", true
	}
}

func leakAndTimeoutDetected(t Test, timeout time.Duration) (isLeaked bool, isTimeout bool) {
	var stderr string
	args := fmt.Sprintf("%s %q %q %s", t.InputFile, t.Cmd1, t.Cmd2, t.OutputFile)
	_, stderr, isTimeout = runCmd(fmt.Sprintf("valgrind --leak-check=full ./pipex %s", args), timeout)
	isLeaked = strings.Contains(stderr, "SUMMARY") && !strings.Contains(stderr, "All heap blocks were freed")
	return isLeaked, isTimeout
}

func showOK() {
	color.Green("[OK]")
}

func showFail(msg string) {
	color.Red(fmt.Sprintf("[FAIL] %s", msg))
}

func showLeak() {
	color.Magenta("[LEAK]")
}

func main() {
	color.Blue(` +----------------------------------+`)
	color.Blue(`/ \          PIPEX CHECKER           \`)
	color.Blue(`|  | _  _  _  _  _  _  _  _  _  _  _  |`)
	color.Blue(`|  || || || || || || || || || || || | |`)
	color.Blue(` \///_//_//_//_//_//_//_//_//_//_//_//`)
	fmt.Println()
	if _, err := os.Stat("pipex"); errors.Is(err, os.ErrNotExist) {
		showFail("pipex executable not found")
		return
	}
	var timeout time.Duration = 5 * time.Second
	var err error
	tests := NewTestSuite()
	cntPass, cntFail, cntLeak := 0, 0, 0
	for i, t := range tests {
		fmt.Printf("Test #%d: %s\n", i+1, t.Desc)
		isLeaked, isTimeout := leakAndTimeoutDetected(t, timeout)
		if isTimeout {
			showFail("timeout...probably infinite loop")
			cntFail++
			continue
		}
		if isLeaked {
			showLeak()
			cntLeak++
			continue
		}
		if !t.KeepOutputFile && t.OutputFile != "" {
			os.Remove(t.OutputFile)
		}
		args := fmt.Sprintf("%s %q %q %s", t.InputFile, t.Cmd1, t.Cmd2, t.OutputFile)
		stdout, stderr, _ := runCmd(fmt.Sprintf("./pipex %s", args), timeout)
		if stdout != "" {
			showFail("program should not print anything to stdout")
			cntFail++
			continue
		}
		if t.ExpectError && stderr == "" {
			showFail("program should return error message")
			cntFail++
			continue
		}
		_, err = os.Stat(t.OutputFile)
		if t.ExpectFileCreated && errors.Is(err, os.ErrNotExist) {
			showFail("output file should exist")
			cntFail++
			continue
		}
		if !t.ExpectFileCreated && !errors.Is(err, os.ErrNotExist) {
			showFail("output file should not exist")
			cntFail++
			continue
		}
		content, _ := ioutil.ReadFile(t.OutputFile)
		if t.ExpectFileCreated && string(content) != t.ExpectFileOutput {
			showFail(fmt.Sprintf("output mismatched\n\tExpected: %q\n\tActual: %q\n", t.ExpectFileOutput, string(content)))
			cntFail++
			continue
		}
		cntPass++
		showOK()
	}
	fmt.Println("-----------------------------------------")
	fmt.Println("SUMMARY: ",
		color.GreenString(fmt.Sprintf("%d [OK], ", cntPass)),
		color.RedString(fmt.Sprintf("%d [FAIL]", cntFail)),
		color.MagentaString(fmt.Sprintf("%d [LEAK]", cntLeak)),
	)
	for _, t := range tests {
		if !t.KeepOutputFile && t.OutputFile != "" {
			os.Remove(t.OutputFile)
		}
	}
}
