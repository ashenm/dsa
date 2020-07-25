/**
 * 10.c
 * Linked Lists
 * https://github.com/ashenm/dsa
 *
 * Implements a double-ended queue
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

typedef struct deque
{
    struct node *head;
    struct node *tail;
} deque;

// removes the rightmost node
node* pop (deque *list);

// removes the leftmost node
node* shift (deque *list);

// conjoins a node to right
deque* unshift (deque *list, int value);

// conjoins a node to left
deque* push (deque *list, int value);

// computes the node count
int range (deque *list);

int main (void)
{

    deque *list = malloc(sizeof(node));

    push(list, 50);
    unshift(list, 25);
    push(list, 75);

    printf("%i\n", range(list));

    free(pop(list));
    free(shift(list));

    node *elect = list -> head;

    while (elect != NULL)
    {
        printf("%i\n", elect -> value);
        elect = elect -> next;
    }

    while (list -> head != NULL)
    {
        elect = list -> head;
        list -> head = list -> head -> next;
        free(elect);
    }

    free(list);

}

node* pop (deque *list)
{

    if (list == NULL)
    {
        return NULL;
    }

    node *elect = list -> tail;

    if (elect == NULL)
    {
        return NULL;
    }

    list -> tail = elect -> prev;

    if (list -> tail != NULL)
    {
        list -> tail -> next = NULL;
    }

    return elect;

}

node* shift (deque *list)
{

    if (list == NULL)
    {
        return NULL;
    }

    node *elect = list -> head;

    if (elect == NULL)
    {
        return NULL;
    }

    list -> head = elect -> next;

    if (list -> head != NULL)
    {
        list -> head -> prev = NULL;
    }

    return elect;

}

deque* unshift (deque *list, int value)
{

    if (list == NULL)
    {
        return NULL;
    }

    node *inset = malloc(sizeof(node));

    if (inset == NULL)
    {
        return NULL;
    }

    inset -> prev = NULL;
    inset -> value = value;
    inset -> next = list -> head;

    if (list -> head == NULL)
    {
        list -> head = inset;
        list -> tail = inset;
        return list;
    }

    list -> head -> prev = inset;
    list -> head = inset;

    return list;

}

deque* push (deque *list, int value)
{

    if (list == NULL)
    {
        return NULL;
    }

    node *inset = malloc(sizeof(node));

    if (inset == NULL)
    {
        return NULL;
    }

    inset -> prev = list -> tail;
    inset -> value = value;
    inset -> next = NULL;

    if (list -> tail == NULL)
    {
        list -> head = inset;
        list -> tail = inset;
        return list;
    }

    list -> tail -> next = inset;
    list -> tail = inset;

    return list;

}

int range (deque *list)
{

    int n = 0;

    if (list == NULL)
    {
        return n;
    }

    node *elect = list -> head;

    while (elect != NULL)
    {
        elect = elect -> next;
        n += 1;
    }

    return n;

}

// vim: set expandtab shiftwidth=4:
