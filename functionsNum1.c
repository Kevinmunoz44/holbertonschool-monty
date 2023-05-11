#include "monty.h"

/**
 * push - Insert a new entry into the table with the given name and value
 * @stack: The stack pointer
 * @n: Number of entries in the table
 *
 * Return: 0;
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
 * @stack: Pointer to the stack structures
 *
 * Returns: 0;
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
 * pint - Prints the value at the top of the stack
 * @stack: The stack to operate on
 * Return: 0;
 */
void pint(stack_t *stack)
{
    unsigned int line_number = 1;
    if (stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", stack->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to the stack
 * @line_number: current line number
 * Return: 0;
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }
    temp = *stack;
    *stack = (*stack)->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;
    free(temp);
}

/**
 * free_stack - print a list of entries in the table
 * @stack: Pointer to the stack structures
 * Return: 0;
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
