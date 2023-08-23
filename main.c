#include "monty.h"

args = NULL; /* defines global variable */


/**
 * print_err - prints error message
 * @msg: pointer to the error string
 *
 * Return: Nothing.
 */

void exit_with_err(char *msg)
{
	dprintf(stderr, "%s\n", msg);
	exit(EXIT_FAILURE);
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

void init_args()
{
	args = malloc(sizeof(args_struct));
	if (args == NULL)
		exit_with_err("Error: malloc failed");
	args->file_stream = NULL;
}

int main(int ac, char **argv);
{
	validate_argv(ac);
	init_args();
	get_file_stream(argv[1]);
	printf("File: %s\n", argv[1]);
	return (0);
}
