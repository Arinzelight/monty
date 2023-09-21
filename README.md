0x19. C - Stacks, Queues - LIFO, FIFO
Monty - A Monty Bytecode Interpreter

Learning Objectives
At the end of this project, you will be able to explain the following concepts and topics without the need for external assistance:

General
Understanding of LIFO (Last-In, First-Out) and FIFO (First-In, First-Out) data structures.
Knowledge of what a stack is and when to use it in software development.
Understanding of what a queue is and when it is suitable for solving problems.
Familiarity with common implementations of stacks and queues.
Identification of the most common use cases for stacks and queues.
Knowledge of the proper use of global variables in C programming.

Requirements

General
The project must be edited using one of the following editors: vi, vim, emacs.
All source code files will be compiled on Ubuntu 20.04 LTS using the gcc compiler with the following flags: -Wall -Werror -Wextra -pedantic -std=c89.
All source code files should end with a newline character.
A README.md file must be present at the root of the project folder.
Code must adhere to the Betty coding style and will be checked using betty-style.pl and betty-doc.pl.
Only a maximum of one global variable is allowed.
Each source code file should contain no more than 5 functions.
The project is allowed to use the C standard library.
Prototypes of all functions should be included in the header file named monty.h.
The header files should be include guarded to prevent multiple inclusion.
The project tasks should be completed in the specified order.

Data Structures
the following data structures were utilized for this project:

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

Compilation & Output
To compile the project, use the following command:
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

