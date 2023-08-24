#include "monty.h"

void push(stack_t **stack, unsigned int current_line)
{
	if (stack == NULL)
		printf("stack (nill)\n");
	printf("Push executing at line %u\n", current_line);
}
