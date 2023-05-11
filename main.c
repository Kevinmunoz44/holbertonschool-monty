#include "monty.h"

/**
 * main - main program
 *
 * @argc: number of arguments
 * @argv: command line arguments
 *
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    if (monty_interpreter(argv[1]) == -1)
        exit(EXIT_FAILURE);
    exit(EXIT_SUCCESS);
}