#include "monty.h"

args = NULL; /* defines global variable */

/**
 * main - main entry point of the program
 * @ac: count of arguments passed to the program
 * @argv: pointer to an array of arguments passed to the program
 *
 * Return: Always 0.
 */

int main(int ac, char **argv);
{
	validate_argv(ac);
	init_args();
	get_file_stream(argv[1]);
	printf("File: %s\n", argv[1]);
	return (0);
}
