/*
 * Author: Deantosh Daiddoh & Lucky Archibong.
 * File: main.c
 */

#include "monty.h"
global_t monty_vars;

/**
 * init_global_vars - initializes the global variables.
 * @stream: a pointer to monty file.
 * Return: void.
 */
void init_global_vars(FILE *stream)
{
	monty_vars.head = NULL;
	monty_vars.stream = stream;
	monty_vars.current_line = 1;
	monty_vars.opcode_value = NULL;
}

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
	char *line = NULL, *line_data[2] = {NULL, NULL};
	FILE *stream;
	size_t len = 0;
	ssize_t nread;

	/*check program usage / if file is present*/
	stream = check_usage_file(argc, argv);

	/*initialize global monty variables*/
	init_global_vars(stream);

	/*read file*/
	while ((nread = getline(&line, &len, stream)) != -1)
	{
		line_data[0] = strtok(line, " \t\n"); /*name of opcode*/
		f = select_opcode_func(line_data[0]);
		if (f == NULL)
		{
			fprintf(stderr, "L%u: ", monty_vars.current_line);
			fprintf(stderr, "unknown instruction %s\n", line_data[0]);
			exit(EXIT_FAILURE);
		}
		/*execute instructions*/
		monty_vars.opcode_value = strtok(NULL, " \t\n");
		f(&monty_vars.head, monty_vars.current_line);
		monty_vars.current_line++;
	}
	free(line);
	/*close the file*/
	fclose(stream);
	return (0);
}


/**
 * check_usage_file - checks for program usage and if monty file
 *			is provided.
 * @argc: the number of args.
 * @argv: the list of args.
 *
 * Return: a pointer to the opened file.
 */
FILE *check_usage_file(int argc, char **argv)
{
	FILE *stream;
	char *file_name;

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
	return (stream);
}
