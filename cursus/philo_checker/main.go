package main

import (
	"fmt"
	"github.com/fatih/color"
	"philo_checker/pkg/book_keeper"
	"philo_checker/pkg/cmd"
	"philo_checker/pkg/exam"
	"philo_checker/pkg/logo"
	"strconv"
	"strings"
	"time"
)

func runTests(tests []exam.TestData) {
	var cmdStr string
	timeout := time.Minute
	fmt.Println(logo.Logo())
	cntOK := 0
	cntKO := 0

	for i, t := range tests {
		if t.NMeals == -1 {
			cmdStr = fmt.Sprintf("./philo %d %d %d %d", t.NPhilos, t.T2Live, t.T2Eat, t.T2Sleep)
		} else {
			cmdStr = fmt.Sprintf("./philo %d %d %d %d %d", t.NPhilos, t.T2Live, t.T2Eat, t.T2Sleep, t.NMeals)
		}
		fmt.Printf("TEST %d: %s ", i, cmdStr)
		stdout, stderr := cmd.Run(cmdStr, timeout)
		if stderr != "" {
			color.Red("[KO] ...should not throw error message\n")
			cntKO++
			continue
		}
		if stdout == "" {
			color.Red("[KO] ...should not print nothing\n")
			cntKO++
			continue
		}
		keeper := book_keeper.NewBookKeeper(1, 800, 200, 200, -1)
		events := strings.Split(stdout, "\n")
		events = events[:len(events)-1]
		failed := false
		for _, event := range events {
			parts := strings.Split(event, " ")
			timestamp, err := strconv.ParseInt(parts[0], 10, 64)
			if err != nil {
				color.Red("[KO] ...incorrect timestamp\n")
				cntKO++
				failed = true
				break
			}
			philoId, err := strconv.Atoi(parts[1])
			if err != nil {
				color.Red("[KO] ...incorrect philosopher id\n")
				cntKO++
				failed = true
				break
			}
			eventDesc := strings.Join(parts[2:], " ")
			err = keeper.Add(philoId, book_keeper.PhiloEvent{
				Timestamp: timestamp,
				Type:      book_keeper.GetPhiloEventType(eventDesc),
			})
			if err != nil {
				color.Red(fmt.Sprintf("[KO] ...%s\n", err.Error()))
				cntKO++
				failed = true
				break
			}
		}
		if failed {
			continue
		}
		err := keeper.Finalize()
		if err != nil {
			color.Red(fmt.Sprintf("[KO] ...%s\n", err.Error()))
			cntKO++
		} else if t.ExpectDeath && !keeper.DeathHappened {
			color.Red("[KO] ...philosopher should die\n")
			cntKO++
		} else if !t.ExpectDeath && keeper.DeathHappened {
			color.Red("[KO] ...philosopher should not die\n")
			cntKO++
		} else {
			color.Green("[OK]\n")
			cntOK++
		}
	}
	fmt.Println()
	fmt.Println("TOTAL:",
		color.GreenString("%d [OK]", cntOK),
		color.RedString("%d [KO]", cntKO),
	)
}

func main() {
	runTests(exam.Tests)
}
