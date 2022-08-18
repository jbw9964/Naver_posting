
#include <stdio.h>
#include <stdlib.h>

#include "MinHeap.h"

int ReturnMinindex(ElementType* Array, int index_1, int index_2)
{
    return Array[index_1] <= Array[index_2] ? index_1 : index_2;
}
int Power(int num, int exp)
{
    int result = 1;
    for (int i = 0; i < exp; i++)
    {
        result *= num;
    }
    return result;
}
int ReturnHeapHeight(Heap H)
{
    int height = 0;
    while (H->Size - (Power(2, height) - 1) > 0)
    {
        height++;
    }
    return height;
}

Heap CreateHeap(int capacity)
{
    Heap temp = (Heap)malloc(sizeof(struct Node));
    temp->Size = 0;
    temp->Capacity = capacity;
    temp->Array = (ElementType*)malloc(sizeof(ElementType) * capacity);

    return temp;
}
Heap CopyHeap(Heap H)
{
    Heap copy = CreateHeap(H->Capacity);
    copy->Size = H->Size;

    for (int i = 0; i < H->Size; i++)
    {
        copy->Array[i] = H->Array[i];
    }

    return copy;
}

bool IsEmpty(Heap H)
{
    return !H->Size ? true : false;
}
bool IsFull(Heap H)
{
    return H->Size == H->Capacity ? true : false;
}
bool IsComplete(Heap H)
{
    return H->Size == (Power(2, ReturnHeapHeight(H)) - 1) ? true : false;
}
bool IsMinHeap(ElementType* Array, int array_size)
{
    bool result = true;
    int index = 0;

    while (result)
    {
        if ((index + 1) * 2 > array_size)
        {
            break;
        }

        if ((index + 1) * 2 + 1 > array_size)
        {
            if (Array[index] > Array[index + 1] * 2 - 1)
            {
                result = false;
            }
            break;
        }

        if ((Array[index] > Array[(index + 1) * 2 - 1]) || (Array[index] > Array[(index + 1) * 2]))
        {
            result = false;
        }
        index++;
    }

    return result;
}

void EnhanceCapacity(Heap H)
{
    H->Array = (ElementType*)realloc(H->Array, sizeof(ElementType) * H->Capacity * 2);
    H->Capacity *= 2;
}

void MakeEmpty(Heap H)
{
    H->Size = 0;
}
void DisposeHeap(Heap H)
{
    free(H->Array);
    free(H);
}

void ShiftUp(ElementType* Array, int index)
{
    ElementType child = Array[index];
    while (index)
    {
        ElementType parent = Array[(index + 1) / 2 - 1];

        if (child < parent)
        {
            Array[index] = parent;
            index = (index + 1) / 2 - 1;
        }
        else
        {
            index = (index + 1) / 2 - 1;
            break;
        }
    }
    Array[index] = child;
}
void ShiftDown(ElementType* Array, int index, int size)
{
    ElementType parent = Array[index];

    while ((index + 1) * 2 <= size)
    {
        if ((index + 1) * 2 + 1 > size)
        {
            if (parent > Array[(index + 1) * 2 - 1])
            {
                Array[index] = Array[(index + 1) * 2 - 1];
                index = (index + 1) * 2 - 1;
            }
            break;
        }
        else
        {
            int min_child = ReturnMinindex(Array, (index + 1) * 2 - 1, (index + 1) * 2);

            if (parent > Array[min_child])
            {
                Array[index] = Array[min_child];
                index = min_child;
            }
            else
            {
                break;
            }
        }
    }

    Array[index] = parent;
}

void DeleteMin(Heap H)
{
    H->Size--;
    H->Array[0] = H->Array[H->Size];
    ShiftDown(H->Array, 0, H->Size);
}

void HeapPush(Heap H, ElementType input)
{
    if (IsFull(H))
    {
        printf("Heap is full. Current capacity is %d. Need more capacity.\n", H->Capacity);
        EnhanceCapacity(H);
    }
    H->Array[H->Size] = input;
    ShiftUp(H->Array, H->Size);
    H->Size++;
}
ElementType HeapPop(Heap H)
{
    ElementType value = H->Array[0];
    H->Size--;
    H->Array[0] = H->Array[H->Size];
    ShiftDown(H->Array, 0, H->Size);
    return value;
}
ElementType HeapTop(Heap H)
{
    return H->Array[0];
}

ElementType* MaxHeapify(ElementType* input_array, int array_size)
{
    int index = array_size / 2 - 1;

    for (int i = index; i >= 0; i--)
    {
        ShiftDown(input_array, i, array_size);
    }
    
    return input_array;
}
Heap BuildHeap(ElementType* input_array, int array_size)
{
    Heap temp = CreateHeap(array_size);
    temp->Size = array_size;
    temp->Array = MaxHeapify(input_array, array_size);
    return temp;
}
Heap MinHeapMerge(Heap H1, Heap H2)
{
    Heap temp = CreateHeap(H1->Capacity + H2->Capacity);
    temp->Size = H1->Size + H2->Size;

    if (H1->Size < H2->Size)
    {
        Heap allo = H1;
        H1 = H2;
        H2 = allo;
    }

    bool temp_result = false;
    if ((ReturnHeapHeight(H1) - ReturnHeapHeight(H2) >= 2) || !IsComplete(H2))
    {
        Heap allo_1 = CopyHeap(H1);
        Heap allo_2 = CopyHeap(H2);

        while ((ReturnHeapHeight(allo_1) - ReturnHeapHeight(allo_2) >= 2) || !(IsComplete(allo_1) || IsComplete(allo_2)))
        {
            HeapPush(allo_2, HeapPop(allo_1));
        }
        temp_result = true;
        if (allo_1->Size < allo_2->Size)
        {
            H1 = allo_2;
            H2 = allo_1;
        }
        else
        {
            H1 = allo_1;
            H2 = allo_2;
        }
    }

    int count_loop = 1, count_index = 1;
    int count_H1 = 0, count_H2 = 0;

    while (true)
    {
        for (int i = 0; i < count_loop; i++)
        {
            if (count_H1 < H1->Size)
            {
                temp->Array[count_index] = H1->Array[count_H1];
                count_index++;
                count_H1++;
            }
        }

        for (int i = 0; i < count_loop; i++)
        {
            if (count_H2 < H2->Size)
            {
                temp->Array[count_index] = H2->Array[count_H2];
                count_index++;
                count_H2++;
            }
        }

        count_loop *= 2;
        if ((count_H1 >= H1->Size) && (count_H2 >= H2->Size))
        {
            break;
        }
    }

    if (temp_result)
    {
        DisposeHeap(H1);
        DisposeHeap(H2);
    }
    HeapPop(temp);
    return temp;
}

void PrintHeap(Heap H)
{
    if (IsEmpty(H))
    {
        printf("Heap is empty.\n");
        return;
    }
    for (int i = 0; i < H->Size; i++)
    {
        printf("%d ", H->Array[i]);
    }
    printf("\n");
}