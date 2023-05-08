#include "monty.h"

/**
 * 
 * 
 * 
 * Return: 0;
*/

#define SIZE_MAX_STACK 50

int pila[SIZE_MAX_STACK];
int p = -1;

void opc_push(char *n_str, int line)
{
    int exit_status = 0;
    if (p >= SIZE_MAX_STACK - 1)
    {
        printf("L%d:Stack full ", line);
        exit(exit_status);
    }
    else
    {
        char *end;
        int num = strtol(n_str, &end, 10);
        if (end != '\0')
        {
            printf("L%d:push integer ", line);
            exit(exit_status);
        }
        p++;
        pila[p] = num;
    }
}

void opc_pall(void)
{
    int j;
    for (j = p; j >= 0; j--)
    {
        printf("%d\n", pila[j]);
    }
}