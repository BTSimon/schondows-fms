#include <stdio.h>
#include <string.h>

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

    if (tokenNum == 0) {
        for (int i = 0; input[i] != '\0'; i++) {
            output[0][i] = input[i];
        }
    }

} 

void read(char tokens[][32]) {
    char input[128];
    fgets(input, sizeof(input), stdin);

    int inputsize = strlen(input);
    tokenize(input, inputsize, tokens);

}