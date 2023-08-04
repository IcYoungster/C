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

int main()
{
    SqList L1;
    L1.length = 3;
    L1.data[0] = 1;
    L1.data[1] = 2;
    L1.data[2] = 3;
    PrintList(L1);
    //this is way much better and elegant codes
}
