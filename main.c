#include "monty.h"

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
	int i = 0;
	void (*handle_instruction)(stack_t **, unsigned int);
	stack_t **stack = NULL;

	validate_argv(ac);
	init_args();
	get_file_stream(argv[1]);

	while (getline(&args->lineptr, &n, args->file_stream) != -1)
	{
		args->current_line += 1;
		printf("Line %d: %s", args->current_line, args->lineptr);
		tokenize_line();
		while (args->tokens[i] != NULL)
		{
			printf("Token [%d]: %s\n", i, args->tokens[i]);
			i++;
		}
		i = 0;
		handle_instruction = get_instruction_handler(args->tokens[0]);
		handle_instruction(stack, args->current_line);
		free_args_token();
	}
	close_file_stream();
	free_args();
	return (0);
}
