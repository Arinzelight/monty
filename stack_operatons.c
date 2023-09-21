#include <stdlib.h>
#include "monty.h"

/**
 * push_stack - Pushes an element onto the stack.
 * @stack: Double pointer to the head of the stack.
 * @num: Integer to push.
 */
void push_stack(stack_t **stack, int num)
{
    stack_t *new_node = malloc(sizeof(stack_t));

    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = num;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;
}

/**
 * free_stack - Frees all elements of a stack.
 * @stack: Double pointer to the head of the stack.
 */
void free_stack(stack_t **stack)
{
    stack_t *current = *stack;
    stack_t *temp;

    while (current)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
}
