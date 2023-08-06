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

//As it looks,we use this function to find data by value
//this function is easy,just loop the list,test every data,
//see if it euqals to what you are looking for
//well,this is the most stupid way to search,
//but in the future we will make some improvement
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

//This function is used to get data for a specific location
//so first things first,we need to judge the location to see whether is's legal
//then give back the data of the location if it exist
//give a NULL back if it does't exist
ElemType FindByNum(SqList L,int location)
{
    int i = location;
    //legal postion equals to [1,L.length-1]
    if(i>=1 || i<=L.length-1)
    {
        return L.data[i-1];
    }
    return 0;
}

int main()
{
    SqList L1;
    L1.length = 3;
    L1.data[0] = 1;
    L1.data[1] = 2;
    L1.data[2] = 3;
    //FindByValue(L1,2);
    int ret = FindByNum(L1,1);
    printf("%d",ret);
}
