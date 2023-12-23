package main

import (
	"bytes"
	"fmt"
	"github.com/fatih/color"
	"log"
	"os/exec"
	"push_swap_checker/pkg/asciiart"
	"push_swap_checker/pkg/exam"
	"push_swap_checker/pkg/judge"
	"strconv"
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

func leakDetected(command string) bool {
	_, stderr, _ := runCmd(fmt.Sprintf("valgrind --leak-check=full %s", command))
	isLeaked := strings.Contains(stderr, "SUMMARY") && !strings.Contains(stderr, "All heap blocks were freed")
	return isLeaked
}

func runTests(tests []exam.Test) {
	cntPass, cntFail, cntLeak := 0, 0, 0
	for i, t := range tests {
		fmt.Printf("Test %d: %s\n", i+1, t.Desc)
		command := fmt.Sprintf("./push_swap %s", t.Args)
		if leakDetected(command) {
			cntLeak++
			showLeak()
			continue
		}
		stdout, stderr, _ := runCmd(command)
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
