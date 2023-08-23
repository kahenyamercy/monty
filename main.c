#include "monty.h"


void print_err(char *msg)
{
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}


int main(int ac, char **argv)
{
	if (ac != 2)
		print_err("USAGE: monty file");
	printf("File: %s\n", argv[1]);
	return (0);
}
