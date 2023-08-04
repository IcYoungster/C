#include<stdio.h>
#define MAXSIZE 50
typedef int ElemType;
//use struct to accomplish SeqList,ofcourse we could also use sth else
typedef struct{
    ElemType data[MAXSIZE];
    int length;
}SqList;

int main()
{
    //create a varible of SeqList,you don't have to give a class name when it is a struct varible
    //And i decide to call it "L1",then i set it's length to 3,so we got a SeqList with 3 data
    //then give them number like "1、2、3",don't forget their class name "data"
    SqList L1;
    L1.length = 3;
    L1.data[0] = 1;
    L1.data[1] = 2;
    L1.data[2] = 3;
    printf("%d %d %d",L1.data[0],L1.data[1],L1.data[2]);
    //this is so called"give and take",give them data,then print them all
}
