/**
 * 1.c
 * Linked Lists
 * https://github.com/ashenm/dsa
 *
 * Creates a single-node linked list
 *
 * Ashen Gunaratne
 * mail@ashenm.ml
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

int main (void)
{

    node *n = malloc(sizeof(node));

    if (n == NULL)
    {
        return 1;
    }

    n -> value = 25;
    n -> next = NULL;

    printf("%i\n", n -> value);

    free(n);

}

// vim: set expandtab shiftwidth=4:
