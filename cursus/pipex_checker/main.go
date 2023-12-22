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
            Desc:        "Program returns error message with 0 params",
            ExpectError: true,
        },
        {
            Desc:        "Program returns error message with 1 param",
            InputFile:   "tests/input.txt",
            ExpectError: true,
        },
        {
            Desc:        "Program returns error message with 2 param",
            InputFile:   "tests/input.txt",
            Cmd1:        "cat",
            ExpectError: true,
        },
        {
            Desc:        "Program returns error message with 3 param",
            InputFile:   "tests/input.txt",
            Cmd1:        "cat",
            Cmd2:        "wc",
            ExpectError: true,
        },
        {
            Desc:              "Program produces output file in normal case",
            InputFile:         "tests/input.txt",
            OutputFile:        "output.txt",
            Cmd1:              "cat",
            Cmd2:              "wc -w",
            ExpectFileCreated: true,
            ExpectFileOutput:  "423\n",
        },
        {
            Desc:              "Program returns error message if input file not exist",
            InputFile:         "not_exist.txt",
            OutputFile:        "output.txt",
            Cmd1:              "cat",
            Cmd2:              "wc -w",
            ExpectFileCreated: false,
            ExpectError:       true,
        },
        {
            Desc:              "Program returns error message if output file cannot be created",
            InputFile:         "not_exist.txt",
            OutputFile:        "no_permission.txt",
            Cmd1:              "cat",
            Cmd2:              "wc -w",
            ExpectFileCreated: false,
            ExpectError:       true,
            KeepOutputFile:    true,
        },
        {
            Desc:              "Program produces output file with command in relative path (e.g. ./helloworld)",
            InputFile:         "tests/input.txt",
            OutputFile:        "output.txt",
            Cmd1:              "tests/helloworld",
            Cmd2:              "wc -w",
            ExpectFileCreated: true,
            ExpectFileOutput:  "2\n",
        },
        {
            Desc:              `Program produces output file with command like grep "hello world"`,
            InputFile:         "tests/input.txt",
            OutputFile:        "output.txt",
            Cmd1:              `grep "Hello World"`,
            Cmd2:              "wc -w",
            ExpectFileCreated: true,
            ExpectFileOutput:  "9\n",
        },
        {
            Desc:              `Program produces output file with ' ./helloworld | grep "Hello, World" '`,
            InputFile:         "tests/input.txt",
            OutputFile:        "output.txt",
            Cmd1:              `tests/helloworld`,
            Cmd2:              "grep \"Hello, World\"",
            ExpectFileCreated: true,
            ExpectFileOutput:  "Hello, World!\n",
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
    stdout, _, _ := runCmd(fmt.Sprintf("valgrind --leak-check=full ./pipex %s", args))
    return strings.Contains(stdout, "All heap blocks were freed")
}

var (
    PASS = color.GreenString("[OK]")
    FAIL = color.RedString("[FAIL]")
)

func main() {
    fmt.Println("==== TESTING pipex ====")
    fmt.Println()
    tests := NewTestSuite()
    cntPass, cntFail := 0, 0
    for i, t := range tests {
        fmt.Printf("Test #%d: %s\n", i+1, t.Desc)
        if leakDetected(t) {
            fmt.Println(FAIL, "memory leak...")
            cntFail++
            continue
        }
        if !t.KeepOutputFile && t.OutputFile != "" {
            os.Remove(t.OutputFile)
        }
        args := fmt.Sprintf("%s %q %q %s", t.InputFile, t.Cmd1, t.Cmd2, t.OutputFile)
        _, _, err := runCmd(fmt.Sprintf("./pipex %s", args))
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
    fmt.Println("SUMMARY: ", cntPass, PASS, ",", cntFail, FAIL)
    for _, t := range tests {
        if !t.KeepOutputFile && t.OutputFile != "" {
            os.Remove(t.OutputFile)
        }
    }
}
