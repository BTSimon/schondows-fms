#include <stdio.h>
#include <string.h>

#include "../include/commands.h"
#include "../include/ui.h"
#include "../include/main.h"

const char *valid_commands[] = VALID_COMMANDS;

void tokenize(char *input, int inputSize, parseLine *output) {
    int tokenStart = 0;
    int tokenNum = 0;

    for (int i = 0; i <= inputSize; i++) {
        if (input[i] == ' ' || input[i] == '\0') {
            int length = i - tokenStart;

            if (length > 0) {
                if (tokenNum == 0) {
                    strncpy(output->command, input + tokenStart, length);
                    output->command[length] = '\0';
                } else {
                    strncpy(output->params[tokenNum - 1], input + tokenStart, length);
                    output->params[tokenNum - 1][length] = '\0';
                }

                tokenNum++;
            }

            tokenStart = i + 1;
        }
    }

    output->paramCount = tokenNum > 0 ? tokenNum - 1 : 0;
}

void read_input(parseLine *tokens) {
    char input[128];
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';
    int inputSize = strlen(input);
    tokenize(input, inputSize, tokens);
}

int verify_commands(char *command) {
    for (int i = 0; i<VALID_COMMANDS_NUM; i++) {
        if (strcmp(valid_commands[i], command) == 0) {
            return 1;
        }
    }
    return 0;
}

void process_commands(parseLine *tokens) {
    if (strcmp(tokens->command, "cls") == 0) {
        if (tokens->paramCount > 0) {
            error("Too many parameters!\n"); 
        }
        clear();
    } 
    else if (strcmp(tokens->command, "shutdown") == 0) {
        if (tokens->paramCount > 0) {
            error("Too many parameters!\n"); 
        }
        display_end_graceful(0);
        running = false;
    }
}
