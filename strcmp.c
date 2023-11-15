#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * _strcmp - string compare function
 * @s1: first pointer to a character
 * @s2: second pointer to a character
 * Return: s1-s2
 */

int _strcmp(const char *s1, const char *s2)
{
	if (s1 == NULL || s2 == NULL)
	{
		if (s1 == NULL && s2 == NULL)
		{
			return (0);
		}
		else if (s1 == NULL)
		{
			return (-1);
		}
		else
		{
			return (1);
		}
	}
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
