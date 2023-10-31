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

/*Init List Start*/

LinkedList HeadInsert(LinkedList &List)
{
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
        NewNode = (LNode*)malloc(sizeof(LNode));
        NewNode->data = i;
        RearNode->Next = NewNode;
        RearNode = NewNode;
        scanf("%d",&i);
    }
    return List;
}

/*Init List Done*/


/*Three different ways to insert New Node*/

// 1.Insert by position
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

    // 2&3 actually could replace this part
    // by using InsertNextNode(TempPointer,NewData);
    LNode *NewNode = (LNode *)malloc(sizeof(LNode));
    NewNode->data = NewData;
    NewNode->Next = TempPointer->Next;
    TempPointer->Next = NewNode;

    return true;
}

// 2.Insert after a specific Node "p"
bool InsertNextNode(LNode *p,ElemType NewData)
{
    LNode *NewNode = (LNode *)malloc(sizeof(LNode));
    if ((p == NULL) || (NewNode == NULL))
    {
        return false;
    }
    NewNode->data = NewData;
    NewNode->Next = p->Next;
    p->Next = NewNode;
    return true;
}

// 3. Insert before a Node "p"
//But the question is we don't have the address of p's prior Node
//One way is to give the HeadNode then traversal to find the prior Node, which is slow
//The other way is to add a New Node then duplicate data of "p" to the new,
//then fill "p" with NewData,
bool InsertPriorNode(LNode* p,ElemType NewData)
{
    LNode *NewNode = (LNode *)malloc(sizeof(LNode));
    if ((p == NULL) || (NewNode == NULL))
    {
        return false;
    }
    NewNode->data = p->data;
    NewNode->Next = p->Next;
    p->data = NewData;
    p->Next = NewNode;
    return true;
}

/*Insert Done*/

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
