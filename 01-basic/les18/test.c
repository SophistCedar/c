#include <stdio.h>
#include <stdlib.h>
#include <time.h>//time()
#include <unistd.h>//sleep() delay with seconds
//交换两个整数
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//选择排序，先找到最小值放到开头，外循环 n-1 次
//外循环 i = 0 - n-1  内循环 j = i+1 - n，左闭右开区间
//两个变量 i j 即可，因为写了专门的交换变量的函数
void selection_sort(int arr[],int len){
    int i, j;
    for(i=0;i<len-1;i++){
        int min = i;//初始赋值，假设最小值就是当前位置，如果后面有更小的就交换位置
        for(j=i+1;j<len;j++){//走访未排序的元素
            if(arr[j]<arr[min]){//找到目前最小值
                min = j;//记录最小值下标
            }
        }
        swap(&arr[i],&arr[min]);//交换
    }
}

int main() {
    int arr[] = { 1589, 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = (int) sizeof(arr) / sizeof(*arr);//数组长度等于数组总字节数 / 数组首元素的字节数
    selection_sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");


    int N = 30;
    int buf[N];
    for(i=0;i<N;i++){
        //srand((unsigned)time(NULL));
        //sleep(1);
        srand((unsigned)i);
        buf[i] = rand()%100;//生成100以内的随机数
    }
    selection_sort(buf,N);
    for(i=0;i<N;i++){
        printf("%d ",buf[i]);
    }
    printf("\n");

    
    return 0;
}