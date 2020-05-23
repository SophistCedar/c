#include <stdlib.h> 
#include <stdio.h>

//声明一个链表节点
//包括用户数据和指向下一个节点的指针
struct weapon{
  int price;
  int atk;
  struct weapon *next;
};

//定义一个创建链表的函数，返回值是链表元素头指针
//头指针，当前创建的节点，上一个节点
struct weapon * create(){
  //三个指针变量，头指针，新创建的节点，上一个节点
  struct weapon * head;//链表元素的头指针
  struct weapon * p1, * p2;//p1指向新创建的节点，p2指向上一个节点
  int n = 0;//链表元素计数
  //分配堆区内存空间
  p1 = p2 = (struct weapon*)malloc(sizeof(struct weapon));
  
  //输入p1的用户数据
  scanf("%d,%d",&p1->price,&p1->atk);
  head = NULL;//此时链表为空
  
  //动态链表结束的条件
  while(p1->price != 0){
    n++;//链表元素个数加1
    if(n==1) head = p1;//如果是第一个元素，将head指向新创建的节点
    else p2->next = p1;//不是第一个元素，将上一个节点指向新创建的节点
    p2 = p1;//p1赋值p2，保留新创建的节点
    //重新创建节点
    p1 = (struct weapon*)malloc(sizeof(struct weapon));//开辟新内存空间再次输入
    scanf("%d,%d",&p1->price,&p1->atk);
    //判断是否链表结束
    //不结束的话，将上一个节点指向新创建的节点，并保留新创建的节点
  }
  p2->next = NULL;//链表最后一个元素指向下一个节点的地址为空指针
  return (head);//返回链表头指针
}


int main(){
  struct weapon *p;
  p = create();
  printf("output first element in link\n");
  printf("%d,%d\n",p->price,p->atk);
  return 0;
}
