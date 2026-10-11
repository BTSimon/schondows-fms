#include <stdio.h>
#include "../include/ui.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

void clear(void) {
    printf("\033[H\033[J");
}

void display_startup(void) {
    clear();
    printf("Welcome to the first iteration of Schöndows FMS\n");
}

void next_command(void) {
    printf("\n> ");
}

void display_end_graceful(int exit_code) {
    printf("Process shutdown with exit code " GREEN "%d\n" RESET, exit_code);
}

void display_end_terminated(int exit_code) {
    printf("Process shutdown with exit code " RED "%d\n" RESET, exit_code);
}