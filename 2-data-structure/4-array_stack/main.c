#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
extern void **array;
extern int max;
extern int counter;
extern int offset;//指向栈顶元素

int main() {
    initStack();//初始化
    
    //向栈顶增加元素
    push((int *) 2);
    push((int *) 1);
    push((int *) 3);
    push((int *) 4);

    //栈内元素个数，栈顶元素
    printf("Size: %d\n", size());
    printf("Stack top element: %p\n",(int*)top());

    //删除栈顶元素
    printf("Stack popping element:%p \n",(int*)pop());
    printf("Stack after popping,");
    printf("Stack top element: %p\n",(int*)top());

    printf("Stack popping element:%p \n",(int*)pop());
    printf("Stack after popping,");
    printf("Stack top element: %p\n",(int*)top());

    return 0;
}
