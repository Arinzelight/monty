#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (monty_state.arg)
	{
		if (monty_state.arg[0] == '-')
			j++;
		for (; monty_state.arg[j] != '\0'; j++)
		{
			if (monty_state.arg[j] > 57 || monty_state.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(monty_state.file);
			free(monty_state.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(monty_state.file);
		free(monty_state.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(monty_state.arg);
	if (monty_state.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
