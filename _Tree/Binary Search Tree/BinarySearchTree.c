
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

void DisposeBST(Tree T)
{
    if (!T)
    {
        return;
    }
    if (T->Left)
    {
        DisposeBST(T->Left);
        free(T->Left);
    }
    if (T->Right)
    {
        DisposeBST(T->Right);
        free(T->Right);
    }
    free(T);
    T = NULL;
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
        T->Left = Delete(T->Left, input);
    }
    else if (input > T->data)
    {
        T->Right = Delete(T->Right, input);
    }
    else
    {
        if (!T->Left && !T->Right)      // has no child
        {
            DisposeBST(T);
            T = NULL;
            return NULL;
        }
        else if (T->Left && T->Right)   // has both child
        {
            T->data = T->Right->data;
            T->Right = Delete(T->Right, T->Right->data);
        }
        else if (T->Left)               // has left child
        {
            T->data = T->Left->data;
            free(T->Left);
        }
        else                            // has right child
        {
            T->data = T->Right->data;
            free(T->Right);
        }
    }

    return T;
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