/*
 Return Codes

 -1 - Array Erased
 0 - Success
 1 - Invalid Position
 2 - Position already initialized (use update function)
 3 - Position not initialized (use insert function)
 4 - Position already empty
 5 - Array is full
 	#define ARRAY_ERASED -1
	#define SUCCESS 0
	#define INVALID_POSITION 1
	#define POSITION_INIT 2
	#define POSITION_NOT_INIT 3
	#define POSITION_EMPTY 4
	#define ARRAY_FULL 5

 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CArray.h"
//交换数组内两个下标位置的元素
void swap(CArray *array, int position1, int position2);

//创建数组，创建 size 大小的自定义整形数组，数组内的所有值初始化为0
CArray * getCArray(int size)
{
	CArray *array = (CArray *) malloc(sizeof(CArray));//分配的内存空间最后一定要释放
	array->array = (int *) malloc(sizeof(int) * size);
	array->size = size;
	int i;
	for (i = 0; i < size; i++) {
		array->array[i] = 0;
	}
	return array;
}

//复制数组，输入要复制的数组指针，
//返回指向自定义结构体整形数组的指针，新数组的指针
CArray * getCopyCArray(CArray *arr)
{
	CArray *array = (CArray *)malloc(sizeof(CArray));//输出的数组
	array->array = (int *)malloc(sizeof(int) * arr->size);
	array->size = arr->size;
	int i;
	for (i = 0; i < arr->size; i++) {
		array->array[i] = arr->array[i];
	}
	return array;
}


//指定位置和元素，向创建的数组赋值，有可能已经赋值完成，或者位置无效
int insertValueCArray(CArray *array, int position, int value)
{
	if (position >= 0 && position < array->size) {
		if (array->array[position] == 0) {
			array->array[position] = value;
			return SUCCESS;
		}
		else return POSITION_INIT; //该下标位置已经赋值过了
	}
	return INVALID_POSITION; //输入的位置无效
}

//指定位置，将数组对应的元素还原，回到初始化状态的 0
int removeValueCArray(CArray *array, int position)
{
	if (position >= 0 && position < array->size) {
		if (array->array[position] != 0) {
			array->array[position] = 0;
			return SUCCESS;
		}
		else return POSITION_EMPTY; //下标位置本身就是初始化状态
	}
	return INVALID_POSITION;
}

//在尾部插入值
//在数组未被初始化的区域赋值，如果数组已满，赋值失败
int pushValueCArray(CArray *array, int value)
{
	int i;
	int ok = 0;//赋值成功，更改为 1
	for (i = 0; i < array->size; i++) {
		if (array->array[i] == 0) {//一直寻找到元素为0的位置
			array->array[i] = value;
			ok = 1;
			break;
		}
	}
	if (ok == 1) return SUCCESS;
	else return ARRAY_FULL;
}

//更新数组内某个位置的元素，该位置元素已经被初始化的情况下更新
int updateValueCArray(CArray *array, int position, int value)
{
	if (position >= 0 && position < array->size) {
		if (array->array[position] != 0) {
			array->array[position] = value;
			return SUCCESS;
		}
		else return POSITION_NOT_INIT;
	}
	return INVALID_POSITION;
}

//初始化数组所有元素为 0
int eraseCArray(CArray *array)
{
	int i;
	for (i = 0; i < array->size; i++) {
		array->array[i] = 0;
	}
	return 0;
}

//交换数组内两个位置元素的值
int switchValuesCArray(CArray *array, int position1, int position2)
{
	if (position1 >= 0 && position1 < array->size 
		&& position2 >= 0 && position2 < array->size) {
		int temp = array->array[position1];
		array->array[position1] = array->array[position2];
		array->array[position2] = temp;
	}
	return INVALID_POSITION;
}

//反转数组内的元素，首尾两两交换
int reverseCArray(CArray *array)
{
	int i;
	for (i = 0; i < array->size / 2; i++) {
		swap(array, i, array->size - i - 1);
	}
	return SUCCESS;
}

//显示数组内容
int displayCArray(CArray *array)
{
	int i;
	printf("\nC ARRAY\n");
	for (i = 0; i < array->size; i++) {
		printf("%d ", array->array[i]);
	}
	printf("\n");
	return 0;
}

//打乱数组内的元素顺序
int blenderCArray(CArray *array)
{
	srand(time(NULL) * array->size);//扩大种子的差别
	int i;
	int total = array->size * 100;//增加更多的交换次数
	for (i = 0; i < total; i++) {
		swap(array, rand() % array->size, rand() % array->size);//必须加上取余数，确保数组不会发生越界
	}
	return 0;
}

//交换数组内两个位置的元素，没有错误检查机制，要确保位置在数组范围内，不要发生数组越界情况
void swap(CArray *array, int position1, int position2)
{
	int temp = array->array[position1];
	array->array[position1] = array->array[position2];
	array->array[position2] = temp;
}

//冒泡排序，两两比较，大的下沉
int bubbleSortCArray(CArray *array)
{
	int i, j;
	for (i = 0; i < array->size - 1; i++) {
		for (j = 0; j < array->size - i - 1; j++) {
			if (array->array[j] > array->array[j + 1]) {
				swap(array, j, j + 1);
			}
		}
	}
	return 0;
}

//选择排序，依次找到当前最小值放到开头
int selectionSortCArray(CArray *array)
{
	int i, j, min;
	for (i = 0; i < array->size - 1; i++) {
		min = i;
		for (j = i + 1; j < array->size; j++)
			if (array->array[j] < array->array[min]) min = j;
		swap(array, min, i);
	}
	return 0;
}
//插入排序
int insertionSortCArray(CArray *array)
{
	int i, j, num;
	for (i = 1; i < array->size; i++) {
		num = array->array[i];
		j = i - 1;
		while (j >= 0 && array->array[j] > num)
		{
			array->array[j + 1] = array->array[j];
			j--;
		}
		array->array[j + 1] = num;
	}
	return 0;
}

//返回一个元素在数组内出现的次数
int valueOcurranceCArray(CArray *array, int value)
{
	int i, total = 0;
	for (i = 0; i < array->size; i++) {
		if (array->array[i] == value) total++;
	}
	return total;
}

//返回一个值在数组内出现的多个位置，返回的是一个数组
CArray * valuePositionsCArray(CArray *array, int value)
{
	int i, j = 0;
	int total = valueOcurranceCArray(array, value);
	CArray *resultArray = getCArray(total);
	for (i = 0; i < array->size; i++) {
		if (array->array[i] == value) {
			// Hopefully this won't overflow
			resultArray->array[j] = i;
			j++;
		}
	}
	return resultArray;
}

//获取数组最小值，假设首元素是最小值，后面有更小的就赋值，依次比较
int findMinCArray(CArray *array)
{
	int i;
	int min = array->array[0];
	for (i = 1; i < array->size; i++) {
		if (array->array[i] < min) {
			min = array->array[i];
		}
	}
	return min;
}

//获取数组最大值，假设首元素是最大值，后面有更大的就赋值，依次比较
int findMaxCArray(CArray *array)
{
	int i;
	int max = array->array[0];
	for (i = 1; i < array->size; i++) {
		if (array->array[i] > max) {
			max = array->array[i];
		}
	}
	return max;
}
