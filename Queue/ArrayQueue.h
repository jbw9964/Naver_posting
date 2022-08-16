
#ifndef _Array_Queue_For_C_Lan_H
#define _Array_Queue_For_C_Lan_H

#include <stdbool.h>

typedef int ElementType;
struct Node;

typedef struct Node* PtrToNode;
typedef PtrToNode Queue;

struct Node
{
    int Size;
    int Capacity;

    int front;
    int rear;
    ElementType* Array;
};

Queue CreateQueue(int capacity);

bool Isempty(Queue Q);
bool IsFull(Queue Q);

void EnhanceCapacity(Queue Q);

void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);

void Push(Queue Q, ElementType input);
ElementType Pop(Queue Q);
ElementType Top(Queue Q);

void PrintQueue(Queue Q);
#endif