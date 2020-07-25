/**
 * 8.c
 * Linked Lists
 * https://github.com/ashenm/dsa
 *
 * Implements a priority queue abstraction
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
    int priority;
    struct node *next;
} node;

// conjoins a new node
node* insert (node **head, int value, int priority);

// removes the highest priority node
node* serve (node **head);

// returns the highest priority node
node* peek (node **head);

// computes the node count
int range (node *head);

int main (void)
{

    node *head = NULL;

    insert(&head, 25, 20);
    insert(&head, 50, 30);
    insert(&head, 75, 25);

    printf("%i\n", range(head));
    printf("%i\n", peek(&head) -> value);

    free(serve(&head));

    node *elect = head;

    while (elect != NULL)
    {
        printf("%i\t%i\n", elect -> value, elect -> priority);
        elect = elect -> next;
    }

    while (head != NULL)
    {
        elect = head;
        head = head -> next;
        free(elect);
    }

}

node* insert (node **head, int value, int priority)
{

    node *elect = *head;
    node *inset = malloc(sizeof(node));

    if (inset == NULL)
    {
        return NULL;
    }

    inset -> value = value;
    inset -> priority = priority;
    inset -> next = NULL;

    if (elect == NULL)
    {
        return *head = inset;
    }

    node *previous = NULL;

    while (elect != NULL)
    {

        if (elect -> priority < priority)
        {
            break;
        }

        previous = elect;
        elect = elect -> next;

    }

    if (previous == NULL)
    {
        inset -> next = elect;
        return *head = inset;
    }

    previous -> next = inset;
    inset -> next = elect;

    return *head;

}

node* serve (node **head)
{

    node *elect = *head;

    if (elect == NULL)
    {
        return NULL;
    }

    *head = elect -> next;

    return elect;

}

node* peek (node **head)
{
    return *head;
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
