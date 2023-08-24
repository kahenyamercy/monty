#include "monty.h"

/**
 * tokenize_line - tokenizes file line read
 *
 * Description: the function accesses the lineptr read by getline,
 * tokenizes it to word tokens and adds the to an array
 *
 * Return: Nothing.
 */


void tokenize_line(void)
{
	char *lineptr_cpy = NULL, *delims = " \n", *token = NULL;
	int i = 0;

	lineptr_cpy = malloc(sizeof(char) * (strlen(args->lineptr) + 1));
	if (lineptr_cpy == NULL)
		handle_malloc_err();
	strcpy(lineptr_cpy, args->lineptr);

	args->token_count = 0;
	token = strtok(lineptr_cpy, delims);
	while (token != NULL)
	{
		args->token_count += 1;
		token = strtok(NULL, delims);
	}

	args->tokens = malloc(sizeof(char *) * (args->token_count + 1));
	if (args->tokens == NULL)
	{
		free(lineptr_cpy);
		handle_malloc_err();
	}

	strcpy(lineptr_cpy, args->lineptr);
	token = strtok(lineptr_cpy, delims);
	while (token != NULL)
	{
		args->tokens[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (args->tokens[i] == NULL)
		{
			free(lineptr_cpy);
			handle_malloc_err();
		}
		strcpy(args->tokens[i], token);
		token = strtok(NULL, delims);
		i++;
	}
	args->tokens[i] = NULL;
	free(lineptr_cpy);
}
