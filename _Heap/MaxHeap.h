
#ifndef _MaxHeap_For_C_Lan_H
#define _MaxHeap_For_C_Lan_H

#include <stdbool.h>

typedef int ElementType;
struct Node;

typedef struct Node* PtrToNode;
typedef PtrToNode Heap;

struct Node
{
    int Size;
    int Capacity;
    ElementType* Array;
};

int ReturnMaxindex(ElementType* array, int index_1, int index_2);
int Power(int num, int exp);
int ReturnHeapHeight(Heap H);

Heap CreateHeap(int capacity);
Heap CopyHeap(Heap H);

bool IsEmpty(Heap H);
bool IsFull(Heap H);
bool IsComplete(Heap H);
bool IsMaxHeap(ElementType* Array, int array_size);

void EnhanceCapacity(Heap H);

void MakeEmpty(Heap H);
void DisposeHeap(Heap H);

void ShiftUp(ElementType* array, int index);
void ShiftDown(ElementType* array, int index, int size);

void DeleteMax(Heap H);

void HeapPush(Heap H, ElementType input);
ElementType HeapPop(Heap H);
ElementType HeapTop(Heap H);

ElementType* MaxHeapify(ElementType* input_array, int array_size);
Heap BuildHeap(ElementType* input_array, int array_size);
Heap MaxHeapMerge(Heap H1, Heap H2);

void PrintHeap(Heap H);
#endif