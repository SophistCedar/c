#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //使用默认设置初始化动态数组
    dynamic_array_t *da = init_dynamic_array();
    //对数组赋值
    for (int i = 1; i <= 50; i++) {
        add(da, &i);
    }
    printf("da->size = %d\n",da->size);
    //删除指定坐标对应的元素
    delete (da, 10);//删除11
    //更新指定下标元素的值
    int value = 1000;
    put(da, &value, 0);//1 替换成 1000
    //在末尾添加元素值7000的元素
    value = 5000;
    int another_value = 7000;
    add(da, &another_value);//末尾添加元素 7000
    //输出数组元素
    for (int i = 0; i < da->size; i++) {
        printf("value %d\n", *(int *)get(da, i));
    }
    //替换下标150的元素为 10000
    int value_for_invalid_index = 10000;
    put(da, &value_for_invalid_index, 150);
    return 0;
}