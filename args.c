#include "monty.h"

/**
 * free_args - frees structure args_struct
 *
 * Return: Nothing.
 */

void free_args()
{
	free(args);
	args = NULL;
}
