#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct args_struct - a structure to hold program arguments
 * @file_stream: file pointer to the currently opened file
 *
 * Description: holds all the arguments required
 * for the program
 */

typedef struct args_struct
{
	FILE *file_stream;
	char *lineptr;
	int current_line;
	char **tokens;
	int token_count;
} args_struct;


extern args_struct *args;

/* args.c */
void validate_argv(int ac);
void init_args(void);

/* file_stream.c */
void get_file_stream(char *filename);
void handle_stream_failed(char *filename);
void close_file_stream(void);

/* errors.c */
void exit_with_err(char *msg);
void handle_malloc_err(void);
void handle_invalid_opcode(char *opcode);

/* tokenize.c */
void tokenize_line(void);

/* free_memory.c */
void free_args(void);
void free_args_token(void);

/* get_instruction_handler.c */
void (*get_instruction_handler(char *opcode))(stack_t **, unsigned int);
#endif
