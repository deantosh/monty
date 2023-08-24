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
	void (*f)(stack_t **stack, unsigned int line_number);
	char *file_name, *line = NULL;
	char *line[2] = {NULL, NULL};
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
		line[0] = strtok(line, " \t\n"); /*name of opcode*/
		f = select_opcode_func(line[0]);
		if (f == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_num, line[0]);
			exit(EXIT_FAILURE);
		}
		printf("function obtained\n");
		return (0);
		line_number++;
	}
	free(line);
	/*close the file*/
	fclose(stream);
	return (0);
}
