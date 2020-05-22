#ifndef __LIST__
#define __LIST__

#define L List_T//为 L 起别名
typedef struct L* L;//此处 L 指的是 struct L 的指针类型数据

//链表每个元素可以看作是一个节点，每个节点包括用户数据和指向下一个节点的指针
struct L {
    void *val;//用户自身数据
    L next;//指向下一个节点的指针，此处 L 等价于 struct L *
};
//链表初始化，返回指向头节点的指针
extern      L List_init(void);
//链表增加元素，每次在头部增加节点，因为想要在尾部增加节点，需要先遍历到最后一个节点，会耗费时间，链表只支持顺序访问
//返回指向新增加的头节点
extern      L List_push(L list, void *val);
//获取链表长度，查看有多少个节点（元素）
extern int    List_length(L list);
//链表转换为数组，数组内放 void* 类型的数据，返回数组元素的首地址
extern void **List_toArray(L list);
//一个链表增加到另一个链表后
extern      L List_append(L list, L tail);
//用可变参数生成链表，可同时输入多个参数初始化列表
extern      L List_list(L list, void *val, ...);
/* TODO */
extern      L List_copy(L list);
extern int    List_pop(L *list);

#undef L
#endif
