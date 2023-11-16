#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * _strconcat - concantenates two strings.
 * @s1: first string
 * @s2: second string
 * Return: pointer to concantenated string.
 */
char *_strconcat(char *s1, char *s2)
{
	size_t len1 = strlen(s1);
	size_t len2 = strlen(s2);
	char *result = (char *)malloc(len1 + len2 + 1);

	if (result == NULL)
	{
		perror("str_concat: malloc");
		exit(EXIT_FAILURE);
	}
	strcpy(result, s1);
	strcat(result, s2);
	return (result);
}
/**
 * _setenv - adds a new environment variable and value.
 * @variable: new variable
 * @value: the value
 * Return: 0 (success), -1(fail)
 */
int _setenv(char *variable, char *value)
{
	char *env, *new_var, *new_var_val;
	size_t len, len_variable = strlen(variable);
	int count, i;

	if (variable == NULL || value == NULL)
	{
		perror("setenv: ");
		return (-1);
	}
	new_var = _strconcat(variable, "=");
	new_var_val = _strconcat(new_var, value);
	for (i = 0; environ[i] != NULL; ++i)
	{
		env = environ[i];
		len = strcspn(env, "=");
		if (strncmp(env, variable, len) == 0 && len == len_variable)
		{
			free(environ[i]);
			environ[i] = new_var_val;
			free(new_var);
			return (0);
		}
	}
	for (count = 0; environ[count] != NULL; ++count)
		;
	environ[count] = new_var_val;
	environ[count + 1] = NULL;
	free(new_var);
	return (0);
}
/**
 * _unsetenv - removes an environment variable.
 * @variable: variable to remove.
 * Return: 0 (success), (-1) fail.
 */
int _unsetenv(char *variable)
{
	char *env;
	size_t len, len_variable = strlen(variable);
	int i;

	if (variable == NULL)
	{
		perror("setenv: ");
		return (-1);
	}
	for (i = 0; environ[i] != NULL; ++i)
	{
		env = environ[i];
		len = strcspn(env, "=");
		if (strncmp(env, variable, len) == 0 && len == len_variable)
		{
			free(environ[i]);
			environ[i] = NULL;
			return (0);
		}
	}
	perror("unsetenv: ");
	return (0);
}
