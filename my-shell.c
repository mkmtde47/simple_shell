#include "main.h"

int shell(void)
{
	char *args;
	char **tokens;

	while (1)
	{
		args = read_input();
		tokens = process_args(args);
		/*execute(tokens);*/
		execute_cmd(tokens);
	}
	return (0);
}
