#include "monty.h"

void free_args_token(void)
{
	int i = 0;

	if (args->tokens == NULL)
		return;
	while (args->tokens[i])
	{
		free(args->tokens[i]);
		i++;
	}
	free(args->tokens);
	args->tokens = NULL;
}

/**
 * free_args - frees structure args_struct
 *
 * Return: Nothing.
 */

void free_args(void)
{
	free(args->lineptr);
	args->lineptr = NULL;
	free(args);
	args = NULL;
}

/**
 * validate_argv - checks for program usage format
 * @ac: count of the arguments passed to the main function
 *
 * Description: if the count is not equal to 2, then probably
 * usage is wrong.
 *
 * Return: Nothing.
 */

void validate_argv(int ac)
{
	if (ac == 2)
		return;
	exit_with_err("USAGE: monty file");
}

/**
 * init_args - allocates memory for global variable args
 *
 * Dsecription: the function allocates memory for the the structure args_struct
 * that is used to hold all arguments used in the program
 *
 * Return: Nothing.
 */

void init_args(void)
{
	args = malloc(sizeof(args_struct));
	if (args == NULL)
		exit_with_err("Error: malloc failed");
	args->file_stream = NULL;
	args->lineptr = NULL;
	args->tokens = NULL;
	args->current_line = 0;
	args->token_count = 0;
}

