#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode
{
    ElemType data;
    struct LNode *Next;
} LNode, *LinkedList;
bool InitLinkedList(LinkedList &List)
{
    List = (LNode *)malloc(sizeof(LNode));
    if (List == NULL)
    {
        return false;
    }
    List->Next = NULL;
    return true;
}

//Print The LinkedList
void PrintList(LinkedList List)
{
    //Create a Pointer to Traversal the list
    //Give the HeadNode's address to Pointer
    //Then Print every Node's data,quit when the "Node->Next" is NULL
    LNode* P;
    P = List->Next;
    while (P != NULL)
    {
        printf("%d\n", P->data);
        P = P->Next;
    }
}

// How to Insert a NewNode into our LinkedList?
// if we already got a List with 3 Nodes,now we want insert one NewNode as second Node,
// The params will be (1.List 2.Data 3.Insert Position)->(L,D,2)
// p.s. The Node will be create inside the function

// so in this function needs two steps:
// 1.Find the position
// 2.Insert NewNode
bool Insert(LinkedList &List, ElemType NewData, int position)
{
    // Step1:Find the position,we need to Traversal the list
    // 1.Create a temp pointer for locate & get address of Node
    // 2.Give the address of HeadNode to TempPointer
    // 3.Use index to show where the TempPointer is, also, as a index of loop
    // 4.Traversal the List
    int p = position;
    int i = 0;
    LNode *TempPointer;
    TempPointer = List;

    while ( i < p - 1)
    {
        TempPointer = TempPointer->Next;
        i++;
    }

    // Step2:Insert NewNode
    // 1.Create a NewNode
    // 2.Give NewData to NewNode's data
    // 3.Give Next Nodes' address to NewNode's next
    //(Now NewNode's next& Pointer's next = NextNode's address)
    // 4.Give NewNode's address to Pointer's next
    LNode *NewNode = (LNode *)malloc(sizeof(LNode));
    NewNode->data = NewData;
    NewNode->Next = TempPointer->Next;
    TempPointer->Next = NewNode;

    return true;
}
int main()
{
    // At first,we did't create a Node but only a pointer
    LinkedList L; // Or LNode* L;

    // Now Initialized it,we create a Head Node for convinience
    InitLinkedList(L);

    // Then we can fill The List with data
    Insert(L, 666, 1);
    Insert(L, 2, 2);
    Insert(L, 3, 3);
    PrintList(L);
    return 0;
}
