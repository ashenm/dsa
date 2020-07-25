/**
 * 6.c
 * Linked Lists
 * https://github.com/ashenm/dsa
 *
 * Implements Stack-like operations
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

// conjoins a new node
node* push (node **head, int value);

// removes the last insert
node* pop (node **head);

// computes the node count
int range (node *head);

int main (void)
{

    node *head = NULL;

    push(&head, 25);
    push(&head, 50);

    printf("%i\n", range(head));

    free(pop(&head));

    node *elect = head;

    while (elect != NULL)
    {
        printf("%i\n", elect -> value);
        elect = elect -> next;
    }

    while (head != NULL)
    {
        elect = head;
        head = head -> next;
        free(elect);
    }

}

node* push (node **head, int value)
{

    node *elect = *head;
    node *inset = malloc(sizeof(node));

    if (inset == NULL)
    {
        return NULL;
    }

    inset -> value = value;
    inset -> next = elect;

    return *head = inset;

}

node* pop (node **head)
{

    node *elect = *head;

    if (elect == NULL)
    {
        return NULL;
    }

    *head = elect -> next;

    return elect;

}

int range (node *head)
{

    int n = 0;

    while (head != NULL)
    {
        head = head -> next;
        n += 1;
    }

    return n;

}

// vim: set expandtab shiftwidth=4:
