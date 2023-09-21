#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



typedef void (*op_func)(stack_t **, unsigned int);

extern stack_t *head;


/*======= Stack function protypes ==========*/
stack_t *create_node(int n);
void free_nodes(void);
void pall_func(stack_t **, unsigned int);
void push_func(stack_t **, unsigned int);
void pop_func(stack_t **, unsigned int);
void pint_func(stack_t **, unsigned int);
void enqueue(stack_t **, unsigned int);

void call_fun(op_func, char *, char *, int, int);

void nop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);

/*=========== stack operation prototypes =============*/
void add(stack_t **, unsigned int);
void sub_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void modulus(stack_t **, unsigned int);

/*============ monty operation prototypes ============*/
void open_file(char *file_name);
int parse_line(char *buffer, int line_number, int format);
void read_file(FILE *);
int len_chars(FILE *);
void find_func(char *, char *, int, int);



/*========== String operation prototypes =============*/
void print_char(stack_t **, unsigned int);
void print_string(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/*=========== Error hanlding prototypes ==============*/

void error(int error_code, ...);
void handle_error(int error_code, ...);
void string_error(int error_code, ...);
void rotr(stack_t **, unsigned int);

#endif
