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

//The first pramas enquires a "&" than the PrintList Function
//which is referance,that could make you directly manipulate
//the data inside the struct
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

//whay if i type data wrong?well i definitely need to delete it or replace it.
//so here comes the Delete Function to help us
void Delete(SqList& L,int position)
{
    int i = position;
    //so delete is simply reverse of the Insert
    //first we need to make sure it's legal to remove that data
    //then we locate the data we need to remove
    //then delete it,but still need to change the length of the List
    //also,we need to swap them to fill the blank
    if (i <= L.length - 1 || i >= 1) // legal position is [1,length-1]
    {
        int j = i - 1;//the param j equals the Array index
        L.data[j] = 0;//actually you don't even need this,but just for safety
        for (; j <= L.length - 1; j++)//swap till j equals last of Array index
        {
            L.data[j] = L.data[j + 1];
        }
        L.length -= 1;
    }
}

int main()
{
    SqList L1;
    L1.length = 3;
    L1.data[0] = 1;
    L1.data[1] = 2;
    L1.data[2] = 3;
    Insert(L1,4,9);
    PrintList(L1);
    printf("\n");
    Delete(L1,4);
    PrintList(L1);
}
