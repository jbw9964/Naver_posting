
#ifndef _Linked_Stack_For_C_Lan_H
#define _Linked_Stack_For_C_Lan_H

#include <stdbool.h>

typedef int ElementType;
struct Node;
struct Head;

typedef struct Node* PtrToNode;
typedef struct Head* PtrToHead;
typedef PtrToNode Item;
typedef PtrToHead Stack;

struct Node
{
    ElementType key;
    ElementType data;
    PtrToNode next;
};

struct Head
{
    int Size;
    PtrToNode item;
    PtrToNode tail;

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