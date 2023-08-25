#include "monty.h"
int main(int ac, char **argv);
args_struct *args = NULL; /* defines global variable */
/**
 * main - main entry point of the program
 * @ac: count of arguments passed to the program
 * @argv: pointer to an array of arguments passed to the program
 *
 * Return: Always 0.
 */

int main(int ac, char **argv)
{
	size_t n = 0;

	validate_argv(ac);
	init_args();
	get_file_stream(argv[1]);

	while (getline(&args->lineptr, &n, args->file_stream) != -1)
	{
		args->current_line += 1;
		tokenize_line();
		execute_instruction();
		free_args_token();
	}
	close_file_stream();
	free_args();
	return (0);
}
