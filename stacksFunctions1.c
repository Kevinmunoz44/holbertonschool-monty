#include "monty.h"

/**
 * push - Agrega un nodo al inicio de la pila
 * @head: Doble puntero al primer nodo de la pila
 * @n: Valor del nodo
 *
 * Return: El nuevo nodo agregado a la pila
 */
stack_t *push(stack_t **head, int n)
{
    stack_t *new_node;

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
        return (NULL);

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *head;
    if (*head)
        (*head)->prev = new_node;
    *head = new_node;

    return (new_node);
}