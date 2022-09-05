#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * init_shell - starts the shell
 */
void init_shell(void)
{
	printf("#cisfun$ ");
}

/**
 * main - start of the program
 * Return: int
 */
int main(void)
{
	char *args[2];
	char *command = malloc(sizeof(char) * 100);
	extern char **environ;
	init_shell();
	while (1)
	{
		scanf("%s", command);
		args[0] = command;
		if (execve(args[0], args, environ) == -1)
			printf("%s: No such file or directory\n",arg);
		else
			printf(" ");

		init_shell();
	}
	return (0);
}
