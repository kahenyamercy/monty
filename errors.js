#include "main.h"

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

