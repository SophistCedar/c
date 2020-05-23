/*
    author: Christian Bender
    This is the implementation of the (generic) stack.
    The implementation uses the dynamic memory management and the principle
    of data hiding.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"

/* 
   actual stack data structure
   This pointer will pointing at the actual field (of void * pointers) 
   that represents the stack.
 */
//使用数组实现栈结构，数组内的元素类型是 void* 类型，array相当于数组名称
void **array;

/* the current capacity of the stack */
//栈的当下容量
int max = 10;

/* counter variable for counting the elements of the stack. */
//计数栈内的元素
int counter = 0;

/* 
    offset address 
    points at the top element of the stack.
*/
//设定一个实时指向栈顶元素的变量（一般命名为 top），top 初始值为 -1，
//表示栈中没有存储任何数据元素，即栈是"空栈"。
//一旦有数据元素进栈，则 top 就做 +1 操作；反之，如果数据元素出栈，top 就做 -1 操作。
int offset = -1;//指向栈顶元素

//初始化栈，容量为10
void initStack()
{
    array = malloc(sizeof(void *) * max);
    assert(array); /* tests whether pointer is assigned to memory. */
}

/*
    grow: increases the stack by 10 elements.
          This utility function isn't part of the public interface
*/
//栈的容量扩大十个，本质上说是不允许的，因为栈顶地址是确定的，栈的容量大小是确定的
void  grow()
{
    max += 10; /* increases the capacity */
    //重新分配堆内存
    void **tmp = malloc(sizeof(void *) * max);

    int i; // for the loop
    /* copies the elements from the origin array in the new one. */
    for (i = 0; i < max - 10; i++)
    {
        *(tmp + i) = *(array + i);
    }
    /*free the original memory */
    free(array);
    //扩大后的栈赋值给array
    array = tmp;  
}

/* push: pushs the argument onto the stack */
//在栈顶增加元素
void push(void *object)
{
    assert(object); /* tests whether pointer isn't null */
    if (counter < max)//判断元素个数是否超过容量
    {
        offset++; /* increases the element-pointer */
        /* 
            moves pointer by the offset address 
            pushs the object onto stack 
         */
        *(array + offset) = object;//元素入栈

        /* increases the inner counter */
        counter++;
    }
    else /* stack is full */
    {
        grow(); /* lets grow stack */
        push(object); /* recursive call */
    }
}

/*
    pop: pops the top element of the stack from the stack.
*/
//删除栈顶元素
void *pop()
{
    void *top = *(array + offset);
    /* check pointers */
    assert(top);
    /* if use the pop-function, stack must not empty. */
    assert(!isEmpty());
    /* decreases the offset address for pointing of
        the new top element */
    offset--;
    /* decreases the inner counter */
    counter--;
    return top;
}

/*
    size: gets the number of elements of the stack.
*/
int size()
{
    return counter;
}

/*
    isEmpty(): returns 1 if stack is empty otherwise 0.
*/
int isEmpty()
{
    return counter == 0;
}

/*
    top: returns the top element from the stack without removing it.
*/
//查看栈顶元素
void *top()
{
    /* offset address points to the top element */
    //array是指向指针数组的二级指针，可以充当数组名称使用，这里等价于*(array+offset)
    return array[offset];
}
