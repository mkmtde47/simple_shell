#include "main.h"


char *findpath(char *command)
{
	char **env = environ;
	char *path;
	char *path2;
	char *cwd;
	while (*env != NULL)
	{
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
					return (path2);
				}
			}
		}
		printf("%s\n", path2);
		env++;
	}
	return (NULL);
}
