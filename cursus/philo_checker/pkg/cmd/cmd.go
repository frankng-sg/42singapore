package cmd

import (
	"bytes"
	"os/exec"
	"time"
)

func Run(command string, timeout time.Duration) (string, string) {
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
		return stdout.String(), stderr.String()
	case <-time.After(timeout):
		cmd.Process.Kill()
		return "", ""
	}
}
