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

//what if i wanna more data but i don't want to 
//type it mannually? Here comes the function INSERT

//Why int?not VOID?because we need to know whether
//it's worked or not.so if succeed,give us back with a "1",if not,just return "-1"

//need to notify 
//1. what List i will insert,
//2. the position  
//3. the data type and the data
int Insert(SqList& L, int position, ElemType NewData)
{
    int i = position;
    //valid position range equals to [1,length+1]
    //example:if there is a line with 3 people
    //you coule insert in No.1~No.4 
    if (i > L.length+1 || i < 1)
    {
        printf("Insert failed!");
        return -1;
    }
    else
    {
        //so basically you need to add one length
        //then swap data one by one form rear to head
        int j = L.length;//this param is set first for record the origin length of SeqList,
                         //basically equals the last one of the origin List
        L.length += 1;

        //so if the origin last larger than insert position,
        //we have to swap them form rear to head
        for (; j >= i; j--)
        {
            L.data[j] = L.data[j - 1];
        }
        L.data[i - 1] = NewData;
        return 0;
    }
}

int main()
{
    SqList L1;
    L1.length = 3;
    L1.data[0] = 1;
    L1.data[1] = 2;
    L1.data[2] = 3;
    Insert(L1,4,6);
    PrintList(L1);
}
