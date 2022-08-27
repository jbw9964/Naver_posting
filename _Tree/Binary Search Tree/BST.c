
#include <stdio.h>
#include <stdlib.h>

#include "BST.h"

/*--------------------------------------------------*/

Queue CreateQueue(int capacity)
{
    Queue temp = (Queue)malloc(sizeof(struct Node_queue));
    temp->Size = 0;
    
    if (capacity <= 1)
    {
        capacity = 2;
    }
    temp->Capacity = capacity;
    temp->front = 0;
    temp->rear = 0;

    temp->Array = (ElementType_Queue*)malloc(sizeof(ElementType_Queue) * capacity);

    return temp;
}

bool IsEmpty_queue(Queue Q)
{
    return !Q->Size ? true : false;
}
bool IsFull_queue(Queue Q)
{
    return Q->Size >= Q->Capacity ? true : false;
}

void EnhanceCapacity(Queue Q)
{
    ElementType_Queue* temp = (ElementType_Queue*)malloc(sizeof(ElementType_Queue) * Q->Capacity * 2);

    int new_index = 0;
    int index_count = Q->front;
    while (new_index < Q->Size)
    {
        temp[new_index] = Q->Array[index_count];
        index_count = (index_count + 1) % Q->Capacity;
        new_index++;
    }

    Q->front = 0;
    Q->rear = new_index;
    free(Q->Array);
    Q->Array = temp;
    Q->Capacity *= 2;
}

void DisposeQueue(Queue Q)
{
    free(Q->Array);
    free(Q);
}
void MakeEmpty(Queue Q)
{
    Q->front = 0;
    Q->rear = 0;
    Q->Size = 0;
}

void Push(Queue Q, ElementType_Queue input)
{
    if (IsFull_queue(Q))
    {
        printf("Queue is full. Current capacity is %d. Need more capacity.\n", Q->Capacity);
        EnhanceCapacity(Q);
    }

    Q->Array[Q->rear] = input;
    Q->rear = (Q->rear + 1) % Q->Capacity;
    Q->Size++;
}
ElementType_Queue Pop(Queue Q)
{
    if (IsEmpty_queue(Q))
    {
        printf("Queue is empty. There's nothing to Pop.\n");
        return false;
    }

    ElementType_Queue value = Q->Array[Q->front];
    Q->front = (Q->front + 1) % Q->Capacity;
    Q->Size--;
    return value;
}
ElementType_Queue Top(Queue Q)
{
    ElementType_Queue temp = Pop(Q);
    if (temp)
    {
        Push(Q, temp);
    }
    return temp;
}

void PrintQueue(Queue Q)
{
    if (IsEmpty_queue(Q))
    {
        printf("Queue is empty.\n");
        return;
    }

    int count = 0;
    int index_count = Q->front;
    while (count != Q->Size)
    {
        printf("%p ", Q->Array[index_count]);
        index_count = (index_count + 1) % Q->Capacity;
        count++;
    }
    printf("\n");
}

/*--------------------------------------------------*/

Tree CreateBST()
{
    Tree temp = (Tree)malloc(sizeof(struct Node_tree));
    temp->Size = 0;
    temp->LeftNodeNum = 0;
    temp->key = 0;
    temp->data = false;
    temp->Left = NULL, temp->Right = NULL;

    return temp;
}
Tree CopyBST(Tree T)
{

    Tree temp = CreateBST();

    Queue Q_1 = CreateQueue(256);
    Queue Q_2 = CreateQueue(256);

    Push(Q_1, T);
    Push(Q_2, temp);

    while (!IsEmpty_queue(Q_1))
    {
        Position current = Pop(Q_1);
        Position temp_current = Pop(Q_2);

        temp_current->Size = current->Size;
        temp_current->LeftNodeNum = current->LeftNodeNum;
        temp_current->key = current->key;
        temp_current->data = current->data;

        if (current->Left)
        {
            temp_current->Left = CreateBST();
            Push(Q_1, current->Left);
            Push(Q_2, temp_current->Left);
        }
        if (current->Right)
        {
            temp_current->Right = CreateBST();
            Push(Q_1, current->Right);
            Push(Q_2, temp_current->Right);
        }
    }

    return temp;
}

bool IsEmpty_tree(Tree T)
{
    return !T->Size ? true : false;
}

