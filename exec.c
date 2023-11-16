#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * exec_command - executes commands
 * @command: pointer to a cahracter
 */
void exec_command(char *command) {
    char *commands[MAX_INPUT_SIZE];
    int num_commands = 0;
    int i;
    int last_command;
    char *token = strtok(command, ";");

    while (token != NULL && num_commands < MAX_INPUT_SIZE - 1) {
        commands[num_commands++] = token;
        token = strtok(NULL, ";");
    }
    commands[num_commands] = NULL;

    for (i = 0; i < num_commands; ++i) {
        char *args[MAX_INPUT_SIZE];
        pid_t pid;

        array(commands[i], args);
        last_command = (i == num_commands - 1);

        if (_strcmp(args[0], "exit") == 0) {
            if (args[1] != NULL)
                exit(atoi(args[1]));
            exit(0);
        }

        pid = fork();
        if (pid == -1)
            perror("fork error");
        else if (pid == 0) {
            execvp(args[0], args);
            perror("executing error");
            exit(1);
        } else {
            int status;
            waitpid(pid, &status, 0);

            if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
                if (last_command) {
                    exit(WEXITSTATUS(status));
                }
            }
        }
    }
}

