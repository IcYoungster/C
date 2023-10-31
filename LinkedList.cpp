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

/*Delete Nodes*/

//Find and Delete,if delete No.p,find p-1,link (p-1) to (p+1),then free p
bool DeleteByPosition(LinkedList &List,int position,ElemType &DeletedData)
{
    //List with HeadNode so can't delete The First Node

    //Using a TempPointer to Travesal and Manipulate the list
    //Using pointer "Delete" to show which Node should be deleted

    if(position<1){return false;}
    LNode* Temp,*Delete;

    // 1.Find
    // Create a index to show where the "Temp" is.Then Traversal the List
    int i = 0;
    Temp = List;
    while (i < position - 1)
    {
        Temp = Temp->Next;
        i++;
    }

    // 2.Delete
    
    //Edge consideration
    if(Temp == NULL || Temp->Next == NULL)
    {return false;}

    Delete = Temp->Next;
    DeletedData = Delete->data;
    Temp->Next = Delete->Next;
    free(Delete);

    return true;
}

//can't directly modifying the prior Node->next to free p,
//so exchange data with the next one,then release the next one
//but if p is the last of List,it will not work, need to know the HeadNode's address
bool DeleteNode(LNode*p)
{
    if(p == NULL){return false;}

    LNode* Deleted = p->Next;
    p->data = p->Next->data;//or just Deleted->data
    p->Next = Deleted->Next;
    free(Deleted);
    return true;
}

int main()
{
    // At first,we did't create a Node but only a pointer
    LinkedList L1; // Or LNode* L;
    LinkedList L2;
    // Now Initialized it,we create a Head Node for convinience
    //InitLinkedList(L);

    HeadInsert(L1);
    RearInsert(L2);
    PrintList(L1);
    PrintList(L2);
    return 0;
}
