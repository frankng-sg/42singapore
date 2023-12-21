package main

import (
	"bufio"
	"bytes"
	"fmt"
	"io"
	"os"
	"os/exec"
	"strconv"
	"strings"
)

type Test struct {
	FilePath    string // Path to input file
	ExpectError bool
	ExpectLimit []int // Maximum number of moves to sort the stack
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

func extractSolution(data string) []string {
	if len(data) <= 0 {
		return []string{}
	}
	if data[len(data)-1] == '\n' {
		data = data[:len(data)-1]
	}
	return strings.Split(data, "\n")
}

func readInput(filepath string) (nums []int) {
	f, err := os.Open(filepath)
	if err != nil {
		panic(err)
	}
	defer f.Close()
	reader := bufio.NewReader(f)
	for {
		txtVal, err := reader.ReadString(' ')
		if err == io.EOF {
			break
		}
		if err != nil {
			panic(err)
		}
		txtVal = strings.TrimSpace(txtVal)
		val, err := strconv.Atoi(txtVal)
		if err != nil {
			panic(err)
		}
		nums = append(nums, val)
	}
	return
}

func swap(nums []int) {
	if len(nums) < 2 {
		return
	}
	nums[0], nums[1] = nums[1], nums[0]
}

func push(src *[]int, dst *[]int) {
	if len(*src) < 1 {
		return
	}
	val := (*src)[0]
	*dst = append([]int{val}, *dst...)
	*src = (*src)[1:]
}

func rotate(nums *[]int) {
	if len(*nums) < 2 {
		return
	}
	val := (*nums)[0]
	*nums = append((*nums)[1:], val)
}

func revRotate(nums *[]int) {
	if len(*nums) < 2 {
		return
	}
	val := (*nums)[len(*nums)-1]
	*nums = append([]int{val}, (*nums)[:len(*nums)-1]...)
}

func verifySolution(filepath string, solution []string) bool {
	stackA := readInput("tests/" + filepath)
	stackB := []int{}
	for _, cmd := range solution {
		switch cmd {
		case "sa":
			swap(stackA)
		case "sb":
			swap(stackB)
		case "ss":
			swap(stackA)
			swap(stackB)
		case "pa":
			push(&stackB, &stackA)
		case "pb":
			push(&stackA, &stackB)
		case "ra":
			rotate(&stackA)
		case "rb":
			rotate(&stackB)
		case "rr":
			rotate(&stackA)
			rotate(&stackB)
		case "rra":
			revRotate(&stackA)
		case "rrb":
			revRotate(&stackB)
		case "rrr":
			revRotate(&stackA)
			revRotate(&stackB)
		default:
			panic("Invalid command")
		}
	}
	for i := 1; i < len(stackA); i++ {
		if stackA[i-1] > stackA[i] {
			return false
		}
	}
	return true
}

func runTests(tests []Test) {
	for i, t := range tests {
		fmt.Printf("\nTest %d: %s ", i+1, t.FilePath)
		command := fmt.Sprintf("cat tests/%s | xargs ./push_swap", t.FilePath)
		stdout, _, err := runCmd(command)
		if err != nil {
			fmt.Printf("[FAIL: program crashed]")
			return
		}
		if t.ExpectError {
			if strings.Contains(stdout, "Error") {
				fmt.Printf("[PASS]")
			} else {
				fmt.Printf("[FAIL]")
			}
			continue
		}
		solution := extractSolution(stdout)
		if !verifySolution(t.FilePath, solution) {
			fmt.Printf("[FAIL]...stack is not sorted")
			continue
		}
		score := 0
		for i, limit := range t.ExpectLimit {
			if len(solution) <= limit {
				score = i + 1
			}
		}
		if score == 0 {
			fmt.Printf("[FAIL]...too many moves (Limit: %d, Actual: %d)", t.ExpectLimit[len(t.ExpectLimit)-1], len(solution))
			continue
		}
		fmt.Printf("[PASS]...Score: 1 / %d", len(t.ExpectLimit))
	}
	fmt.Println()
}

func main() {
	var tests = []Test{
		{"empty.txt", false, []int{0}},
		{"onenum.txt", false, []int{0}},
		{"twonum.txt", false, []int{1}},
		{"integerlimit.txt", false, []int{0}},
		{"integerlimit1.txt", true, []int{0}},
		{"invalidnumber1.txt", true, []int{0}},
		{"invalidnumber2.txt", true, []int{0}},
		{"invalidnumber3.txt", true, []int{0}},
		{"invalidnumber1.txt", true, []int{0}},
		{"random3.txt", false, []int{3}},
		{"random5.txt", false, []int{12}},
		{"random100.txt", false, []int{1500, 1300, 1100, 900, 700}},
		{"random500.txt", false, []int{11500, 10000, 8500, 7000, 5500}},
	}
	runTests(tests)
}
