
#ifndef _Linked_Queue_For_C_Lan_H
#define _Linked_Queue_For_C_Lan_H

#include <stdbool.h>

typedef int ElementType;
struct Node;
struct Head;

typedef struct Node* PtrToNode;
typedef struct Head* PtrToHead;
typedef PtrToNode Item;
typedef PtrToHead Queue;

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

Queue CreateQueue();

bool IsEmpty(Queue Q);

void Push(Queue Q, ElementType input);
ElementType Pop(Queue Q);
ElementType Top(Queue Q);

void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);

void PrintQueue(Queue Q);
#endif