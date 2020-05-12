#include <stdio.h>
#include <stdlib.h>
#include <time.h>//time()
#include <unistd.h>//sleep() delay with seconds
//传入数组首地址和数组长度
//先比较前n个，再比较n-1个，依次类推，所以需要两轮循环
//比较n-1个外循环，最后一个最小的不用比较
//三个变量i j temp
//前一个比后一个大就交换位置
void bubble_sort(int arr[],int len){
    int i, j, temp;
    for(i=0;i<len-1;i++){
        for(j=0;j<len-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = { 1589, 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = (int) sizeof(arr) / sizeof(*arr);//数组长度等于数组总字节数 / 数组首元素的字节数
    bubble_sort(arr, len);
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
    bubble_sort(buf,N);
    for(i=0;i<N;i++){
        printf("%d ",buf[i]);
    }
    printf("\n");

    
    return 0;
}