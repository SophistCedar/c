#include <assert.h>
#include <stddef.h>//NULL
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

#define T Stack_T

//使用链表实现栈结构，思路是定义一个结构体，结构体内包括节点个数，和头节点
//使用节点来存放栈数据结构内的数据，数据出栈相当于头节点后移；
//数据入栈，先把数据构造成一个节点，令这个节点指向当前头节点，头节点再前移


//使用链表实现stack数据结构，此处定义一个节点
typedef struct elem {
    void *val;
    struct elem *next;
} elem_t;
//定义一个结构体，包括一个整形count变量用于计数，以及指向一个链表节点的指针
//该节点用于存放栈顶元素，每次增加元素就将元素转化为节点指向栈顶元素，删除栈顶元素就删除第一个节点
//访问栈顶元素，就访问第一个节点内存放的用户数据
struct T {
    int count;
    elem_t *head;
};

/* Initial stack */
T Stack_init (void) {
    T stack;//定义一个栈数据结构
    stack = (T) malloc(sizeof(T));//分配堆内存空间
    stack->count = 0;//计数为0
    stack->head = NULL;//指向为空，现在还没有节点，相当于头指针，且头指针为 NULL
    return stack;//返回stack
}

/* Check empty stack*/
int Stack_empty(T stack) {
    assert(stack);//加上assert
    return stack->count == 0;
}

/* Return size of the stack */
int Stack_size(T stack) {
    assert(stack);
    return stack->count;
}

/* Push an element into the stack */
void Stack_push(T stack, void *val) {
    assert(stack);
    //把插入的元素构造成一个节点，该节点内的指针指向栈顶元素所在的节点
    elem_t *t;
    t = (elem_t *) malloc(sizeof(elem_t));
    t->val = val;
    t->next = stack->head;//指向stack内原先栈顶所在的节点

    stack->head = t;//更改栈顶节点，将构造的节点赋值给原先的节点
    stack->count++;//元素个数 +1
}

/* Pop an element out of the stack */
void *Stack_pop(T stack) {
    assert(stack);
    assert(stack->count > 0);

    void *val;//删除的元素
    elem_t *t;//对应的节点
    t = stack->head;//提取stack内的栈顶元素所在的头节点
    val = t->val;//提取栈顶元素

    stack->head = t->next;//更改栈顶元素所在节点为下一个
    stack->count--;//元素个数减少 1

    free(t);//释放原来栈顶元素所在节点占用的堆内存空间
    return val;
}

/* Print all elements in the stack */
//此处也可以实现只打印栈顶元素，为方便起见，打印全部元素
void Stack_print(Stack_T stack) {
    assert(stack);

    int i, size = Stack_size(stack);
    elem_t *current_elem = stack->head;//头节点
    printf("Stack [Top --- Bottom]: ");
    for(i = 0; i < size; i++) {
        printf("%p ", (int *)current_elem->val);//第一次循环时，打印头节点内的用户数据，即栈顶元素
        current_elem = current_elem->next;//转变到下一个节点
    }
    printf("\n");
}
