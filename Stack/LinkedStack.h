
#ifndef _Linked_Stack_For_C_Lan_H
#define _Linked_Stack_For_C_Lan_H

#include <stdbool.h>

typedef int ElementType;
struct Node;

typedef struct Node* PtrToNode;
typedef PtrToNode Stack;

struct Node
{
    PtrToNode next;
    PtrToNode prev;
    PtrToNode tail;

    int Size;
    ElementType Item;
};

Stack CreateStack();

bool IsEmpty(Stack S);

void DisposeStack(Stack S);
void MakeEmpty(Stack S);

void Push(Stack S, ElementType input);
ElementType Pop(Stack S);
ElementType Top(Stack S);

void PrintStack(Stack S);
#endif