Position Find(Tree T, ElementType_Tree input)
{
    Position current = T;

    while (current)
    {
        if (input > current->data)
        {
            current = current->Right;
        }
        else if (input > current->data)
        {
            current = current->Left;
        }
        else
        {
            break;
        }
    }

    if (!current)
    {
        printf("There is no %d in Tree. Return Nullptr.\n", input);
    }
    return current;
}
Position FindKth_min(Tree T, int K)
{
    if (T->Size < K || K <= 0)
    {
        printf("There is no %dth element in Tree.\n", K);
        return NULL;
    }

    K -= 1;
    Position current = T;
    while (true)
    {
        if (current->LeftNodeNum == K)
        {
            break;
        }
        else if (current->LeftNodeNum > K)
        {
            current = current->Left;
        }
        else
        {
            K -= current->LeftNodeNum + 1;
            current = current->Right;
        }
    }

    return current;
}
Position FindMin(Tree T)
{

    // return !T || !T->Left ? (!T ? NULL : T) : FindMin(T->Left);

    if (!T)
    {
        return NULL;
    }
    else if (!T->Left)
    {
        return T;
    }
    else
    {
        return FindMin(T->Left);
    }
}

void DisposeTree(Tree T)
{
    if (!T)
    {
        return;
    }
    if (T->Left)
    {
        DisposeTree(T->Left);
    }
    if (T->Right)
    {
        DisposeTree(T->Right);
    }
    free(T);
}

void Insert(Tree T, ElementType_Tree input)
{
    if (IsEmpty_tree(T))
    {
        T->data = input;
        T->Size++;
        return;
    }

    Position current = T;
    Position prev;

    while (current)
    {
        if (input > current->data)
        {
            prev = current;
            current->Size++;
            current = current->Right;
        }
        else
        {
            prev = current;
            current->Size++;
            current->LeftNodeNum++;
            current = current->Left;
        }
    }

    if (input > prev->data)
    {
        prev->Right = CreateBST();
        prev->Right->data = input;
    }
    else
    {
        prev->Left = CreateBST();
        prev->Left->data = input;
    }
    T->Size++;
}
Position Delete(Tree T, ElementType_Tree input)
{
    if (!T)
    {
        return NULL;
    }
    else if (input < T->data)
    {
        T->Left = Delete(T->Left, input);
    }
    else if (input > T->data)
    {
        T->Right = Delete(T->Right, input);
    }
    else if (!(T->Left && T->Right))
    {
        Position temp = T;
        if (!T->Left)
        {
            T = T->Right;
        }
        else if (!T->Right)
        {
            T = T->Left;
        }
        free(temp);
    }
    else
    {
        Position temp = FindMin(T->Right);
        T->data = temp->data;
        T->Right = Delete(T->Right, T->data);
    }

    return T;
}

void PrintLevelOrder(Tree T)
{
    Queue Q_1 = CreateQueue(256);
    Queue Q_2 = CreateQueue(256);

    Push(Q_1, T);

    int count = 1;
    while (!IsEmpty_queue(Q_1))
    {
        while (!IsEmpty_queue(Q_1))
        {
            Push(Q_2, Pop(Q_1));
        }

        printf("Level %d : ", count);
        count++;
        while (!IsEmpty_queue(Q_2))
        {
            Position current = Pop(Q_2);
            printf("%d ", current->data);

            if (current->Left)
            {
                Push(Q_1, current->Left);
            }
            if (current->Right)
            {
                Push(Q_1, current->Right);
            }
        }
        printf("\n");
    }
}
void PrintPreorder(Tree T)
{
    if (!T)
    {
        return;
    }

    printf("%d ", T->data);
    if (T->Left)
    {
        PrintPreorder(T->Left);
    }
    if (T->Right)
    {
        PrintPreorder(T->Right);
    }
}
void PrintInorder(Tree T)
{
    if (!T)
    {
        return;
    }

    if (T->Left)
    {
        PrintInorder(T->Left);
    }
    printf("%d ", T->data);
    if (T->Right)
    {
        PrintInorder(T->Right);
    }
}
void PrintPostorder(Tree T)
{
    if (!T)
    {
        return;
    }

    if (T->Left)
    {
        PrintPostorder(T->Left);
    }
    if (T->Right)
    {
        PrintPostorder(T->Right);
    }
    printf("%d ", T->data);
}
void PrintTree(Tree T)
{
    if (!T)
    {
        return;
    }
    if (T->Left)
    {
        PrintTree(T->Left);
    }
    if (T->Right)
    {
        PrintTree(T->Right);
    }
    printf("%d ", T->data);
}