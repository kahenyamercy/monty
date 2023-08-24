#include "monty.h"

/**
 * execute_instruction - helper function to get instruction and execute it
 *
 * Description: the get_instruction_handler returns a pointer to a
 * that executes the instruction
 *
 * Return: Nothing.
 */

void execute_instruction(void)
{
	void (*handle_instruction)(stack_t **, unsigned int);

	handle_instruction = get_instruction_handler(args->tokens[0]);
	handle_instruction(&(args->stack), args->current_line);
}
