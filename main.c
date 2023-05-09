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
    char *token;
    bool unknown = false;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    stack_t *stack = NULL;
    unsigned int line_number = 1;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        if (line[0] == '\n') /* Verifica si la línea está en blanco*/
        {
            line_number++;
            continue;
        }

        token = strtok(line, " \n\t");
        if (token != NULL && strcmp(token, "push") == 0)
        {
            token = strtok(NULL, " \n\t");
            if (token != NULL && ((isdigit(*token) || (*token == '-' && isdigit(*(token + 1)))) && strspn(token, "-0123456789") == strlen(token)))
                push(&stack, atoi(token));
            else
            {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                free(line);
                fclose(file);
                free_stack(&stack);
                exit(EXIT_FAILURE);
            }
        }
        else if (token != NULL && strcmp(token, "pall") == 0)
            pall(stack);
        else
        {
            unknown = true;
        }
        line_number++;
    }

    free(line);
    fclose(file);
    free_stack(&stack);

    if (unknown)
    {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}