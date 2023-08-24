#include "monty.h"

/**
 * print_err - prints error message
 * @msg: pointer to the error string
 *
 * Return: Nothing.
 */

void exit_with_err(char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(EXIT_FAILURE);
}


/**
 * handle_malloc_err - prints malloc err message to the stderr
 *
 * Description: the function prints malloc err to the stderr, free memory
 * used and exit with EXIT_FAILURE
 *
 * Return: Nothing.
 */

void handle_malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed");
	free_args();
	exit(EXIT_FAILURE);
}

/**
 * handle_invalid_opcode - print invalid instruction opcode error
 * @opcode: pointer to the invalid instruction
 *
 * Return: Nothing.
 */

void handle_invalid_opcode(char *opcode)
{
	fprintf(stderr, "L%d: unknown instruction %s\n",
			args->current_line, opcode);
	close_file_stream();
	free_args_token();
	free_args();
	exit(EXIT_FAILURE);
}

