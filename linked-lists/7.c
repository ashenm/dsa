/**
 * 7.c
 * Linked Lists
 * https://github.com/ashenm/dsa
 *
 * Implements Queue-like operations
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
node* queue (node **head, int value);

// removes the first insert
node* dequeue (node **head);

// computes the node count
int range (node *head);

int main (void)
{

    node *head = NULL;

    queue(&head, 25);
    queue(&head, 50);

    printf("%i\n", range(head));

    free(dequeue(&head));

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

node* queue (node **head, int value)
{

    node *elect = *head;
    node *inset = malloc(sizeof(node));

    if (inset == NULL)
    {
        return NULL;
    }

    inset -> value = value;
    inset -> next = NULL;

    if (elect == NULL)
    {
        return *head = inset;
    }

    while (elect -> next != NULL)
    {
        elect = elect -> next;
    }

    elect -> next = inset;

    return *head;

}

node* dequeue (node **head)
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
