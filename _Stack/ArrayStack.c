
#include <stdio.h>
#include <stdlib.h>

#include "ArrayStack.h"

Stack CreateStack(int capacity)
{
    Stack temp = (Stack)malloc(sizeof(struct Node));

    if (capacity < 1)
    {
        capacity = 1;
    }
    temp->Capacity = capacity;
    temp->Size = 0;
    temp->Array = (ElementType*)malloc(sizeof(ElementType) * capacity);

    return temp;
}

bool IsEmpty(Stack S)
{
    return !S->Size ? true : false;
}
bool IsFull(Stack S)
{
    return S->Capacity >= S->Size ? true : false;
}

void EnhanceCapacity(Stack S)
{
    S->Array = (ElementType*)realloc(S->Array, sizeof(ElementType) * S->Capacity * 2);
}

void DisposeStack(Stack S)
{
    free(S->Array);
    free(S);
}
void MakeEmpty(Stack S)
{
    S->Size = 0;
}

void Push(Stack S, ElementType input)
{
    if (IsFull(S))
    {
        printf("Stack is full. Current capacity is %d. Need more capacity.\n", S->Size);
        EnhanceCapacity(S);
    }

    S->Array[S->Size] = input;
    S->Size++;
}
ElementType Pop(Stack S)
{
    if (IsEmpty(S))
    {
        printf("Stack is empty. There's nothing to Pop.\n");
        return false;
    }
    ElementType value = S->Array[S->Size - 1];
    S->Size--;
    return value;
}
ElementType Top(Stack S)
{
    ElementType temp = Pop(S);
    if (temp)
    {
        Push(S, temp);
    }
    return temp;
}

void PrintStack(Stack S)
{
    if (IsEmpty(S))
    {
        printf("Stack is empty.\n");
        return;
    }

    for (int i = 0; i < S->Size; i++)
    {
        printf("%d ", S->Array[i]);
    }
    printf("\n");
}