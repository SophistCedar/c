#include <stdlib.h> 
#include <stdio.h>

//数组指针：指向数组的指针。
//int arr[] = {0,1,2,3,4};
//int *p = arr;

//指针数组：数组中每个元素都是指针。
//int a = 1, b = 2, c = 3;
//定义一个指针数组
//int *arr[3] = {&a, &b, &c};//也可以不指定长度，直接写作 int *parr[]
//定义一个指向指针数组的指针，二级指针
//int **parr = arr;

//二维数组指针：指向二维数组的指针。如：
//int a[3][4] = { {0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11} };
//int (*p)[4] = a;





//数组指针：指向数组的指针。
//int arr[] = {0,1,2,3,4};
//int *p = arr;
//p，arr，&arr[0]都是指向数组的开头，即第0个元素的地址。
int main1(void)
{
   int arr[] = {0, 1, 2, 3, 4};
   int *p = &arr[3];  //也可以写作 int *p = arr + 3;

   printf("%d, %d, %d, %d, %d\n", 
   *(p-3), *(p-2), *(p-1), *(p), *(p+1) );
   return 0;
}

//指针数组：数组中每个元素都是指针。
int main2(void)
{
   int a = 1, b = 2, c = 3;
   //定义一个指针数组
   int *arr[3] = {&a, &b, &c};//也可以不指定长度，直接写作 int *parr[]
   //定义一个指向指针数组的指针
   int **parr = arr;
   printf("%d, %d, %d\n", *arr[0], *arr[1], *arr[2]);
   printf("%d, %d, %d\n", **(parr+0), **(parr+1), **(parr+2));

   return 0;
}
//指针数组和字符串结合使用  char s[10][80] 二维字符数组
int main3(void)
{
   char *str[3] = 
   {
       "hello C",
       "hello C++",
       "hello Java"
   };
   printf("%s\n%s\n%s\n", str[0], str[1], str[2]);
   return 0;
}

//二维数组指针
//二维数组指针：指向二维数组的指针。如：
//int a[3][4] = { {0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11} };
//int (*p)[4] = a;
int main4(void)
{
  int a[3][4] = { {0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11} };
  int i,j;
  for( i = 0; i < 3; i++ )
  {
    for( j = 0; j < 4; j++ )
    {
      printf("a[%d][%d]=%d=%p\n", i, j,a[i][j], &a[i][j]);
    }
  }
  return 0;
}

int main5(){
    int a[3][4]={{0,1,2,3},{4,5,6,7},{8,9,10,11}};
    int(*p)[4];
    int i,j;
    p=a;
    for(i=0; i<3; i++){
        for(j=0; j<4; j++) printf("%2d  ",*(*(p+i)+j));
        printf("\n");
    }
    return 0;
}



int main(){
  main1();
  main2();
  main3();
  main4();
  main5();
  return 0;
}
