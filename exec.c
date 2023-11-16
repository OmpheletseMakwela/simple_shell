#include "main.h"
#include <stdlib.h>
#include<sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
/**
 * exec_command - executes a command from terminal.
 * @command: string.
 * Return: nothing.
 */
void exec_command(char *command)
{
	char *commands[MAX_INPUT_SIZE];
	int num_commands = 0;
	int i;
	char *token = strtok(command, ";");

	while (token != NULL && num_commands < MAX_INPUT_SIZE - 1)
	{
		commands[num_commands++] = token;
		token = strtok(NULL, ";");
	}
	commands[num_commands] = NULL;
	for (i = 0; i < num_commands; ++i)
	{
		char *args[MAX_INPUT_SIZE];
		pid_t pid;

		array(commands[i], args);
		if (_strcmp(args[0], "exit") == 0)
		{
			if (args[1] != NULL)
				exit(atoi(args[1]));
			exit(0);
		}
		pid = fork();
		if (pid == -1)
			perror("fork error");
		else if (pid == 0)
		{
			if (_strcmp(args[0], "env") == 0)
			{
				env();
				exit(0);
			}
			execvp(args[0], args);
			perror("executing error");
			exit(0);
		}
		else
			wait(NULL);
	}
}
