#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 50
typedef int ElemType;
typedef struct{
    ElemType data[MAXSIZE];
    int length;
}SqList;

#define InitSize 10
typedef struct{
    ElemType *data;
    int MaxSize;
    int length;
}DySeqList;

void DyInitList(DySeqList &DL)
{
    DL.data = (ElemType*)malloc(InitSize*sizeof(ElemType));
    DL.length = 0;
    DL.MaxSize = InitSize;
}

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

bool Delete(SqList& L,int position, ElemType &DelData)
{
    int i = position;
    bool ret = false;//ret var is for record the state of return value
    DelData = (ElemType)L.data[i];//take DelData back
    if (i <= L.length - 1 || i >= 1) 
    {
        for (int j = i - 1; j <= L.length - 1; j++)
        {
            L.data[j] = L.data[j + 1];
        }
        L.length -= 1;
        ret = true;
        //could just return the DelData here
        //printf("Delete succeed! it's No.%d,%d\n",i,DelData);
    }else{
        ret = false;
    }
    return ret;
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
    SqList L1;
    DySeqList L2;
    InitList(L1);
    DyInitList(L2);
    L1.length = 3;
    L2.length = 3;
    L1.data[0] = 1;
    L1.data[1] = 1;
    L1.data[2] = 1;
    int e = -1;
    Delete(L1,2,e);
    printf("删除的元素是%d\n",e);
    PrintList(L1);
    }
