/*
 * Author: Deantosh Daiddoh & Lucky Archibong
 * File: get_opcode_func.c
 */

#include "monty.h"

/**
 * select_opcode_func - selects the opcode that matches the name parsed.
 * @op: the opcode name.
 *
 * Return: the function to execute the opcode.
 */
void (*select_opcode_func(char *op))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	/*create a list of opcodes*/
	instruction_t opcode_list[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{NULL, NULL}
	};

	while (opcode_list[i].opcode)
	{
		if (strcmp(op, opcode_list[i].opcode) == 0)
			return (opcode_list[i].f);
		i++;
	}
	return (NULL);
}
