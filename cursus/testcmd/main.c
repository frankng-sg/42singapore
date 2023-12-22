#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv, char **envp) {
	static char *args[] = {"/usr/bin/grep", "hello world"};
	
	if (access(args[0], X_OK) >= 0)
		printf("Access to %s: OK\n", args[0]);
	else
		printf("Cannot access to %s...\n", args[0]);
	if (execve(args[0], args, envp) < 0)
		printf("Cannot execute command %s\n", args[0]);
	else
		printf("%s...OK\n", args[0]);
}
