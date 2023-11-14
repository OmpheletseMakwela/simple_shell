#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "main.h"

/**
 * main - main function
 * Return: 0 on success
 */

int main(void)
{
	char input[MAX_INPUT_SIZE];
	char *ptr = input;
	size_t n = 1000;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			printf("#cisfun$ ");
			if (getline(&ptr, &n, stdin) == -1)
			{
				perror("getline:");
			}
			strtok(input, "\n");
			exec_command(input);
		}
		return (0);
	}
	else
	{
		if (getline(&ptr, &n, stdin) == -1)
		{
			perror("getline:");
		}
		strtok(input, "\n");
		exec_command(input);
		return (0);
	}
}
