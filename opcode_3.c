#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * mod_op - Computes the rest of the division of the second top element
 *          of the stack by the top element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
	int divisor;
	stack_t *top = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	divisor = (*stack)->n;
	if (divisor == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	*stack = (*stack)->next;
	(*stack)->n %= divisor;

	free(top);

	(void)line_number;
}

/**
 * pchar_op - Prints the char at the top of the stack as an ASCII character.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void pchar_op(stack_t **stack, unsigned int line_number)
{
	int ascii_value;
	stack_t *top = NULL;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	ascii_value = (*stack)->n;

	if (ascii_value < 0 || ascii_value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", ascii_value);

	top = *stack;
	*stack = (*stack)->next;
	free(top);
}

/**
 * pstr_op - Prints the string starting at the top of the stack as ASCII characters.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void pstr_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL && current->n != 0 && 
		current->n >= 0 && current->n <= 127)
	{
		if (current->n == 10)
			break;

		printf("%c", current->n);

		current = current->next;
	}

	printf("\n");
}

/**
 * rotl_op - Rotates the stack to the top.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void rotl_op(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		stack_t *last = *stack;
		stack_t *second_last = NULL;

		while (last->next != NULL)
		{
			second_last = last;
			last = last->next;
		}

		second_last->next = NULL;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
	}
}

/**
 * rotr_op - Rotates the stack to the bottom.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 */
void rotr_op(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		stack_t *last = *stack;
		stack_t *second_last = NULL;

		while (last->next != NULL)
		{
			second_last = last;
			last = last->next;
		}

		second_last->next = NULL;
		last->next = *stack;
		last->prev = NULL;
		(*stack)->prev = last;
		*stack = last;
	}
}

