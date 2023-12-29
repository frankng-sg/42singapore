package main

import (
	"bytes"
	"fmt"
	"os/exec"
	"time"

	"github.com/go-vgo/robotgo"
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

func main() {
	go func() {
		runCmd("./fractol mandelbrot iw600 ih400", 10 * time.Minute)
	}()
	time.Sleep(5 * time.Second)
	for {
		x, y := robotgo.Location()
		fmt.Println("Mouse: ", x, y)
		time.Sleep(2000 * time.Millisecond)
		robotgo.Move(4307, 372)
		robotgo.MilliSleep(100)
		robotgo.Click()
		robotgo.KeyTap("escape")
		time.Sleep(500 * time.Millisecond)
	}
}
