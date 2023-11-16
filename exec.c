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
    int execute_command;
    int logical_operator;
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

        execute_command = 1;
        logical_operator = -1;

        if (strstr(commands[i], "&&") != NULL) {
            execute_command = 0;
            logical_operator = 0;
        } else if (strstr(commands[i], "||") != NULL) {
            execute_command = 0;
            logical_operator = 1;
        }

        if (logical_operator >= 0) {
            char *logical_tokens[MAX_INPUT_SIZE];
            int num_logical_tokens = 0;
            char *logical_token = strtok(commands[i], " ");
            
            while (logical_token != NULL && num_logical_tokens < MAX_INPUT_SIZE - 1) {
                logical_tokens[num_logical_tokens++] = logical_token;
                logical_token = strtok(NULL, " ");
            }
            logical_tokens[num_logical_tokens] = NULL;

            if (logical_operator == 0) {
    	     if (execute_command && execvp(logical_tokens[0], logical_tokens) == -1) {
                    perror("executing error");
                    exit(1);
                }
            } else if (logical_operator == 1) {
                if (!execute_command && execvp(logical_tokens[0], logical_tokens) == -1) {
                    perror("executing error");
                    exit(1);
                }
            }
        } else {
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
                } else if (logical_operator == 1) {
                    execute_command = 0;
                }
            }
        }
    }
}
