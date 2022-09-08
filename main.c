#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * init_shell - starts the shell
 */
void init_shell(void)
{
	printf("#cisfun$ ");
}

/**
 * stripnewline - removes new line character
 * @cmd: char pointer
 * @tchar: long int
 * Return: char pointer
 */

char *stripnewline(char *cmd, size_t tchar)
{
	 int i = 0;
	 char *command = malloc(sizeof(char) * tchar);
	while (*cmd != '\n')
	{
		command[i] = *cmd;
		i++;
		cmd++;
	}
	return (command);
}


/**
 * execprogram - execute programs given path
 * @commandarg: command to run with args
 * @environ: enviromental path
 */

void execprogram(char **commandarg, char **environ)
{
	if (execve(commandarg[0], commandarg, environ) == -1)
	{
		printf("%s: No such file or directory\n", commandarg[0]);
		init_shell();
	}
}

/**
 * main - start of the program
 * @argc: count arguments
 * @argv: arguments
 * Return: int
 */
int main(int argc, char *argv[])
{
	 char *commangarg[10];
	 pid_t pid;
	 size_t read;
	 size_t size = 100;
	 char *command = malloc(sizeof(char) * 100);
	 char *environ[10] = { NULL };
	init_shell();
	if (argc == 1)
	{
		while (1)
		{
			read = getline(&command, &size, stdin);
			command = stripEOF(command, read);
			pid = fork();
			commangarg[0] = command;
			commangarg[1] = NULL;
			if (pid == 0)
			{
				execprogram(commangarg, environ);
			}
			else
			{
				wait(NULL);
				init_shell();
			}
		}
	}
	else
	{
		commangarg[0] = argv[1];
		commangarg[1] = "-l";
		commangarg[2] = ".";
		if (execve(commangarg[0], commangarg, environ) == -1)
			printf("%s: No such file or directory\n", commangarg[0]);
	}
	return (0);
}
