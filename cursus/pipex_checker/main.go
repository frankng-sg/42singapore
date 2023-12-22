package main

import (
	"bytes"
	"fmt"
	"os"
	"os/exec"
	"errors"
	"strings"
)

func runCmd(command string) (string, string, error) {
	var stdout bytes.Buffer
	var stderr bytes.Buffer

	cmd := exec.Command("bash", "-c", command)
	cmd.Stdout = &stdout
	cmd.Stderr = &stderr
	err := cmd.Run()
	return stdout.String(), stderr.String(), err
}

type Test struct {
	Desc              string
	Cmd1              string
	Cmd2              string
	InputFile         string
	OutputFile        string
	ExpectFileCreated bool
	ExpectFileContent     string
}

func NewTestSuite() []Test {
	return []Test{
		{
			Desc:          "Program does not crash with empty params",
			ExpectFileContent: "",
		},
	}
}

func leakDetected(t Test) bool {
	args := fmt.Sprintf("%s %s %s %s", t.InputFile, t.Cmd1, t.Cmd2, t.OutputFile)
	stdout, _, _ := runCmd(fmt.Sprintf("valgrind --leak-check=full ./pipex %s", args))
	return strings.Contains(stdout, "All heap blocks were freed")
}

func main() {
	fmt.Println("==== TESTING pipex ====")
	fmt.Println()
	for i, t := range NewTestSuite() {
		fmt.Printf("Test #%d: %s\n", i, t.Desc)
		if leakDetected(t) {
			fmt.Printf("[FAIL] program should not leak memory\n", i)
			continue
		}
		args := fmt.Sprintf("%s %s %s %s", t.InputFile, t.Cmd1, t.Cmd2, t.OutputFile)
		stdout, _, _ := runCmd(fmt.Sprintf("./pipex %s", args))
		_, err := os.Stat(t.OutputFile)
		if t.ExpectFileCreated && errors.Is(err, os.ErrNotExist) {
			fmt.Printf("[FAIL] output file should exist")
			continue
		}
		if !t.ExpectFileCreated && !errors.Is(err, os.ErrNotExist) {
			fmt.Println("[FAIL] output file should not exist")
			continue
		}
		if !t.ExpectFileCreated && stdout != t.ExpectFileContent {
			fmt.Printf("[FAIL] output mismatched\nExpected: %q\nActual: %q\n", t.ExpectFileContent, stdout)
			continue
		}
		fmt.Println("[OK]")
	}
}
