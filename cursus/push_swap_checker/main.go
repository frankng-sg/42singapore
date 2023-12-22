package main

import (
    "bytes"
    "fmt"
    "github.com/fatih/color"
    "log"
    "os"
    "os/exec"
    "strconv"
    "strings"
)

var (
    PASS = color.GreenString("[OK]")
    FAIL = color.RedString("[FAIL]")
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
    data, err := os.ReadFile(filepath)
    if err != nil {
        log.Fatal(err)
    }
    txtNums := strings.Split(string(data), " ")
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
    cntPass, cntFail := 0, 0
    for i, t := range tests {
        fmt.Printf("\nTest %d: %s ", i+1, t.FilePath)
        command := fmt.Sprintf("cat tests/%s | xargs ./push_swap", t.FilePath)
        stdout, _, err := runCmd(command)
        if err != nil {
            fmt.Printf("%s program crashed", FAIL)
            cntFail++
            continue
        }
        if t.ExpectError {
            if strings.Contains(stdout, "Error") {
                cntPass++
                fmt.Printf(PASS)
            } else {
                cntFail++
                fmt.Printf(FAIL)
            }
            continue
        }
        solution := extractSolution(stdout)
        if !verifySolution(t.FilePath, solution) {
            fmt.Printf("%s...stack is not sorted", FAIL)
            cntFail++
            continue
        }
        score := 0
        for i, limit := range t.ExpectLimit {
            if len(solution) <= limit {
                score = i + 1
            }
        }
        if score == 0 {
            fmt.Printf("%s...too many moves (Limit: %d, Actual: %d)", FAIL, t.ExpectLimit[len(t.ExpectLimit)-1], len(solution))
            cntFail++
            continue
        }
        cntPass++
        fmt.Printf("%s...Score: %d / %d (Limit: %d, Actual: %d)",
            PASS, score, len(t.ExpectLimit), t.ExpectLimit[score-1], len(solution))
    }
    fmt.Println()
    fmt.Println("-------------------------")
    fmt.Printf("SUMMARY: %d %s, %d %s\n", cntPass, PASS, cntFail, FAIL)
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
        {"sorted3.txt", false, []int{0}},
        {"sorted5.txt", false, []int{0}},
        {"sorted12.txt", false, []int{0}},
        {"random3.txt", false, []int{3}},
        {"random5.txt", false, []int{12}},
        {"random100.txt", false, []int{1500, 1300, 1100, 900, 700}},
        {"random500.txt", false, []int{11500, 10000, 8500, 7000, 5500}},
    }
    runTests(tests)
}
