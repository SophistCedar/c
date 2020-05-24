#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

#define T Queue_T

//初始化的时候 front = rear = NULL
//增加第一个元素的时候 front = rear = temp，此时front和rear指向同一个节点
//增加元素在rear后面增加，删除元素在front位置删除，这样就实现了整个链表完成queue结构

//使用链表构造队列结构，先定义元素节点
typedef struct elem {
    void *val;
    struct elem *next;
} elem_t;
//队列内存放元素数量，队列内元素放在节点内，有两个指向队首和队尾节点的指针
struct T {
    int count;
    elem_t *front;
    elem_t *rear;
};

/* Initial queue */
//初始化的时候队列首尾指针为 NULL，元素数量为0
T Queue_init (void) {
    T queue;//定义一个栈数据结构
    queue = (T) malloc(sizeof(T));//分配堆内存空间
    queue->count = 0;//计数为0
    queue->front = NULL;//指向为空，现在还没有节点，相当于头指针，且头指针为 NULL
    queue->rear = NULL;
    return queue;//返回queue
}

/* Check empty queue*/
int Queue_empty(T queue) {
    assert(queue);//加上assert
    return queue->count == 0;
}

/* Return size of the queue */
int Queue_size(T queue) {
    assert(queue);
    return queue->count;
}

/* Push an element into the queue */
void Queue_push(T queue, void *val) {
    assert(queue);
    //把插入的元素构造成一个节点，添加到队尾
    elem_t *t;
    t = (elem_t *) malloc(sizeof(elem_t));
    t->val = val;
    t->next = NULL;//在队尾添加，因此加近来的就成为尾节点，指向 NULL
    if(Queue_empty(queue)){//只有当队列为空的时候才运行，第一个节点插入的时候，首尾指针均指向这个节点
        queue->front = t;
        queue->rear = t;
    }
    else{
        queue->rear->next = t;//令原来的尾节点指向 t
        queue->rear = t;//尾节点后移
    }
    
    queue->count++;//元素个数 +1
}

/* Pop an element out of the queue */
void *Queue_pop(T queue) {
    assert(queue);
    assert(queue->count > 0);//必须有元素的时候才可以删除

    void *val;//删除的元素
    elem_t *t;//对应的节点
    t = queue->front;//提取queue内的栈顶元素所在的头节点
    val = t->val;//提取栈顶元素

    queue->front = t->next;//首节点后移
    queue->count--;//元素个数减少 1

    free(t);//释放原来队首元素所在节点占用的堆内存空间
    return val;
}

/* Print all elements in the queue */
void Queue_print(Queue_T queue) {
    assert(queue);

    int i, size = Queue_size(queue);
    elem_t *current_elem = queue->front;//头节点
    printf("queue [Top --- Bottom]: ");
    for(i = 0; i < size; i++) {
        printf("%p ", (int *)current_elem->val);//第一次循环时，打印头节点内的用户数据，即队首元素
        current_elem = current_elem->next;//转变到下一个节点
    }
    printf("\n");
}
