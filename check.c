#include "monty.h"
/**
 * is_number - Check if a string represents a valid number.
 * @str: The input string to check.
 *
 * Return: 1 if the string is a valid number, 0 otherwise.
 */
int is_number(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}

	return (1);
}

