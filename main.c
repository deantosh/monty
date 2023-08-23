/*
 * Author: Deantosh Daiddoh & Lucky Archibong.
 * File: main.c
 */

#include "monty.h"

/**
 * main - the program entry point.
 * @argc: the number of arguments.
 * @argv: The list of arguments.
 *
 * Return: 0 (success) or 1 (fails).
 */
int main(int argc, char **argv)
{
	char *file_name, *line = NULL;
	FILE *stream;
	size_t len = 0;
	ssize_t nread;
	int line_number = 1;

	/*if user does not provide the file*/
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_name = argv[1];

	/*open file*/
	stream = fopen(file_name, "r");
	if (stream == NULL) /*can't open*/
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}
	/*read file*/
	while ((nread = getline(&line, &len, stream)) != -1)
	{
		printf("opcode: %s", line);
		printf("Line number: %d\n", line_number);
		line_number++;
	}
	free(line);
	/*close the file*/
	fclose(stream);
	return (0);
}
