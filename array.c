#include <stdlib.h>
#include<sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "main.h"
/**
 * array - convert string to array
 * @str: string.
 * @args: array.
 * Return: nothing.
 */
void array(char *str, char **args)
{
	char *token = strtok(str, " \n\t");

	while (token != NULL)
	{
		*args = token;
		token = strtok(NULL, " \n\t");
		args++;
	}
	*args = NULL;
}
