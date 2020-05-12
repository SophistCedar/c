#include <stdio.h>

void change(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a = 5;
    int b = 3;
    change(&a,&b);
    printf("num of a:%d\n",a);
    printf("num of b:%d\n",b);
    printf("hello world!\n");
    return 0;
}