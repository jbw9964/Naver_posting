
#include <stdio.h>
#include <stdlib.h>

#include "ArrayDeque.h"

Deque CreateDeque(int capacity)
{
    Deque temp = (Deque)malloc(sizeof(struct Node));
    temp->Size = 0;
    temp->Capacity = capacity;
    temp->front = 0;
    temp->rear = 0;
    temp->Array = (ElementType*)malloc(sizeof(ElementType) * capacity);

    return temp;
}
Deque CopyDeque(Deque dq)
{
    Deque temp = CreateDeque(dq->Capacity);
    temp->Size = dq->Size;
    temp->front = dq->front;
    temp->rear = dq->rear;

    int count = 0;
    int index = dq->front;
    while (count != dq->Size)
    {
        temp->Array[index] = dq->Array[index];
        index = (index + 1) % dq->Capacity;
        count++;
    }

    return temp;
}

bool IsEmpty(Deque dq)
{
    return !dq->Size ? true : false;
}
bool IsFull(Deque dq)
{
    return dq->Size == dq->Capacity ? true : false;
}

void MakeEmpty(Deque dq)
{
    dq->Size = 0;
    dq->front = 0;
    dq->rear = 0;
}
void DisposeDeque(Deque dq)
{
    free(dq->Array);
    free(dq);
}

ElementType PopFront(Deque dq)
{
    if (IsEmpty(dq))
    {
        return false;
    }
    ElementType value = dq->Array[dq->front];
    dq->Size--;
    dq->front = (dq->front + 1) % dq->Capacity;
    return value;
}
ElementType PopRear(Deque dq)
{
    if (IsEmpty(dq))
    {
        return false;
    }
    ElementType value = dq->Array[dq->rear - 1];
    dq->Size--;
    dq->rear--;
    if (dq->rear < 0)
    {
        dq->rear += dq->Capacity;
    }
    return value;
}
ElementType TopFront(Deque dq)
{
    return IsEmpty(dq) ? false : dq->Array[dq->front];
}
ElementType TopRear(Deque dq)
{
    return IsEmpty(dq) ? false : dq->Array[dq->rear - 1];
}
void DeleteFront(Deque dq)
{
    if (!IsEmpty(dq))
    {
        dq->Size++;
        dq->front = (dq->front + 1) % dq->Capacity;
    }
}
void DeleteRear(Deque dq)
{
    if (!IsEmpty(dq))
    {
        dq->Size--;
        dq->rear--;
        if (dq->rear < 0)
        {
            dq->rear += dq->Capacity;
        }
    }
}

void EnhanceCapacity(Deque dq)
{
    ElementType* temp = (ElementType*)malloc(sizeof(ElementType) * dq->Capacity * 2);

    int count = 0;
    while (!IsEmpty(dq))
    {
        temp[count] = PopFront(dq);
        count++;
    }

    dq->Capacity *= 2;
    dq->front = 0;
    dq->rear = count;
    free(dq->Array);
    dq->Array = temp;
}

void InsertFront(Deque dq, ElementType input)
{
    if (IsFull(dq))
    {
        printf("Deque is full. Need more Capacity. Current Capacity is %d.\n", dq->Capacity);
        EnhanceCapacity(dq);
    }

    dq->Size++;
    dq->front--;
    if (dq->front < 0)
    {
        dq->front += dq->Capacity;
    }
    dq->Array[dq->front] = input;
}
void InsertRear(Deque dq, ElementType input)
{
    if (IsFull(dq))
    {
        printf("Deque is full. Need more Capacity. Current Capacity is %d.\n", dq->Capacity);
        EnhanceCapacity(dq);
    }

    dq->Size++;
    dq->Array[dq->rear] = input;
    dq->rear = (dq->rear + 1) % dq->Capacity;
}

void PrintDeque(Deque dq)
{
    if (IsEmpty(dq))
    {
        printf("Deque is empty.\n");
        return;
    }

    int count = 0;
    int index = dq->front;
    while (count != dq->Size)
    {
        printf("%d ", dq->Array[index]);
        index = (index + 1) % dq->Capacity;
        count++;
    }
    printf("\n");
}