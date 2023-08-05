#include<stdio.h>
#define MAXSIZE 50
typedef int ElemType;
typedef struct{
    ElemType data[MAXSIZE];
    int length;
}SqList;

void PrintList(SqList L)
{
    int i=0;
    for(;i<L.length;i++)
    {
        printf("%-3d",L.data[i]);
    }
}
int Insert(SqList& L, int position, ElemType NewData)
{
    int i = position;
    
    //if List length equals MAXSIZE, we can't Insert too... Sad,is't it?
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

int main()
{
    //Test
    SqList L1,L2;
    L1.length = 3;
    L2.length = 49;
    L1.data[0] = 1;
    L1.data[1] = 2;
    L1.data[2] = 3;
    L2.data[49]= 0;
    Insert(L1,4,9);
    Insert(L2,50,9);
    PrintList(L1);
    printf("\n");
    PrintList(L2);
}
