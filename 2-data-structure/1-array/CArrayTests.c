#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CArray.h"

int CArrayTests()
{
	printf("\n");
	printf(" +-------------------------------------+\n");
	printf(" |                                     |\n");
	printf(" |               C Array               |\n");
	printf(" |                                     |\n");
	printf(" +-------------------------------------+\n");
	printf("\n");
	//创建数组，数组长度为 10
	CArray *array = getCArray(10);
	//对数组赋值
	int i;
	for (i = 0; i < array->size; i++) {
		insertValueCArray(array, i, i+1);
	}
	printf("Entered array is:\n");
	//展示原始数组
	displayCArray(array);
	//向位置 11 末尾增加元素，但是数组已满
	printf("\nCode: %d\n", pushValueCArray(array, 11)); // 5

	//清空数组内的元素
	for (i = 0; i < array->size; i++) {
		removeValueCArray(array, i);
	}
	//展示清空后的数组
	displayCArray(array);
	//指定位置对数组初始化
	printf("\nCode: %d", removeValueCArray(array, -1)); // 1
	//指定位置，插入元素
	printf("\nCode: %d\n", insertValueCArray(array, -1, 1)); // 1

	// Erase
	for (i = 0; i < array->size; i++) {
		insertValueCArray(array, i, i + 1);
	}
	eraseCArray(array);
	displayCArray(array); // Should give all 0s

	// Switching
	CArray *arr = getCArray(13);
	for (i = 0; i < arr->size; i++) {
		insertValueCArray(arr, i, i + 1);
	}
	displayCArray(arr);
	for (i = 0; i < arr->size / 2; i++) {
		switchValuesCArray(arr, i, arr->size - i - 1);
	}
	displayCArray(arr);

	// Or simply...
	reverseCArray(arr);
	displayCArray(arr);
	
	// Sorting
	srand(time(NULL));
	CArray *barray = getCArray(20);
	for (i = 0; i < barray->size; i++) {
		insertValueCArray(barray, i, rand());
	}
	CArray *carray = getCopyCArray(barray);
	CArray *darray = getCopyCArray(barray);
	printf("\nNot sorted Array:");
	displayCArray(barray);

	printf("\nBubble Sort:");
	clock_t begin1 = clock();
	// Timing bubble sort
	bubbleSortCArray(barray);
	clock_t end1 = clock();
	double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
	displayCArray(barray);

	printf("\nSelection Sort:");
	clock_t begin2 = clock();
	// Timing selection sort
	selectionSortCArray(carray);
	clock_t end2 = clock();
	double time_spent2 = (double)(end2 - begin2) / CLOCKS_PER_SEC;
	displayCArray(carray);

	printf("\nInsertion Sort:");
	clock_t begin3 = clock();
	// Timing insertion sort
	insertionSortCArray(darray);
	clock_t end3 = clock();
	double time_spent3 = (double)(end3 - begin3) / CLOCKS_PER_SEC;
	displayCArray(carray);

	// Descending order
	reverseCArray(barray);
	// displayCArray(barray);

//	printf("\nBlender:");
//	blenderCArray(barray);
//	displayCArray(barray);

	printf("\nTotal time spent for bubble sort: %lf seconds", time_spent1);
	printf("\nTotal time spent for selection sort: %lf seconds", time_spent2);
	printf("\nTotal time spent for insertion sort: %lf seconds", time_spent3);

	// Searching
	CArray *aarray = getCArray(1000);
	for (i = 0; i < aarray->size; i++) {
		insertValueCArray(aarray, i, rand() % 100);
	}

	int j = 24;
	printf("\nOccurrences of the number %d in the array: %d", j, 
		valueOcurranceCArray(aarray, j));
	printf("\nAnd its positions:\n");
	CArray *positions = valuePositionsCArray(aarray, j);
	displayCArray(positions);
	// This should all give value of j
	printf("\nAll %d s", j);
	for (i = 0; i < positions->size; i++) {
		printf("\nPosition %d has a value of %d", 
			positions->array[i], aarray->array[positions->array[i]]);
	}
	printf("\nThe list has a minimum value of %d and a maximum value of %d", 
		findMinCArray(aarray), findMaxCArray(aarray));
	insertionSortCArray(aarray);
	// displayCArray(aarray);

	//must free the mallca memory
	free(arr);
	free(array);
	free(aarray);
	free(barray);
	free(carray);
	free(darray);
	printf("\n");
	return 0;
}
int main(){
	CArrayTests();
	return 0;
}
