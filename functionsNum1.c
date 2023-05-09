#include "monty.h"

/**
 * push - Insert a new entry into the table with the given name and value
 *
 * @stack: The stack pointer
 * @n: Number of entries in the table
 *
 * Return: 0 if successful and -1 otherwise
 */
void push(stack_t **stack, int n)
{
    stack_t *new = malloc(sizeof(stack_t));
    if (new == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new->n = n;
    new->prev = NULL;
    new->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new;

    *stack = new;
}

/**
 * pall - print a list of entries in the table
 *
 * @stack: Pointer to the stack structures
 *
 * Returns: a list of entries in the table.
 */
void pall(stack_t *stack)
{
    while (stack != NULL)
    {
        printf("%d\n", stack->n);
        stack = stack->next;
    }
}


/**
 * free_stack - print a list of entries in the table
 *
 * @stack: Pointer to the stack structures
 *
 * Return: a list of entries in the table
 */
void free_stack(stack_t **stack)
{
    stack_t *temp;

    while (*stack != NULL)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}