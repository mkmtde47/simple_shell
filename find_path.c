#include "main.h"
extern char **environ;

char *findpath(char *command)
{
	printf("findpath: called with command: %s\n", command);
	char **env = environ;
	char *path;
	char *path2;
	char *cwd;
	        printf("findpath: before while loop\n");
		printf("findpath: environ = %p\n", (void *)environ);
	while (*env != NULL)
	{
		printf("findpath: env[%d] = %s\n", (int)(env - environ), *env);
		if (strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env + 5;
			while ((cwd = strtok(path, ":")) != NULL)
			{
				path2 = malloc(strlen(cwd) + strlen(command) + 1);
				strcpy(path2, cwd);
				strcat(path2, command);
				if (access(path2, F_OK) == 0)
				{
					printf("findpath: found path: %s\n", path2);
                      
					return (path2);
				}
			}
		}
		printf("%s\n", path2);
		env++;
	}
	 printf("findpath: after while loop\n");
	 printf("findpath: command not found: %s\n", command);
	return (NULL);
}
