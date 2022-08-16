
#include <stdio.h>
#include <stdlib.h>

#include "ArrayStack.h"

Stack CreateStack(int capacity)
{
    Stack temp = (Stack)malloc(sizeof(struct Head));

    temp->Capacity = capacity;
    temp->Size = 0;
    temp->Array = (ElementType*)malloc(sizeof(ElementType) * capacity);

    return temp;
}

bool IsEmpty(Stack S)
{
    if (!S->Size)
    {
        return true;
    }
    return false;
}
bool IsFull(Stack S)
{
    if (S->Capacity == S->Size)
    {
        return true;
    }
    return false;
}

void EnhanceCapacity(Stack S)
{
    ElementType* temp_array = (ElementType*)malloc(sizeof(ElementType) * S->Capacity * 2);

    for (int i = 0; i < S->Size; i++)
    {
        temp_array[i] = S->Array[i];
    }

    free(S->Array);
    S->Array = temp_array;
    S->Capacity *= 2;
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
    ElementType value = S->Array[S->Size];
    S->Size--;
    return value;
}
ElementType Top(Stack S)
{
    return S->Array[S->Size];
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