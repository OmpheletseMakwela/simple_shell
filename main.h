#ifndef MAIN_H
#define MAIN_H

#define MAX_INPUT_SIZE 2000
extern char **environ;
void exec_command(char *command);
void env(void);
int _strcmp(const char *s1, const char *s2);
void array(char *str, char **args);
int _unsetenv(char *variable);
int _setenv(char *variable, char *value);
char *_strconcat(char *s1, char *s2);

#endif
