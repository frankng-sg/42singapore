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
			InputFile:         "not_exist.txt",
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

func runCmd(command string) (string, string, error) {
	var stdout bytes.Buffer
	var stderr bytes.Buffer

	cmd := exec.Command("bash", "-c", command)
	cmd.Stdout = &stdout
	cmd.Stderr = &stderr
	err := cmd.Run()
	return stdout.String(), stderr.String(), err
}

func leakDetected(t Test) bool {
	args := fmt.Sprintf("%s %q %q %s", t.InputFile, t.Cmd1, t.Cmd2, t.OutputFile)
	_, stderr, _ := runCmd(fmt.Sprintf("valgrind --leak-check=full ./pipex %s", args))
	isLeaked := strings.Contains(stderr, "SUMMARY") && !strings.Contains(stderr, "All heap blocks were freed")
	return isLeaked
}

var (
	PASS = color.GreenString("[OK]")
	FAIL = color.RedString("[FAIL]")
	LEAK = color.MagentaString("[LEAK]")
)

func main() {
	color.Blue("+----------------------------------+")
	color.Blue("|          PIPEX CHECKER           |")
	color.Blue("+----------------------------------+")
	fmt.Println()
	tests := NewTestSuite()
	cntPass, cntFail, cntLeak := 0, 0, 0
	for i, t := range tests {
		fmt.Printf("Test #%d: %s\n", i+1, t.Desc)
		if leakDetected(t) {
			fmt.Println(LEAK)
			cntLeak++
			continue
		}
		if !t.KeepOutputFile && t.OutputFile != "" {
			os.Remove(t.OutputFile)
		}
		args := fmt.Sprintf("%s %q %q %s", t.InputFile, t.Cmd1, t.Cmd2, t.OutputFile)
		stdout, _, err := runCmd(fmt.Sprintf("./pipex %s", args))
		if stdout != "" {
			fmt.Println(FAIL, "program should not print anything to stdout")
			cntFail++
			continue
		}
		if t.ExpectError && err == nil {
			fmt.Println(FAIL, "program should return error message")
			cntFail++
			continue
		}
		_, err = os.Stat(t.OutputFile)
		if t.ExpectFileCreated && errors.Is(err, os.ErrNotExist) {
			fmt.Println(FAIL, "output file should exist")
			cntFail++
			continue
		}
		if !t.ExpectFileCreated && !errors.Is(err, os.ErrNotExist) {
			fmt.Println(FAIL, "output file should not exist")
			cntFail++
			continue
		}
		content, err := ioutil.ReadFile(t.OutputFile)
		if t.ExpectFileCreated && string(content) != t.ExpectFileOutput {
			fmt.Printf("%s output mismatched\n\tExpected: %q\n\tActual: %q\n", FAIL, t.ExpectFileOutput, string(content))
			cntFail++
			continue
		}
		cntPass++
		fmt.Println(PASS)
	}
	fmt.Println("-----------------------------------------")
	fmt.Println("SUMMARY: ",
		color.GreenString(fmt.Sprintf("%d", cntPass)), PASS, ",",
		color.RedString(fmt.Sprintf("%d", cntFail)), FAIL, ",",
		color.MagentaString(fmt.Sprintf("%d", cntLeak)), LEAK,
	)
	for _, t := range tests {
		if !t.KeepOutputFile && t.OutputFile != "" {
			os.Remove(t.OutputFile)
		}
	}
}
