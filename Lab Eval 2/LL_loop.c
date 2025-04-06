#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
} Node;

void removeLoop(Node *start)
{
    Node *tortoise = start;
    Node *hare = start;
    int loopExists = 0;

    while (hare != NULL && hare->link != NULL)
    {
        tortoise = tortoise->link;
        hare = hare->link->link;

        if (tortoise == hare)
        {
            loopExists = 1;
            break;
        }
    }

    if (!loopExists)
    {
        return;
    }

    tortoise = start;
    Node *precedingHare = NULL;

    while (tortoise != hare)
    {
        tortoise = tortoise->link;
        precedingHare = hare;
        hare = hare->link;
    }

    if (precedingHare != NULL)
    {
        precedingHare->link = NULL;
    }
}