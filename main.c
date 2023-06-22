#include "monty.h"

#define MAX_LINE_LEN 1024

/**
 * main - Entry point for Monty bytecode interpreter
 * @argc: The number of arguments passed to the program
 * @argv: An array of strings containing the arguments passed to the program
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char buffer[MAX_LINE_LEN];
	stack_t *stack = NULL;
	int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, MAX_LINE_LEN, file) != NULL)
	{
		line_number++;
		if (parse_line(buffer, &stack, line_number) == -1)
		{
			free_stack(stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}

	free_stack(stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
