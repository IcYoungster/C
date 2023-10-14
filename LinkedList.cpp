#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
//LNode = Linked List Node
//each Node contains two part:the data and address of the next node
//To save next node address, we need use struct itself to complete this
//so we use another node type to save address - which is *Next
typedef struct LNode{
    ElemType data;
    struct LNode *Next;
}LNode,*LinkedList;//rename it.The two name are the same
//the first name infers it's a Node, but the second one stressed on List

//Initial Function with return value
bool InitLinkedList(LinkedList &List)
{
    //so first we better create a Head Node for convenience,
    //we need to apply a block of space in memory by using function malloc(),
    //Then change it's type to LNode*
    List = (LNode*)malloc(sizeof(LNode));
    
    //if there is no space to arrange, it will return false
    if(List == NULL){return false;}
    
    //then let our List pointed to the Head Node
    //Now the list's logic like this: |List|->|Head Node|->|NULL|
    List->Next = NULL;
    return true;
}

int main()
{
    LinkedList L;//Or LNode* L;
    InitLinkedList(L);
    return 0;
}
