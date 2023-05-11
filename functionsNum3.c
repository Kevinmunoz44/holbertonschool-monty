#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 *
 * @stack: double pointer to the beginning of the stack
 * @line_number: current line number in the file
 */
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *t;

    /* validate that there are at least two elements in the stack */
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    t = (*stack)->next;
    (*stack)->next = t->next;
    if (t->next != NULL)
        t->next->prev = *stack;
    t->next = *stack;
    t->prev = NULL;
    (*stack)->prev = t;
    *stack = t;
}

/**
 * add - adds the top two elements of the stack
 *
 * @stack: double pointer to the beginning of the stack
 * @line_number: current line number in the file
 */
void add(stack_t **stack, unsigned int line_number)
{
    /* validate that there are at least two elements in the stack */
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    pop(stack, line_number);
}

/**
 * nop - does nothing
 *
 * @stack: double pointer to the beginning of the stack
 * @line_number: current line number in the file
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}