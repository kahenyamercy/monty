#include "monty.h"

/**
 * handle_stream_failed - handles case when file opening failed
 * @filename: pointer to the file that had an error opening stream
 *
 * Description: the function prints out error to the stderr,
 * frees any memory that was allocated and exit with EXIT_FAILURE.
 *
 * Return: Nothing.
 */

void handle_stream_failed(char *filename)
{
	dprinf(stderr, "Error: Can't open file %s\n", filename);
	free_args();
	exit(EXIT_FAILURE);
}

/**
 * get_file_stream - opens a file stream
 * @filename: pointer to the file being opened
 *
 * Return: Nothing.
 */

void get_file_stream(char *filename)
{
	FILE *stream;

	stream = fopen(filename, 'r');
	if (stream == NULL)
		handle_stream_failed(filename);
	args->file = stream;
}
