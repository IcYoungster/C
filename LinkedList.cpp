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

void PrintList(LinkedList List)
{
    LNode* P;
    P = List->Next;
    while (P != NULL)
    {
        printf("%d\n", P->data);
        P = P->Next;
    }
}

bool Insert(LinkedList &List, ElemType NewData, int position)
{
    int p = position;
    int i = 0;
    LNode *TempPointer;
    TempPointer = List;

    while ( i < p - 1)
    {
        TempPointer = TempPointer->Next;
        i++;
    }

    LNode *NewNode = (LNode *)malloc(sizeof(LNode));
    NewNode->data = NewData;
    NewNode->Next = TempPointer->Next;
    TempPointer->Next = NewNode;

    return true;
}

// define a function to build LinkedList from scratch,
// it conprised with initial and add new data Node,
// which would help us when there are plenties of Data

// There are two different ways to insert elements in the Linked List
// 1.Insert new Node after Head Node of the list, name the function as HeadInsert
    // To add a new Node after the HeadNode like this:
    // HeadPointer -> HeadNode -> NULL
    // HeadPointer -> HeadNode ->New Node 1 ->NULL
    // HeadPointer -> HeadNode ->New Node 2 ->New Node 1 ->NULL
// 2.Insert new Node after the last Node of the List,name it RearInsert
    // HeadPointer -> HeadNode -> NULL
    // HeadPointer -> HeadNode ->New Node 1 ->NULL
    // HeadPointer -> HeadNode ->New Node 1 ->New Node 2 ->NULL

LinkedList HeadInsert(LinkedList &List)
{
    // First we Create the LinkedList with HeadNode,Same with the "InitLinkedList"
    // Then Set a Number, Control the Loop, Insert the Data
    List = (LNode *)malloc(sizeof(LNode));
    List->Next = NULL;

    ElemType i = NULL;
    LNode* NewNode;
    scanf("%d",&i);
    while (i != 9999)
    {
        NewNode = (LNode*)malloc(sizeof(LNode));
        NewNode->data = i;
        NewNode->Next = List->Next;
        List->Next = NewNode;
        scanf("%d",&i);
    }
    return List;
}

//Pretty much same with HeadInsert, but add a RearNode
LinkedList RearInsert(LinkedList &List)
{
    List = (LNode *)malloc(sizeof(LNode));
    List->Next = NULL;

    ElemType i = NULL;
    
    LNode* NewNode;
    LNode* RearNode = List;//Pointed to the Rear of List
    scanf("%d",&i);
    while (i != 9999)
    {
        // Create a NewNode,Then Insert it at the end
        // At first,RearNode & List all pointed to HeadNode,
        // so RearNode->Next == HeadNode->Next
        // Then let RearNode pointed to NewNode
        NewNode = (LNode*)malloc(sizeof(LNode));
        NewNode->data = i;
        RearNode->Next = NewNode;
        RearNode = NewNode;
        scanf("%d",&i);
    }
    return List;
}

int main()
{
    // At first,we did't create a Node but only a pointer
    LinkedList L1; // Or LNode* L;
    LinkedList L2;
    // Now Initialized it,we create a Head Node for convinience
    //InitLinkedList(L);

    // Then we can fill The List with data
    // But insert Data on by one is STUPID!
    HeadInsert(L1);
    RearInsert(L2);
    PrintList(L1);
    PrintList(L2);
    return 0;
}
