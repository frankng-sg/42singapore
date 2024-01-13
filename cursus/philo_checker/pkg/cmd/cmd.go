package cmd

import (
	"bytes"
	"errors"
	"os/exec"
	"time"
)

func Run(command string, timeout time.Duration) (string, error) {
	var stdout bytes.Buffer
	var stderr bytes.Buffer

	handler := exec.Command("bash", "-c", command)
	handler.Stdout = &stdout
	handler.Stderr = &stderr
	goRunCmd := func() <-chan struct{} {
		done := make(chan struct{})
		go func() {
			defer close(done)
			handler.Run()
		}()
		return done
	}
	select {
	case <-goRunCmd():
		return stdout.String(), nil
	case <-time.After(timeout):
		handler.Process.Kill()
		handler.Wait()
		return "", errors.New("timeout")
	}
}
