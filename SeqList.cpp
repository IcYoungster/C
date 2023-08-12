#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 50
typedef int ElemType;
typedef struct{
    ElemType data[MAXSIZE];
    int length;
}SqList;

//the upper one was good, but as we reached the MAXSIZE,we could never fill a single data into it
//but Dynamic SeqList, which allows us to add the maxsize of list freely
#define InitSize 10//define the dynamic list first size of data
typedef struct{
    ElemType *data;//this pointer pointed to the first data of the list, aka address
    int MaxSize;
    int length;//record recent length
}DySeqList;
//so how to apply for a space dynamically?
//C language use the key word "malloc" to apply and the "free" to give space back

void DyInitList(DySeqList &DL)
{
    //malloc give back a pointer,so we need to trans with force
    //the space we need is euqals to = size(number) * size of type
    DL.data = (ElemType*)malloc(InitSize*sizeof(ElemType));
    DL.length = 0;
    DL.MaxSize = InitSize;
}

//add a function to increase the lenth of Dynamic Seqlist
//main idea is to create a new list with extra length,
//then swap all the data to the new list, delete the old one in the end
//followed with few steps:
//1.define a pointer pointed to DL.data,this pointer is a temporary container
//2.apply more space for "DL.data" List
//3.swap data one by one from that temp pointer to our new "DL.data"
//4.change the params like length and maxsize.
//5.free temp pointer,which actually freed the space pointed to
void IncreaseSize(DySeqList &DL,int length)
{
    ElemType *TempPointer = DL.data;
    DL.data = (ElemType*)malloc((InitSize+length)*(sizeof(ElemType)));
    for(int i=0;i <= InitSize;i++)
    {
        DL.data[i] = TempPointer[i];
    }
    DL.length += length;
    DL.MaxSize += length;
    free(TempPointer);
}

void InitList(SqList &L)
{
    int i = 0;
    for (int i = 0; i < MAXSIZE; i++)
    {
        L.data[i] = 0;
    }
    L.length = 0;
}

void PrintList(SqList L)
{
    int i=0;
    for(;i<L.length;i++)
    {
        printf("%-3d",L.data[i]);
    }
}

void PrintDyList(DySeqList DL)
{
    for(int i=0;i<DL.length;i++)
    {
        printf("%-3d",DL.data[i]);
    }
}

int Insert(SqList& L, int position, ElemType NewData)
{
    int i = position;
    if(L.length == MAXSIZE)
    {
        printf("Insert Failed.List Full");
        return false;
    }
    if (i <= L.length+1 || i >= 1)
    {
        int j = L.length;
        L.length += 1;
        for (; j >= i; j--)
        {
            L.data[j] = L.data[j - 1];
        }
        L.data[i - 1] = NewData;
    }
    return 0;
}

void Delete(SqList& L,int position)
{
    int i = position;
    if (i <= L.length - 1 || i >= 1) 
    {
        for (int j = i - 1; j <= L.length - 1; j++)
        {
            L.data[j] = L.data[j + 1];
        }
        L.length -= 1;
    }
}

void FindByValue(SqList L, ElemType Data)
{
    for (int j = 0; j < L.length; j++)
    {
        if (L.data[j] == Data)
        {
            printf("The number is %d in the list",j+1);
            break;
        }
    }
}

ElemType FindByNum(SqList L,int location)
{
    int i = location;
    if(i>=1 || i<=L.length-1)
    {
        return L.data[i-1];
    }
    return 0;
}

int main()
{
    //SqList L1 = {{1,1,1},3}; could like this,but don't initial
    SqList L1;
    DySeqList L2;
    InitList(L1);
    DyInitList(L2);
    L1.length = 3;
    L2.length = 3;
    L1.data[0] = 1;
    L1.data[1] = 1;
    L1.data[2] = 1;
    L2.data[0] = 9;
    L2.data[1] = 9;
    L2.data[2] = 9;
    PrintList(L1);
    printf("\n");
    PrintDyList(L2);
    printf("\n");
    IncreaseSize(L2,3);
    PrintDyList(L2);
}
