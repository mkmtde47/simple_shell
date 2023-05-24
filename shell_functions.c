#include "main.h"
extern char **environ;

char *read_input()
{
	char *buffer = NULL;
	char c = '$';
	char s = ' ';
	ssize_t nread;
	size_t len = 0;
	int mode;

	mode = isatty(STDIN_FILENO);

	if (mode == 1)
	{
		write(1, &c, 1);
		write(1, &s, 1);
	}
	nread = getline(&buffer, &len, stdin);
	if (nread == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			exit(EXIT_FAILURE);
		}
	}
	return (buffer);
}

char **process_args(char *args)
{
	char *token;
	int i = 0;
	char **token_list;
	char *delim = " \n";

	/*WE CAN ASLO USE LINKED LISTS INSTEAD*/
	token_list = malloc(sizeof(char *) * 64);
	if (token_list == NULL)
		return (NULL);

	token = strtok(args, delim);
	while (token != NULL)
	{
		token_list[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	token_list[i] = NULL;
	i = 0;
	return (token_list);
}

int execute(char **tokens)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
		{
			perror("MKsh");
			printf("errno: %d\n", errno);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("MKsh");
	}
	else
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		}
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return 0;
}
