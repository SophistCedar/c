#include <stdlib.h> 
#include <stdio.h>

//声明一个链表元素，每个元素都是一个节点
//每个节点包括用户数据和指向下一个节点的指针
//链表元素地址不一定是连续的
//要想访问某个元素，必须使用上一个元素提供的指向下一个元素的地址
//因此，必须先要有一个头指针，否则无法访问元素
//最后一个链表元素存放的指向下一个元素地址为空，链表结束


//声明一个链表节点
struct weapon{
  int price;
  int atk;
  struct weapon *next;
};

int main(){
  //声明三个链表元素，链表头指针
  struct weapon a,b,c,*head;
  //初始化链表元素内的数据
  a.price = 100;
  a.atk = 100;
  b.price = 200;
  b.atk = 200;
  c.price = 300;
  c.atk = 300;
  //头指针指向第一个元素
  head = &a;
  //第一个元素指向第二个元素
  a.next = &b;
  //第二个元素指向第三个元素
  b.next = &c;
  //第三个元素指向为空，链表结束
  c.next = NULL;
  
  //声明一个节点地址
  struct weapon *p;
  //头指针赋值给该节点
  p = head;
  //依次遍历链表内的元素，当指向下一个节点的地址为空时，链表结束，遍历结束
  while(p != NULL){
   //打印链表节点存放的用户数据
   printf("%d,%d\n",p->price,p->atk);
   //将节点地址指向下一个节点的地址
   p = p->next;
  
  }
  return 0;
   

}
