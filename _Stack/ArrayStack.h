
#ifndef _Array_Stack_For_C_Lan_H
#define _Array_Stack_For_C_Lan_H

#include <stdbool.h>

typedef int ElementType;
struct Head;
typedef struct Head* Stack;

struct Head
{
    int Capacity;
    int Size;
    ElementType* Array;
};


Stack CreateStack(int capacity);

bool IsEmpty(Stack S);
bool IsFull(Stack S);

void EnhanceCapacity(Stack S);

void DisposeStack(Stack S);
void MakeEmpty(Stack S);

void Push(Stack S, ElementType input);
ElementType Pop(Stack S);
ElementType Top(Stack S);

void PrintStack(Stack S);
#endif