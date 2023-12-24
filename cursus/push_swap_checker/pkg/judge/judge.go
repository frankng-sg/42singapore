package judge

import (
    "fmt"
    "github.com/fatih/color"
)

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

func VerifySolution(nums []int, solution []string) bool {
    stackA := nums
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
            color.Red(fmt.Sprintf("Invalid command: %s", cmd))
            return false
        }
    }
    for i := 1; i < len(stackA); i++ {
        if stackA[i-1] > stackA[i] {
            return false
        }
    }
    return true
}
