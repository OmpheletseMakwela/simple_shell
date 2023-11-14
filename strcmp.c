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
 * Return: result
 */

int _strcmp(char *s1, char *s2)
{
	int result = 0;
	char *ptr1 = s1;
	char *ptr2 = s2;

	while (*ptr1 != '\0')
	{
		if (*ptr1 != *ptr2)
		{
			int i = (int) *ptr1;
			int i2 = (int)*ptr2;

			result = i - i2;
			break;
		}
		ptr1++;
		ptr2++;
	}
	return (result);
}
