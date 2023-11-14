#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * env - handling the environment command
 */
void env(void)
{
	char *env = *environ;
	char **env_ptr = environ;

	while (env != NULL)
	{
		printf("%s\n", env);
		env = *(env_ptr)++;
	}
}
