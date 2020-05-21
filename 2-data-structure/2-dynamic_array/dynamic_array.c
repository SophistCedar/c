#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "dynamic_array.h"

//创建数组，初始化为默认容量
dynamic_array_t *init_dynamic_array()
{
    dynamic_array_t *da = malloc(sizeof(dynamic_array_t));//分配的堆内存一定要释放
    da->items = calloc(DEFAULT_CAPACITY, sizeof(void *));//在内存中动态地分配 num 个长度为 size 的连续空间，并将每一个字节都初始化为 0。
    da->capacity = DEFAULT_CAPACITY;//初始化为默认容量

    return da;
}

void *add(dynamic_array_t *da, const void *value)
{
    //如果数组元素个数超过容量，那么扩大容量至原来的两倍，重新分配存储的内存
    if (da->size >= da->capacity) {
        //重新分配内存，把内存扩展到 newsize。
        //realloc 函数功能：先判断当前指针所指是否有足够的连续空间，若足够，返回，
        //若不够，按size指定的大小分配空间，将原数据copy到新分配的内存中，然后释放原ptr所指向区域；
        void **newItems = realloc(da->items, (da->capacity <<= 1) * sizeof(void **));
        //释放 address 所指向的内存块,释放的是动态分配的内存空间。
        //free(da->items);
        //内存使用完毕后，应使用free()函数释放，但 realloc 之后原来的指针是自动释放，不需要使用free；
        //新分配的空间赋值
        da->items = newItems;
    }
    //获取输入值的副本
    void *copy_value = retrive_copy_of_value(value);
    //将输入值赋值给原数组后边界的下一个坐标位置
    da->items[da->size++] = copy_value;//da->size++先自增，对da->size++自身是有影响的
    //此处等价于 da->size++，再da->items[da->size] = copy_value;
    //返回输入值的副本
    return copy_value;
}

//替换数组内指定下标位置的元素
void *put(dynamic_array_t *da, const void *value, const unsigned index)
{
    //判断数组是否越界
    if (!contains(da->size, index))
        return INDEX_OUT_OF_BOUNDS;
    //释放原有下标的堆内存空间，retrive_copy_of_value 函数会重新分配内存空间
    free(da->items[index]);
    //获得输入值的副本，已经分配了内存空间
    void *copy_value = retrive_copy_of_value(value);
    //将输入值副本指针赋值给指定的下标位置
    da->items[index] = copy_value;
    //返回输入值的副本
    return copy_value;
}

//访问数组内下标index的元素
void *get(dynamic_array_t *da, const unsigned index)
{
    //首先判断数组是否越界
    if (!contains(da->size, index))
        return INDEX_OUT_OF_BOUNDS;
    //返回index下标对应的值
    return da->items[index];
}

//删除某个下标对应的元素，下标后的元素全部前移一位，数组个数减少 1 ，释放最后一个元素的堆内存空间
void delete (dynamic_array_t *da, const unsigned index)
{
    if (!contains(da->size, index))
        return;//数组越界就结束
    //把index下标后面的所有元素全部前移一个下标
    for (unsigned i = index; i < da->size; i++) {
        da->items[i] = da->items[i + 1];
    }
    //数组元素个数减少一个
    da->size--;
    //释放最后一个元素的堆内存空间，元素个数先减少，对应的下标位置就是最后一个元素的下标
    free(da->items[da->size]);
}

//判断数组是否越界，没有越界返回 1 ，越界返回 0，包含返回 1，不包含返回0
unsigned contains(const unsigned size, const unsigned index)
{
    if (size >= 0 && index < size)
        return 1;

    printf("index [%d] out of bounds!\n", index);
    return 0;
}

//返回输入值指针的副本，memcpy比strcpy功能更加强大
void *retrive_copy_of_value(const void *value)
{
    //先分配堆内存空间
    void *value_copy = malloc(sizeof(void *));
    //把输入值内存空间所指的数据复制到新分配的内存上
    memcpy(value_copy, value, sizeof(void *));
    //返回输入数据在堆内存的副本
    return value_copy;
}