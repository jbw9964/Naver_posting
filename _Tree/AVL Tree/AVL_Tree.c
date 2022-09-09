
#include <stdio.h>
#include <stdlib.h>

#include "AVL_Tree_new.h"

int ReturnMax(int input_1, int input_2)
{
    return input_1 >= input_2 ? input_1 : input_2;
}
int ReturnHeight(Position P)
{
    return !P ? -1 : P->Height;
}

Tree CreateAVL(ElementType input)
{
    Tree temp = (Tree)malloc(sizeof(struct AVL_Node));
    temp->Height = 0;
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

Position Rotate_LL(Position K2)
{
    Position K1 = K2->Left;
    Position Y = K1->Right;

    K1->Right = K2;
    K2->Left = Y;

    K2->Height = 1 + ReturnMax(ReturnHeight(K2->Left), ReturnHeight(K2->Right));
    K1->Height = 1 + ReturnMax(ReturnHeight(K1->Left), ReturnHeight(K1->Right));

    return K1;
}
Position Rotate_RR(Position K1)
{
    Position K2 = K1->Right;
    Position Y = K2->Left;

    K2->Left = K1;
    K1->Right = Y;

    K1->Height = 1 + ReturnMax(ReturnHeight(K1->Left), ReturnHeight(K1->Right));
    K2->Height = 1 + ReturnMax(ReturnHeight(K2->Left), ReturnHeight(K2->Right));

    return K2;
}
Position Rotate_LR(Position K3)
{
    Position K1 = K3->Left;
    Position K2 = K1->Right;

    Position X = K2->Left;
    Position Y = K2->Right;

    K2->Left = K1;
    K2->Right = K3;
    
    K1->Right = X;
    K3->Left = Y;

    K1->Height = 1 + ReturnMax(ReturnHeight(K1->Left), ReturnHeight(K1->Right));
    K3->Height = 1 + ReturnMax(ReturnHeight(K3->Left), ReturnHeight(K3->Right));
    K2->Height = 1 + ReturnMax(ReturnHeight(K2->Left), ReturnHeight(K2->Right));

    return K2;
}
Position Rotate_RL(Position K3)
{
    Position K1 = K3->Right;
    Position K2 = K1->Left;

    Position X = K2->Left;
    Position Y = K2->Right;

    K2->Left = K3;
    K2->Right = K1;

    K3->Right = X;
    K1->Left = Y;

    K3->Height = 1 + ReturnMax(ReturnHeight(K3->Left), ReturnHeight(K3->Right));
    K1->Height = 1 + ReturnMax(ReturnHeight(K1->Left), ReturnHeight(K1->Right));
    K2->Height = 1 + ReturnMax(ReturnHeight(K2->Left), ReturnHeight(K2->Right));

    return K2;
}

Tree Insert(Tree T, ElementType input)
{
    if (!T)
    {
        T = CreateAVL(input);
        return T;
    }

    else if (input <= T->data)
    {
        T->Left = Insert(T->Left, input);

        if (ReturnHeight(T->Left) - ReturnHeight(T->Right) >= 2)
        {
            if (input <= T->Left->data)
            {
                T = Rotate_LL(T);
            }
            else
            {
                T = Rotate_LR(T);
            }
        }
    }

    else if (input > T->data)
    {
        T->Right = Insert(T->Right, input);

        if (ReturnHeight(T->Right) - ReturnHeight(T->Height) >= 2)
        {
            if (input > T->Right->data)
            {
                T = Rotate_RR(T);
            }
            else
            {
                T = Rotate_RL(T);
            }
        }
    }
    
    T->Height = 1 + ReturnMax(ReturnHeight(T->Left), ReturnHeight(T->Right));

    return T;
}
Tree Delete(Tree T, ElementType input);

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