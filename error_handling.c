#include "monty.h"

/**
 * error - Outputs specific error messages based on error codes.
 * @error_code: An integer representing the error code. Possible values:
 *   (1) - Indicates no file provided or more than one file to the program.
 *   (2) - Signifies that the provided file cannot be opened or read.
 *   (3) - Indicates that the provided file contains an invalid instruction.
 *   (4) - Denotes a failure to allocate memory (malloc failed).
 *   (5) - Occurs when the push instruction is given a non-integer parameter.
 *   (6) - Occurs when attempting to execute pint on an empty stack.
 *   (7) - Occurs when attempting to execute pop on an empty stack.
 *   (8) - Indicates that the stack is too short for the intended operation.
 */
void error(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l_num = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * handle_error - Handles errors and prints corresponding error messages.
 * @error_code: The error codes and their meanings are as follows:
 *   (6) => Error: Can't pint, stack is empty.
 *   (7)  => Error: Can't pop, stack is empty.
 *   (8)  => Error: Can't perform the operation, stack is too short.
 *   (9) => Error: Division by zero.
 */
void handle_error(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			l_num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_error - handles errors.
 * @error_code: The error codes are the following:
 * (10) ~> Error: Can't pchar, value is out of ASCII bounds.
 * (11) ~> Error: Can't pchar, stack is empty
 */
void string_error(int error_code, ...)
{
	va_list ag;
	int l_num;

	va_start(ag, error_code);
	l_num = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
