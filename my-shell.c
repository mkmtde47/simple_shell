#include "main.h"

/**
 * shell - loop of shell
 * Return: void
 */

int shell(void)
{
	char *args;
	char **tokens;

	while (1)
	{
		args = read_input();
		tokens = process_args(args);
		execute(tokens);
	}
	return (0);
}
