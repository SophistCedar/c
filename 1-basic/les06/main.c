#include <stdio.h>

//指针/变量地址 作函数参数
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//变量作函数参数，无法成功交换
void try_change(int c, int d){
    int tmp = c;
    c = d;
    d = tmp;
}

int main()
{
    //交换成功
    int a = 5;
    int b = 3;
    swap(&a,&b);
    printf("num of a:%d\n",a);
    printf("num of b:%d\n",b);

    //交换失败
    int c = 5;
    int d = 3;
    try_change(c,d);
    printf("num of c:%d\n",c);
    printf("num of d:%d\n",d);

    printf("hello world!\n");
    return 0;
}