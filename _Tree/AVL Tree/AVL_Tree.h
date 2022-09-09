
#ifndef _AVL_Tree_For_C_Lan_H
#define _AVL_Tree_For_C_Lan_H

typedef int ElementType;
struct AVL_Node;

typedef struct AVL_Node* Tree;
typedef struct AVL_Node* Position;

struct AVL_Node
{
    int Height;
    ElementType data;

    Position Left;
    Position Right;
};

int ReturnMax(int input_1, int input_2);
int ReturnHeight(Position P);

Tree CreateAVL(ElementType input);

Position Find(Tree T, ElementType input);

Position Rotate_LL(Position K2);
Position Rotate_RR(Position K2);
Position Rotate_LR(Position P);
Position Rotate_RL(Position P);

Tree Insert(Tree T, ElementType input);
Tree Delete(Tree T, ElementType input);

void Print_PreOrder(Tree T);
void Print_InOrder(Tree T);
void Print_PostOrder(Tree T);
#endif