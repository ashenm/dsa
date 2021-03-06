/**
 * 4.c
 * Linked Lists
 * https://github.com/ashenm/dsa
 *
 * Implements dynamic memory discharge
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
node* append (node *head, int value);

int main (void)
{

    node *head = NULL;

    head = append(head, 25);
    head = append(head, 50);

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

node* append (node *head, int value)
{

    node *inset = malloc(sizeof(node));

    if (inset == NULL)
    {
        return NULL;
    }

    inset -> value = value;
    inset -> next = NULL;

    if (head == NULL)
    {
        return inset;
    }

    node *elect = head;

    while (elect -> next != NULL)
    {
        elect = elect -> next;
    }

    elect -> next = inset;

    return head;

}

// vim: set expandtab shiftwidth=4:
