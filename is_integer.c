#include "monty.h"

/**
 * is_integer - Checks if a string is a valid integer.
 * @str: String to check.
 * Return: 1 if it's a valid integer, 0 otherwise.
 */
int is_integer(char *str)
{
    if (*str == '-')
        str++;

    while (*str)
    {
        if (!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}
