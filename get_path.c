#include "main.h"

char *get_path(char *command)
{
	char *path;
	char *path_dup;
	int len_com;
	int len_dir;
	char *tokens_p;
	char *path_f;
	struct stat buf;

	len_com = strlen(command);
	path = getenv("PATH");
	if (path)
	{
		path_dup = strdup(path);
		tokens_p = strtok(path_dup, ":");
		while (tokens_p != NULL)
		{
			len_dir = strlen(tokens_p);
			path_f = malloc(len_com + len_dir + 2);
			strcpy(path_f, tokens_p);
			strcat(path_f, "/");
			strcat(path_f, command);
			strcat(path_f, "\0");

			if (stat(path_f, &buf) == 0)
			{
				free(path_dup);
				return (path_f);
			}
			else
			{
				free(path_f);
				tokens_p = strtok(NULL, ":");
			}
		}
		free(path_dup);
		if (stat(command, &buf) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}
