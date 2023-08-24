#include "monty.h"


void tokenize_line(void)
{
	char *lineptr_cpy;
	char *delims = " \n";
	char *token = NULL;
	int i = 0;

	lineptr_cpy = malloc(sizeof(char) * (strlen(args->lineptr) + 1));
	if (lineptr_cpy == NULL)
		handle_malloc_err();
	strcpy(lineptr_cpy, args->lineptr);

	args->token_count = 0;
	token = strtok(lineptr_cpy, delims);
	while(token != NULL)
	{
		args->token_count += 1;
		token = strtok(NULL, delims);
	}
	printf("Tokens count: %d\n", args->token_count);

	args->tokens = malloc(sizeof(char *) * (args->token_count + 1));
	if (args->tokens == NULL)
		handle_malloc_err();

	strcpy(lineptr_cpy, args->lineptr);
	token = strtok(lineptr_cpy, delims);
	while (token != NULL)
	{
		args->tokens[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (args->tokens[i] == NULL)
			handle_malloc_err();
		strcpy(args->tokens[i], token);
		printf("args->tokens[%d] = %s\n", i, args->tokens[i]);
		token = strtok(NULL, delims);
		i++;
	}
	args->tokens[i] = NULL;
	free(lineptr_cpy);
}
