#include "monty.h"

/**
 * main - Entry point for the Monty Bytecode Interpreter
 *
 * @argc: Number of arguments passed to the program
 * @argv: Array of strings containing the arguments
 *
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
 */
int main(int argc, char **argv)
{
    FILE *file;
    char *line = NULL, *token;
    size_t len = 0;
    ssize_t read;
    stack_t *stack = NULL;
    unsigned int line_number = 1;
    
    if (argc != 2)
        return (fprintf(stderr, "USAGE: monty file\n"), EXIT_FAILURE);
    file = fopen(argv[1], "r");
    if (file == NULL)
        return (fprintf(stderr, "Error: Can't open file %s\n", argv[1]), EXIT_FAILURE);
    while ((read = getline(&line, &len, file)) != -1)
    {
        if (strspn(line, " \t\n") == (size_t)read)
            continue;
        token = strtok(line, " \n\t");
        if (token != NULL && strcmp(token, "push") == 0)
        {
            token = strtok(NULL, " \n\t");
            if (token != NULL && ((isdigit(*token) ||
                                   (*token == '-' && isdigit(*(token + 1)))) &&
                                  strspn(token, "-0123456789") == strlen(token)))
                push(&stack, atoi(token));
            else
                return (fprintf(stderr, "L%u: usage: push integer\n", line_number),
                        free(line), fclose(file),
                        free_stack(&stack), EXIT_FAILURE);
        }
        else if (token != NULL && strcmp(token, "pall") == 0)
            pall(stack);
        else
            return (fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token),
                    free(line),
                    fclose(file), free_stack(&stack), EXIT_FAILURE);
        line_number++;
    }
    free(line), fclose(file), free_stack(&stack);
    return (EXIT_SUCCESS);
}