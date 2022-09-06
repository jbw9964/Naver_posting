
#include <stdio.h>
#include <stdlib.h>

#include "BinarySearchTree.h"

Tree CreateBST(ElementType input)
{
    Tree temp = (Tree)malloc(sizeof(struct Node));
    temp->data = input;
    temp->Left = NULL;
    temp->Right = NULL;

    return temp;
}

Position Find(Tree T, ElementType input)
{
    if (!T)
    {
        return NULL;
    }
    else if (input < T->data)
    {
        return Find(T->Left, input);
    }
    else if (input > T->data)
    {
        return Find(T->Right, input);
    }
    else
    {
        return T;
    }
}

Tree Insert(Tree T, ElementType input)
{
    if (!T)
    {
        return CreateBST(input);
    }
    else if (input <= T->data)
    {
        T->Left = Insert(T->Left, input);
    }
    else if (input > T->data)
    {
        T->Right = Insert(T->Right, input);
    }

    return T;
}
Tree Delete(Tree T, ElementType input)
{
    if (!T)
    {
        return NULL;
    }
    else if (input < T->data)
    {
        return Delete(T->Left, input);
    }
    else if (input > T->data)
    {
        return Delete(T->Right, input);
    }
    else
    {
        return T;
    }
}

void Print_PreOrder(Tree T)
{
    if (!T)
    {
        return;
    }

    printf("%d ", T->data);
    if (T->Left)
    {
        Print_PreOrder(T->Left);
    }
    if (T->Right)
    {
        Print_PreOrder(T->Right);
    }
}
void Print_InOrder(Tree T)
{
    if (!T)
    {
        return;
    }

    if (T->Left)
    {
        Print_InOrder(T->Left);
    }
    printf("%d ", T->data);
    if (T->Right)
    {
        Print_InOrder(T->Right);
    }
}
void Print_PostOrder(Tree T)
{
    if (!T)
    {
        return;
    }

    if (T->Left)
    {
        Print_PostOrder(T->Left);
    }
    if (T->Right)
    {
        Print_PostOrder(T->Right);
    }
    printf("%d ", T->data);
}