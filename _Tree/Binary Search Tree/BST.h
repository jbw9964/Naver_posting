
#ifndef _Binary_Search_Tree_Include_Queue_For_C_Lan_H
#define _Binary_Search_Tree_Include_Queue_For_C_Lan_H

#include <stdbool.h>

/*--------------------------------------------------*/
// BST

typedef int ElementType_Tree;
struct Node_tree;

typedef struct Node_tree* PtrToNode_tree;
typedef PtrToNode_tree Tree;
typedef PtrToNode_tree Position;

struct Node_tree
{
    int Size;
    int LeftNodeNum;
    ElementType_Tree key;
    ElementType_Tree data;
    Position Left;
    Position Right;
};

Tree CreateBST();
Tree CopyBST(Tree T);

bool IsEmpty_tree(Tree T);

Position Find(Tree T, ElementType_Tree input);
Position FindKth_min(Tree T, int K);
Position FindMin(Tree T);

void DisposeTree(Tree T);

void Insert(Tree T, ElementType_Tree input);
Position Delete(Tree T, ElementType_Tree input);

void PrintLevelOrder(Tree T);
void PrintPreorder(Tree T);
void PrintInorder(Tree T);
void PrintPostorder(Tree T);

/*--------------------------------------------------*/
// Queue

typedef Position ElementType_Queue;
struct Node_queue;

typedef struct Node_queue* PtrToNode_queue;
typedef PtrToNode_queue Queue;

struct Node_queue
{
    int Size;
    int Capacity;

    int front;
    int rear;
    ElementType_Queue* Array;
};

Queue CreateQueue(int capacity);

bool IsEmpty_queue(Queue Q);
bool IsFull_queue(Queue Q);

void EnhanceCapacity(Queue Q);

void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);

void Push(Queue Q, ElementType_Queue input);
ElementType_Queue Pop(Queue Q);
ElementType_Queue Top(Queue Q);

void PrintQueue(Queue Q);

/*--------------------------------------------------*/
#endif