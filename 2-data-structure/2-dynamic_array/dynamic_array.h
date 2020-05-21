#ifndef __DYNAMIC_ARRAY__
#define __DYNAMIC_ARRAY__
#define DEFAULT_CAPACITY 1 << 4//默认动态数组容量16，后面可自动扩展，每次扩大两倍
#define INDEX_OUT_OF_BOUNDS NULL

typedef struct dynamic_array {
    void **items;//二级指针，动态数组内的每个元素可以看成是一个 void * 指针，
    //items指向指针数组内首元素的地址，可以充当数组名称作用
    unsigned size;//元素个数
    unsigned capacity;//数组容量，如果元素个数超过容量就自动分配内存
} dynamic_array_t;

//初始化动态数组
extern dynamic_array_t *init_dynamic_array();
//增加元素
extern void *add(dynamic_array_t *da, const void *value);
//更改对应坐标的元素
extern void *put(dynamic_array_t *da, const void *value, unsigned index);
//查看对应坐标的元素
extern void *get(dynamic_array_t *da, const unsigned index);
//删除指定下标对应的元素
extern void delete (dynamic_array_t *da, const unsigned index);
//判断数组下标是否越界
unsigned contains(const unsigned size, const unsigned index);
//获得一个 void* 元素的副本，主要作了一个堆内存分配的工作，保证变量的生命周期
extern void *retrive_copy_of_value(const void *value);

#endif