
#include <stdio.h>
#include <stdlib.h>

#include "ArrayQueue.h"

Queue CreateQueue(int capacity)
{
    Queue temp = (Queue)malloc(sizeof(struct Node));
    temp->Size = 0;
    
    if (capacity <= 1)
    {
        capacity = 2;
    }
    temp->Capacity = capacity;
    temp->front = 0;
    temp->rear = 0;

    temp->Array = (ElementType*)malloc(sizeof(ElementType) * capacity);

    return temp;
}

bool IsEmpty(Queue Q)
{
    return !Q->Size ? true : false;
}
bool IsFull(Queue Q)
{
    return Q->Size >= Q->Capacity ? true : false;
}

void EnhanceCapacity(Queue Q)
{
    ElementType* temp = (ElementType*)malloc(sizeof(ElementType) * Q->Capacity * 2);

    int new_index = 0;
    int index_count = Q->front;
    while (new_index < Q->Size)
    {
        temp[new_index] = Q->Array[index_count];
        index_count = (index_count + 1) % Q->Capacity;
        new_index++;
    }

    Q->front = 0;
    Q->rear = new_index;
    free(Q->Array);
    Q->Array = temp;
    Q->Capacity *= 2;
}

void DisposeQueue(Queue Q)
{
    free(Q->Array);
    free(Q);
}
void MakeEmpty(Queue Q)
{
    Q->front = 0;
    Q->rear = 0;
    Q->Size = 0;
}

void Push(Queue Q, ElementType input)
{
    if (IsFull(Q))
    {
        printf("Queue is full. Current capacity is %d. Need more capacity.\n", Q->Capacity);
        EnhanceCapacity(Q);
    }

    Q->Array[Q->rear] = input;
    Q->rear = (Q->rear + 1) % Q->Capacity;
    Q->Size++;
}
ElementType Pop(Queue Q)
{
    if (IsEmpty(Q))
    {
        printf("Queue is empty. There's nothing to Pop.\n");
        return false;
    }

    ElementType value = Q->Array[Q->front];
    Q->front = (Q->front + 1) % Q->Capacity;
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

void PrintQueue(Queue Q)
{
    if (IsEmpty(Q))
    {
        printf("Queue is empty.\n");
        return;
    }

    int count = 0;
    int index_count = Q->front;
    while (count != Q->Size)
    {
        printf("%d ", Q->Array[index_count]);
        index_count = (index_count + 1) % Q->Capacity;
        count++;
    }
    printf("\n");
}