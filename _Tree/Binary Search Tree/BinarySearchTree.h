
#ifndef _Binary_Search_Tree_For_C_Lan_H
#define _Binary_Search_Tree_For_C_Lan_H

typedef int ElementType;
struct Node;

typedef struct Node* PtrToNode;
typedef PtrToNode Tree;
typedef PtrToNode Position;

struct Node
{
    ElementType data;
    Position Left;
    Position Right;
};

Tree CreateBST(ElementType input);

Position Find(Tree T, ElementType input);

Tree Insert(Tree T, ElementType input);
Tree Delete(Tree T, ElementType input);

void Print_PreOrder(Tree T);
void Print_InOrder(Tree T);
void Print_PostOrder(Tree T);
#endif