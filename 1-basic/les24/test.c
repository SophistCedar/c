#include <stdio.h>
#include "mymath.h"// 自定义头文件
#define TEST_NUM 10000
int main(){
    int a = 2;
    int b = 3;
    int sum = add(a, b); 
    printf("a=%d, b=%d, a+b=%d\n", a, b, sum);

    printf("TEST_NUM:%d\n",TEST_NUM);
}