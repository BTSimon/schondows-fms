#include <stdio.h>
#include <string.h>

#define VALID_COMMANDS {"pwd", "ls", "cd", "cls"}
#define VALID_COMMANDS_NUM 4

const char *valid_commands[] = VALID_COMMANDS;

void tokenize(char *input, int inputSize, char output[][32]) {
    int tokenStart = 0;
    int tokenNum = 0;

    for(int i = 0; i<inputSize; i++) {
        if (input[i] == ' ') {

            int charCount = 0;

            for (int j = tokenStart; j<i; j++) {
                output[tokenNum][charCount] = input[j];
                charCount++;
            }

            output[tokenNum][charCount] = '\0';
            tokenStart = i+1;
            tokenNum++;
        } 
    }

    if (tokenStart < inputSize) {
        int charCount = 0;

        for (int j = tokenStart; j < inputSize; j++) {
            output[tokenNum][charCount] = input[j];
            charCount++;
        }

        output[tokenNum][charCount] = '\0';
        tokenNum++;
    }

} 

void read(char tokens[][32]) {
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