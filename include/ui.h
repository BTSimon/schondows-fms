#ifndef UI_H
#define UI_H

void clear(void);
void display_startup(void);
void next_command(void);
void display_end_graceful(int exit_code);
void display_end_terminated(int exit_code);

#endif