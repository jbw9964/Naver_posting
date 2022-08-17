
#include <stdio.h>
#include <stdlib.h>

#include "LinkedQueue.h"

Queue CreateQueue()
{
    Queue temp = (Queue)malloc(sizeof(struct Head));
    temp->Size = 0;
    temp->item = NULL;
    temp->tail = NULL;


    return temp;
}

bool IsEmpty(Queue Q)
{
    return !Q->Size ? true : false;
}

void Push(Queue Q, ElementType input)
{
    if (IsEmpty(Q))
    {
        Q->item = (Item)malloc(sizeof(struct Node));
        Q->item->key = 0;
        Q->item->data = input;
        Q->item->next = NULL;

        Q->tail = Q->item;
        Q->Size++;
        return;
    }

    Item temp = Q->tail;
    temp->next = (Item)malloc(sizeof(struct Node));
    temp->next->key = 0;
    temp->next->data = input;
    temp->next->next = NULL;

    Q->tail = temp->next;
    Q->Size++;
}
ElementType Pop(Queue Q)
{
    if (IsEmpty(Q))
    {
        printf("Queue is empty. There's nothing to Pop.\n");
        return false;
    }

    ElementType value = Q->item->data;
    Item temp = Q->item;

    Q->item = temp->next;
    free(temp);
    Q->Size--;
    return value;
}
ElementType Top(Queue Q)
{
    ElementType temp = Pop(Q);
    if (temp)
    {
        Push(Q, temp);
    }
    return temp;
}

void MakeEmpty(Queue Q)
{
    while (!IsEmpty(Q))
    {
        Pop(Q);
    }
    Q->item = NULL;
    Q->tail = NULL;
}
void DisposeQueue(Queue Q)
{
    MakeEmpty(Q);
    free(Q);
}

void PrintQueue(Queue Q)
{
    if (IsEmpty(Q))
    {
        printf("Queue is empty.\n");
        return;
    }

    Item temp = Q->item;
    for (int i = 1; i < Q->Size; i++)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}