
#include <stdio.h>
#include <stdlib.h>

#include "LinkedStack.h"

Stack CreateStack()
{
    Stack temp = (Stack)malloc(sizeof(struct Head));
    temp->Size = 0;
    temp->item = NULL;
    temp->tail = NULL;

    return temp;
}

bool IsEmpty(Stack S)
{
    return !S->Size ? true : false;
}

void Push(Stack S, ElementType input)
{
    if (IsEmpty(S))
    {
        S->item = (Item)malloc(sizeof(struct Node));
        S->item->key = 0;
        S->item->data = input;
        S->item->next = NULL;

        S->tail = S->item;
        S->Size++;
        return;
    }

    Item temp = S->item;

    S->item = (Item)malloc(sizeof(struct Node));
    S->item->key = 0;
    S->item->data = input;
    S->item->next = temp;

    S->Size++;
}
ElementType Pop(Stack S)
{
    if (IsEmpty(S))
    {
        printf("Stack is empty. There's nothing to Pop.\n");
        return false;
    }

    ElementType value = S->item->data;
    Item temp = S->item;
    
    S->item = temp->next;
    free(temp);
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

void MakeEmpty(Stack S)
{
    while (IsEmpty(S))
    {
        Pop(S);
    }
    S->item = NULL;
    S->tail = NULL;
}
void DisposeStack(Stack S)
{
    MakeEmpty(S);
    free(S);
}

void PrintStack(Stack S)
{
    if (IsEmpty(S))
    {
        printf("Stack is empty.\n");
        return;
    }

    Item temp = S->item;
    for (int i = 1; i < S->Size; i++)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}