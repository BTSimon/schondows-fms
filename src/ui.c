#include <stdio.h>
#include "../include/ui.h"

void clear(void) {
    printf("\033[H\033[J");
}

void display_startup(void) {
    clear();
    printf("Welcome to the first iteration of Schöndows FMS\n");
}

