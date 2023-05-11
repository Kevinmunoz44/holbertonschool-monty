#include "monty.h"
/**
 * read_lines - reads each line of a file
 * @file: Pointer to the file to be read
 * @stack: Pointer to the stack structure
 *
 * Return: 0;
 */

int read_lines(FILE *file, stack_t **stack)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 1;
    while ((read = getline(&line, &len, file)) != -1)
    {
        /* Verificar si la línea está en blanco o solo tiene espacios*/
        if (strspn(line, " \t\n") == (size_t)read)
        {
            line_number++;
            continue;
        }
        char *token = strtok(line, " \n\t");
        if (token != NULL && strcmp(token, "push") == 0)
        {
            token = strtok(NULL, " \n\t");
            if (token != NULL &&
                ((isdigit(*token) || (*token == '-' && isdigit(*(token + 1)))) &&
                 strspn(token, "-0123456789") == strlen(token)))
                push(stack, atoi(token));
            else
            {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                free(line);
                return (-1);
            }
        }
        else if (token != NULL && strcmp(token, "pall") == 0)
            pall(*stack);
        else if (token != NULL && strcmp(token, "pint") == 0)
            pint(*stack);
        else if (token != NULL && strcmp(token, "pop") == 0)
            pop(stack, line_number);
        else if (token != NULL && strcmp(token, "swap") == 0)
            swap(stack, line_number);
        else if (token != NULL && strcmp(token, "add") == 0)
            add(stack, line_number);
        else if (token != NULL && strcmp(token, "nop") == 0)
            ; /* Do nothing */
        else
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
            free(line);
            return (-1);
        }
        line_number++;
    }
    free(line);
    return (0);
}

/**
 * monty_interpreter - Interpreter for themonty functions
 * @filename: The name of the file to be modified
 *
 * Return: 0;
 */

int monty_interpreter(char *filename)
{
    FILE *file;
    stack_t *stack = NULL;
    file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        return (-1);
    }
    if (read_lines(file, &stack) == -1)
    {
        fclose(file);
        free_stack(&stack);
        return (-1);
    }
    fclose(file);
    free_stack(&stack);
    return (0);
}