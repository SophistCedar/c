#include <stdio.h>
#define MAXSIZE 10

//使用数组实现队列结构
//队列尺寸必须是固定的，所以在首尾处需要特殊处理，也可以通过动态数组实现队列的自扩充
//如果不断的向队列内增加元素，终究rear会超过MAXSIZE，
//如果到达临界点，但是先入队的元素出队了，后入队的元素可以从“队首”继续入队，rear = 0
//如果达到临界点，并且先入队的元素没有出队，即队列元素已满，则无法继续插入元素
//可以考虑使用动态数组来完成队列数量自动增加
int queue[MAXSIZE];

int front = -1;//指向队首
int rear = -1;//指向队尾
int size = -1;

int isempty()
{
    return size<0;
}

int isfull()
{
    return size == MAXSIZE;
}
//队尾插入
void enqueue(int value)
{
    if(size<MAXSIZE)
    {
        if(size<0)//第一次插入元素的时候
        {
            queue[0] = value;
            front = rear = 0;
            size = 1;
        }
        else if(rear == MAXSIZE-1)
        //这个时候如果rear到了边界，但是先入队的元素已经出队了（size满足条件）
        //就在 0 的位置开始重新开始入队，rear的位置开始重新计数
        {
            queue[0] = value;
            rear = 0;
            size++;
        }
        else
        {
            queue[rear+1] = value;//最后 rear = 8，queue[9] 的时候，此时rear++后 rear 变成 9
            rear++;
            size++;
        }
    }
    else
    {
        printf("Queue is full\n");
    }
}
//元素出队，个数减1，指向队首的指针后移一位
void dequeue()
{
    if(size<0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        size--;
        front++;
    }
}

int Front()
{
    return queue[front];
}

void display()
{
    int i;
    if(rear>=front)//当rear到达MAXSIZE，并且队首的元素出队了，rear=0 重新开始
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d\n",queue[i]);
        }
    }
    else
    {
        for(i=front;i<MAXSIZE;i++)
        {
            printf("%d\n",queue[i]);
        }
        for(i=0;i<=rear;i++)
        {
            printf("%d\n",queue[i]);
        }
    }
}

int main()
{
    for(int i=0;i<4;i++){
        enqueue(i);
    }
    display();
    dequeue();
    printf("After dequeue\n");
    display();
    dequeue();
    printf("After dequeue\n");
    display();
    return 0;
}