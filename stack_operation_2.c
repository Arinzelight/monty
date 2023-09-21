#include "monty.h"

/**
 * mul - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: An integer representing the line number of the opcode.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int mul;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		handle_error(8, line_number, "mul");

	(*stack) = (*stack)->next;
	mul = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = mul;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * modulus - Computes the remainder of the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: An integer representing the line number of the opcode.
 */
void modulus(stack_t **stack, unsigned int line_number)
{
	int mod;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		handle_error(8, line_number, "mod");


	if ((*stack)->n == 0)
		handle_error(9, line_number);
	(*stack) = (*stack)->next;
	mod = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = mod;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
