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
    int i;
    char *token;
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
        token = strtok(line, " \n\t");
        if (token != NULL && strcmp(token, "push") == 0)
        {
            if (token == NULL)
            {
                fprintf(stderr, "L%u: usage: push integer\n", line_number);
                free(line);
                fclose(file);
                free_stack(&stack);
                exit(EXIT_FAILURE);
            }
            for (i = 0; token[i] != '\0'; i++)
            {
                if (i == 0 && token[i] == '-')
                    continue;
                if (isdigit(token[i]) == 0)
                {
                    fprintf(stderr, "L%u: usage: push integer\n", line_number);
                    free(line);
                    fclose(file);
                    free_stack(&stack);
                    exit(EXIT_FAILURE);
                }
            }
            push(&stack, atoi(token));
        }
    }

    free(line);
    fclose(file);
    free_stack(&stack);

    return EXIT_SUCCESS;
}