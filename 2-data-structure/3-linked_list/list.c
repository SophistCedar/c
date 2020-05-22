#include <assert.h>// void assert(int expression)
#include <stddef.h>// NULL
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>//va_list va_start() va_arg() va_end()
#include "list.h"

#define L List_T

/* Initial list */
//链表的每个节点定义为指向结构体的指针，该结构体包括用户数据和指向下一个节点的指针
L List_init (void) {
    L list;//定义指向结构体的指针
    list = (L) malloc(sizeof(L));//分配堆内存
    list->next = NULL;//指向的下一个节点地址为空，链表到此结束，相当于建立了一个节点的链表，没有头指针
    return list;
}

/* Push an element into top of the list */
//在列表首部插入一个节点，将输入的数据构造成一个节点，将这个节点指向原来列表的头节点，返回新列表的头节点
L List_push(L list, void *val) {
    L new_elem = (L)malloc(sizeof(L));//分配堆内存
    new_elem->val = val;//赋值用户数据
    new_elem->next = list;//指向链表第一个节点，list指的是第一个节点的地址，也是第一个节点内用户数据的地址
    return new_elem;//返回插入的节点
}

/* Length of list */
//先计数头节点，依次判断每个节点的指向，如果是 NULL 说明到了最后一个节点的指向
int List_length(L list) {
    int n;
    for(n = 0; list; list=list->next)//当 list = list->next = NULL 的时候循环终止，最后一个节点的指向 NULL
        n++;
    return n;
}

/* Convert list to array */
//数组内存放用户数据，用户数据是一个 void* 类型指针
//返回数组首元素地址，是一个二级指针，充当数组名的作用
void **List_toArray(L list) {
    int i, n = List_length(list);//获得链表节点个数
    void **array = (void **)malloc((n+1) *sizeof(*array));
    //链表最后一个节点指向 NULL，所以数组最后一个元素放 NULL，所以需要 n+1

    for(i = 0; i < n; i++) {
        array[i] = list->val;//给数组元素赋值
        list = list->next;//指向下一个节点
    }
    array[i] = NULL;//数组最后一个元素
    return array;//返回数组首元素的地址，返回数组名称
}

/* Create and return a list */
// 可变参数的函数通在参数列表的末尾是使用省略号(,...)定义
L List_list(L list, void *val, ...) {
    //申请参数列表变量ap， va_list 是一个适用于 va_start()、va_arg() 和 va_end() 这三个宏存储信息的类型。
    va_list ap;
    L *p = &list;//p是一个指向结构体的二级指针，指向链表头节点（每个节点是指向结构体的指针），
    //void va_start(va_list ap, last_arg)
    //这个宏初始化 ap 变量，它与 va_arg 和 va_end 宏是一起使用的。last_arg 是最后一个传递给函数的已知的固定参数，即省略号之前的参数。
    //初始化 ap 变量，val 是最后一个传递给函数的已知的固定参数
    va_start(ap, val);
    //type va_arg(va_list ap, type), 这个宏检索函数参数列表中类型为 type 的下一个参数。
    //依次读取固定参数 val 后的 void* 类型参数
    for(; val; val = va_arg(ap, void *)) {
        //将输入的数据构造成一个节点，第一次循环的时候是头节点创建
        *p = malloc(sizeof(L));//分配链表节点的内存空间
        (*p)->val = val;//链表节点内的用户内容赋值
        p = &(*p)->next;//节点后移，指向下一个节点
    }
    *p = NULL;//最后一个节点为空
    //void va_end(va_list ap)
    //这个宏允许使用了 va_start 宏的带有可变参数的函数返回。如果在从函数返回之前没有调用 va_end，则结果为未定义。
    va_end(ap);
    return list;//返回指向链表第一个节点的指针
}

/* Append 2 lists together */
// 此处需要遍历到 list 的最后一个节点，令那个节点存放的指针指向 tail 的第一个节点即可
L List_append(L list, L tail) {
    // list 是一个指向结构体的指针
    L *p = &list;// *p 是头节点，p指向头节点
    // *p 看作是一个节点， p 看作一个节点的指针
    //依次遍历节点的指向，直至找到最后一个指向 NULL 的最后一个节点，循环结束
    while((*p)->next) {
        p = &(*p)->next;
        //当此处循环到最后一个节点的时候，经过赋值，此时 p 最后一个节点内存放的指向指针，为 NULL，
        //最后一个节点指向的节点表示为 *p
    }
    // p 是最后一个节点内保留的指针， *p 指的是最后一个节点的指向节点，*p 内的两个成员都是 NULL
    // tail 是一个指向结构体的指针，表示 tail 的第一个节点
    // 把 tail 的第一个节点放到 list 的最后一个节点的指向节点，这就完成了连接
    *p = tail;//链表名称代表的是第一个节点的地址，也就是第一个节点用户数据的地址

    // (*p)->val = tail->val;
    // (*p)->next = tail->next;
    // printf("%p\n",tail);//链表名称代表的是第一个节点用户数据的地址
    // printf("%p\n",&tail->val);//结构体成员全部为指针变量省去了结构体内存对齐的问题，都是4/8字节
    // printf("%p\n",&tail->next);
    // printf("%d\n",(int)sizeof(void*));//64位系统指针变量字节为8，32位是4字节，16位是2字节
    // printf("%p\n",tail->val);//此处的用户数据是字符串，字符串被存储在常量区
    // printf("%p\n",tail->next);//指向下一个节点的指针分配在堆区，导致结构体内的成员在内存中是不连续的
    // printf("%p\n",&list);//栈区的地址，向下生长
    // printf("%p\n",&tail);

    return list;
}

