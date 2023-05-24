#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;
int shell();
char *read_input(void);
char **process_args(char *args);
int execute(char **tokens);
void execute_cmd(char **argv);
char *get_path(char *command);
#endif
