package main

import (
    "bytes"
    "errors"
    "fmt"
    "github.com/fatih/color"
    "log"
    "os"
    "os/exec"
    "push_swap_checker/pkg/asciiart"
    "push_swap_checker/pkg/exam"
    "push_swap_checker/pkg/judge"
    "strconv"
    "strings"
    "time"
)

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

func extractSolution(data string) []string {
    if len(data) <= 0 {
        return []string{}
    }
    if data[len(data)-1] == '\n' {
        data = data[:len(data)-1]
    }
    return strings.Split(data, "\n")
}

func toInts(data string) (nums []int) {
    txtNums := strings.Split(data, " ")
    for _, txtNum := range txtNums {
        if len(txtNum) <= 0 {
            continue
        }
        num, err := strconv.Atoi(txtNum)
        if err != nil {
            log.Fatal(err)
        }
        nums = append(nums, num)
    }
    return
}

func showOK(msg string) {
    color.Green("[OK] " + msg)
}

func showLeak() {
    color.Magenta("[LEAK]")
}

func showFail(msg string) {
    color.Red("[FAIL] %s", msg)
}

func leakAndTimeoutDetected(command string, timeout time.Duration) (isLeaked bool, isTimeout bool) {
    var stderr string
    _, stderr, isTimeout = runCmd(command, timeout)
    isLeaked = strings.Contains(stderr, "SUMMARY") && !strings.Contains(stderr, "All heap blocks were freed")
    return
}

func runTests(tests []exam.Test) {
    if _, err := os.Stat("push_swap"); errors.Is(err, os.ErrNotExist) {
        showFail("pipex executable not found")
        return
    }

    var TimeOut = 5 * time.Second
    cntPass, cntFail, cntLeak := 0, 0, 0
    for i, t := range tests {
        fmt.Printf("Test %d: %s\n", i+1, t.Desc)
        command := fmt.Sprintf("./push_swap %s", t.Args)
        isLeaked, isTimeout := leakAndTimeoutDetected(command, TimeOut)
        if isLeaked {
            cntLeak++
            showLeak()
            continue
        }
        if isTimeout {
            cntFail++
            showFail("timeout...probably infinite loop")
            continue
        }
        stdout, stderr, _ := runCmd(command, TimeOut)
        if t.ExpectError {
            if strings.Contains(stdout, "Error\n") || strings.Contains(stderr, "Error\n") {
                cntPass++
                showOK("")
            } else {
                cntFail++
                showFail("should display error")
            }
            continue
        }
        if !t.ExpectOutput {
            if stdout != "" {
                cntFail++
                showFail("should display nothing")
            } else {
                cntPass++
                showOK("")
            }
            continue
        }
        solution := extractSolution(stdout)
        if !judge.VerifySolution(toInts(t.Args), solution) {
            showFail("stack is not sorted")
            cntFail++
            continue
        }
        score := 0
        for i, limit := range t.Limits {
            if len(solution) <= limit {
                score = i + 1
            }
        }
        if score == 0 {
            showFail(fmt.Sprintf("too many moves\nLimit: %d, Actual: %d", t.Limits[0], len(solution)))
            cntFail++
            continue
        }
        cntPass++
        if len(t.Limits) == 1 {
            showOK(fmt.Sprintf("Limit: %d, Actual: %d", t.Limits[0], len(solution)))
        } else {
            showOK(fmt.Sprintf("Score: %d / %d\nLimit: %d, Actual: %d", score, len(t.Limits), t.Limits[score-1], len(solution)))
        }
    }
    fmt.Println()
    fmt.Println("-------------------------")
    fmt.Printf("SUMMARY: %s %s %s\n",
        color.GreenString("%d [OK]", cntPass),
        color.RedString("%d [Fail]", cntFail),
        color.MagentaString("%d [LEAK]", cntLeak),
    )
}

func main() {
    asciiart.DisplayPushSwapLogo()
    var tests = exam.NewTestSuite()
    runTests(tests)
}
