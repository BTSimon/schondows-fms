#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../include/commands.h"
#include "../include/ui.h"
#include "../include/main.h"

bool running = true;

int main(void) {
    display_startup();
    
    while (running) {
        // Függvény a parancssor kinézetének kezeléséhez
        // Függvény a bemenet kezeléséhez
        next_command();
        parseLine tokens;
        read_input(&tokens);
        if (!verify_commands(tokens.command)) {
            printf("Invalid command\n");
            continue;
        }
        process_commands(&tokens);
        
        
    }

    return 0;
}