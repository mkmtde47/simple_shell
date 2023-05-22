#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
extern char **environ;
int shell();
char *read_input(void);
char **process_args(char *args);
int execute(char **tokens);
char *findpath(char *command);
#endif
