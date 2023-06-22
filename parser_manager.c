#include "monty.h"

/**
 * is_number - checks if a string is a valid integer
 * @s: the string to check
 *
 * Return: 1 if s is a valid integer, 0 otherwise
 */
int is_number(char *s)
{
	int i = 0;

	if (s[0] == '-' || s[0] == '+')
		i++;

	for (; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * parse_line - parses a line of Monty bytecode
 * @line: the line to parse
 * @stack: pointer to the top of the stack
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
*/
int parse_line(char *line, stack_t **stack)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	char *opcode, *arg;
	unsigned int n, i;

	opcode = strtok(line, " \n\t");
	if (!opcode || opcode[0] == '#')
		return (0);

	arg = strtok(NULL, " \n\t");
	if (arg && is_number(arg))
		n = atoi(arg);
	else
		n = 0;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, n);
			return (0);
		}
	}

	return (1);
}
