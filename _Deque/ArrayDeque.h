
#ifndef _Array_Deque_For_C_Lan_H
#define _Array_Deque_For_C_Lan_H

#include <stdbool.h>

typedef int ElementType;
struct Node;

typedef struct Node* PtrToNode;
typedef PtrToNode Deque;

struct Node
{
    int Size;
    int Capacity;

    int front;
    int rear;
    ElementType* Array;
};

Deque CreateDeque(int capacity);
Deque CopyDeque(Deque dq);

bool IsEmpty(Deque dq);
bool IsFull(Deque dq);

void MakeEmpty(Deque dq);
void DisposeDeque(Deque dq);

ElementType PopFront(Deque dq);
ElementType PopRear(Deque dq);
ElementType TopFront(Deque dq);
ElementType TopRear(Deque dq);

void EnhanceCapacity(Deque dq);

void InsertFront(Deque dq, ElementType input);
void InsertRear(Deque dq, ElementType input);
void DeleteFront(Deque dq);
void DeleteRear(Deque dq);

void PrintDeque(Deque dq);
#endif