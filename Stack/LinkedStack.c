
#include <stdio.h>
#include <stdlib.h>

#include "LinkedStack.h"

Stack CreateStack()
{
    Stack temp = (Stack)malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->prev = NULL;
    temp->tail = NULL;
    temp->Size = 0;
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

void DisposeStack(Stack S)
{
    Stack temp = S->tail;

    for (int i = 0; i < S->Size; i++)
    {
        temp = temp->prev;
        free(temp->next);
    }
    
    free(S);
}
void MakeEmpty(Stack S)
{
    S->Size = 0;
}

void Push(Stack S, ElementType input)
{
    Stack temp = S;

    for (int i = 0; i < S->Size; i++)
    {
        temp = temp->next;
    }

    temp->next = (PtrToNode)malloc(sizeof(struct Node));
    temp->next->prev = temp;
    temp = temp->next;
    temp->Item = input;
    temp->next = NULL;

    S->tail = temp;
    S->Size++;
}
ElementType Pop(Stack S)
{
    ElementType value = S->tail->Item;

    Stack temp = S->tail->prev;
    S->tail = temp;

    free(temp->next);
    temp->next = NULL;
    S->Size--;

    return value;
}
ElementType Top(Stack S)
{
    return S->tail->Item;
}

void PrintStack(Stack S)
{
    if (IsEmpty(S))
    {
        printf("Stack is empty.\n");
        return;
    }

    Stack temp = S;
    for(int i = 0; i < S->Size; i++)
    {
        temp = temp->next;
        printf("%d ", temp->Item);
    }
    printf("\n");
}