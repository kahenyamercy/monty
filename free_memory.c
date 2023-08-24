#include "monty.h"

/**
 * free_args_token - frees memory allocated to store work tokens
 *
 * Return: Nothing.
 */

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
	free_stack();
	free(args);
	args = NULL;
}
/**
 * free_stack - frees the stack
 * Return: none
 */
void free_stack(void)
{
	if (args->stack == NULL)
		return;

	while (args->stack != NULL)
	{
		printf("hello\n");
		free(args->stack);
		args->stack = (args->stack)->next;
	}
	args->stack = NULL;
}
