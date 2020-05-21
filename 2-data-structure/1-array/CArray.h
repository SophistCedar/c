//#pragma once是一个比较常用的C/C++预处理指令，
//只要在头文件的最开始加入这条预处理指令，就能够保证头文件只被编译一次。
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

	#define ARRAY_ERASED -1
	#define SUCCESS 0
	#define INVALID_POSITION 1
	#define POSITION_INIT 2
	#define POSITION_NOT_INIT 3
	#define POSITION_EMPTY 4
	#define ARRAY_FULL 5
	//自定义数组类型，包括数组首元素地址和数组元素的个数
	typedef struct CArray {
		int *array;//数组首元素地址
		int size;//数组长度
	} CArray;

	// +-------------------------------------+
	// |           Returns array             |
	// +-------------------------------------+
	CArray * getCArray(int size);//创建数组
	CArray * getCopyCArray(CArray *array);//复制数组

	// +-------------------------------------+
	// |           Input / Output            |
	// +-------------------------------------+
	int insertValueCArray(CArray *array, int position, int value);//指定位置插入元素
	int removeValueCArray(CArray *array, int position);//指定位置移除元素
	int pushValueCArray(CArray *array, int value);//在数组末尾添加元素
	int updateValueCArray(CArray *array, int position, int value);//更新已经赋值的数组元素

	// +-------------------------------------+
	// |               Erase                 |
	// +-------------------------------------+
	int eraseCArray(CArray *array);//还原数组到初始化状态

	// +-------------------------------------+
	// |             Switching               |
	// +-------------------------------------+
	int switchValuesCArray(CArray *array, int position1, int position2);//交换数组指定位置的两个元素的值
	int reverseCArray(CArray *array);//逆序数组

	// +-------------------------------------+
	// |              Sorting                |
	// +-------------------------------------+
	int bubbleSortCArray(CArray *array);//数组冒泡排序
	int selectionSortCArray(CArray *array);//数组选择排序
	int insertionSortCArray(CArray *array);
	int blenderCArray(CArray *array);//数组元素顺序随即打乱

	// +-------------------------------------+
	// |             Searching               |
	// +-------------------------------------+
	int valueOcurranceCArray(CArray *array, int value);//查找元素出现次数
	CArray * valuePositionsCArray(CArray *array, int value);//查找元素出现位置
	int findMaxCArray(CArray *array);//找到最大值
	int findMinCArray(CArray *array);//找到最小值

	// +-------------------------------------+
	// |              Display                |
	// +-------------------------------------+
	int displayCArray(CArray *array);//显示数组
	

#ifdef __cplusplus
}
#endif
