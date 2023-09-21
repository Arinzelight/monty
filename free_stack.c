#include "monty.h"

/**
 * free_stack - frees a doubly linked list
 * @head: head of the stack
 */
void free_stack(stack_t *head)
{
    stack_t *current_node;

    while (head)
    {
        current_node = head->next;
        free(head);
        head = current_node;
    }
}
