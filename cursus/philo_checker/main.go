package main

import (
	"errors"
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

func runCmd(t exam.TestData, keeper *book_keeper.BookKeeper, command string, timeout time.Duration) error {
	out, err := cmd.Run(command, timeout)
	if err != nil {
		return err
	}
	events := strings.Split(out, "\n")
	for i := 0; i < len(events); i++ {
		if events[i] == "" {
			break
		}
		parts := strings.Split(events[i], " ")
		timestamp, err := strconv.ParseInt(parts[0], 10, 64)
		if err != nil {
			return errors.New("incorrect timestamp")
		}
		philoId, err := strconv.Atoi(parts[1])
		if err != nil {
			return errors.New("incorrect philosopher id")
		}
		eventDesc := strings.Join(parts[2:], " ")
		err = keeper.Add(philoId, book_keeper.PhiloEvent{
			Timestamp: timestamp,
			Type:      book_keeper.GetPhiloEventType(eventDesc),
		})
		if err != nil {
			return err
		}
	}

	if err = keeper.Finalize(); err != nil {
		return err
	} else if t.ExpectDeath && !keeper.DeathHappened {
		return errors.New("philosopher should die")
	} else if !t.ExpectDeath && keeper.DeathHappened {
		return errors.New("philosopher should not die")
	}
	return nil
}

func runTest(testNo int, t exam.TestData, timeout time.Duration) error {
	var cmdStr string
	if t.NMeals == -1 {
		t.NMeals = 5
	}
	cmdStr = fmt.Sprintf("./philo %d %d %d %d %d", t.NPhilos, t.T2Live, t.T2Eat, t.T2Sleep, t.NMeals)
	fmt.Printf("TEST %d: %s ", testNo, cmdStr)
	keeper := book_keeper.NewBookKeeper(t.NPhilos, t.T2Live, t.T2Eat, t.T2Sleep, t.NMeals)
	return runCmd(t, keeper, cmdStr, timeout)
}

func runTests(tests []exam.TestData) {
	timeout := 10 * time.Second
	fmt.Println(logo.Logo())
	cntOK := 0
	cntKO := 0

	for i, t := range tests {
		err := runTest(i, t, timeout)
		if err != nil {
			color.Red("[KO] ...%s\n", err.Error())
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
