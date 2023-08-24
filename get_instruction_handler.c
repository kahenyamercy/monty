#include "monty.h"

/**
 * get_instruction_handler - selects the prefered function to be
 *	called based on the the opcode found
 * @opcode: pointer to opcode string whose associated function
 * is to returned
 *
 * Return: returns a function pointer associated with the opcode.
 */


void (*get_instruction_handler(char *opcode))(stack_t **, unsigned int)
{
	instruction_t instructionList[] = {
		{"push", &push},
		{NULL, NULL}
	};
	int i = 0;

	while (instructionList[i].opcode != NULL)
	{
		if (strcmp(instructionList.opcode, opcode) == 0)
			return (instructionList[i].f);
		i++;
	}
	handle_invalid_opcode(opcode);
}
