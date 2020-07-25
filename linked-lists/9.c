/**
 * 9.c
 * Linked Lists
 * https://github.com/ashenm/dsa
 *
 * Implements a doubly linked list
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
    struct node *prev;
} node;

// conjoins a new node
node* append (node **head, int value);

// computes the node count
int range (node *head);

int main (void)
{

    node *head = NULL;

    append(&head, 25);
    append(&head, 50);

    printf("%i\n", range(head));

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

node* append (node **head, int value)
{

    node *inset = malloc(sizeof(node));

    if (inset == NULL)
    {
        return NULL;
    }

    inset -> prev = *head;
    inset -> value = value;
    inset -> next = NULL;

    if (*head == NULL)
    {
        return *head = inset;
    }

    node *elect = *head;

    while (elect -> next != NULL)
    {
        elect = elect -> next;
    }

    elect -> next = inset;
    inset -> prev = elect;

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
