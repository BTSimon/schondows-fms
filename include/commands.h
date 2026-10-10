#ifndef COMMANDS_H
#define COMMANDS_H

void tokenize(char *input, int inputSize, char output[][32], int paramsSize);
void read(char tokens[][32]);
int verify_commands(char *command);

#endif