#include <string.h>
#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty file where the push was called.
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \n");
    int num;

    if (!arg || !is_integer(arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    num = atoi(arg);
    push_stack(stack, num);
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty file where pall was called.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
