#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../include/commands.h"
#include "../include/ui.h"

bool running = true;

int main(void) {
    display_startup();
    
    while (running) {
        // Függvény a parancssor kinézetének kezeléséhez
        // Függvény a bemenet kezeléséhez
        next_command();
        char tokens[10][32];
        read(tokens);
        
    }

    return 0;
}