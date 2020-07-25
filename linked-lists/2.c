/**
 * 2.c
 * Linked Lists
 * https://github.com/ashenm/dsa
 *
 * Demonstrates linked list itteration
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

    node *x = malloc(sizeof(node));
    node *y = malloc(sizeof(node));

    if (x == NULL || y == NULL)
    {
        return 1;
    }

    x -> value = 25;
    x -> next = y;

    y -> value = 50;
    y -> next = NULL;

    for (node *n = x; n != NULL; n = n -> next)
    {
        printf("%i\n", n -> value);
    }

    free(x);
    free(y);

}

// vim: set expandtab shiftwidth=4:
