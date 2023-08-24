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
		{"pall", &pall},
		{"pop", &pop},
		{"swap", &swap},
		{"add", &add},
		{"nop", &nop},
		{"sub", &sub},
		{"div", &div_op},
		{"mul", &mul_op},
		{"pint", &pint_op},
		{"mod", &mod_op},
		{"pchar", &pchar_op},
		{"pstr", &pstr_op},
		{"rotl", &rotl_op},
		{"rotr", &rotr_op},
		{NULL, NULL}
	};
	int i = 0;

	while (instructionList[i].opcode != NULL)
	{
		if (strcmp(instructionList[i].opcode, opcode) == 0)
			return (instructionList[i].f);
		i++;
	}
	handle_invalid_opcode(opcode);
	return (NULL); /* never reached */
}
