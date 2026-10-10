#ifndef COMMANDS_H
#define COMMANDS_H

typedef struct parseLine {
    char command[32];
    char params[10][32];
    int paramCount;
} parseLine;

void tokenize(char *input, int inputSize, parseLine *output);
void read_input(parseLine *tokens);
int verify_commands(char *command);

#endif