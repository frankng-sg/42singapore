package cmd

import (
	"bufio"
	"os/exec"
)

type CommandHandler struct {
	Cmd     string
	handler *exec.Cmd
	stdout  *bufio.Scanner
}

func NewCommandHandler(command string) *CommandHandler {
	return &CommandHandler{Cmd: command}
}

func (c *CommandHandler) Run() error {
	c.handler = exec.Command("bash", "-c", c.Cmd)
	stdout, err := c.handler.StdoutPipe()
	if err != nil {
		return err
	}
	c.stdout = bufio.NewScanner(stdout)
	return c.handler.Start()
}

func (c *CommandHandler) EOF() bool {
	return !c.stdout.Scan()
}

func (c *CommandHandler) Read() string {
	return c.stdout.Text()
}

func (c *CommandHandler) Kill() error {
	return c.handler.Process.Kill()
}
