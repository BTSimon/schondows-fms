#include <stdio.h>
#include <stdbool.h>

#include "../include/commands.h"
#include "../include/ui.h"

bool running = true;

int main(void) {
    display_startup();
    
    while (running) {
        // Függvény a parancssor kinézetének kezeléséhez
        // Függvény a bemenet kezeléséhez
        read();
    }

    return 0;
}