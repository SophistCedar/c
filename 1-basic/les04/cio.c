#include <stdio.h>
//标准输入 标准输出  标准错误的实现
//gets fgets也是一样的道理
int main()
{
    //printf("hello world!\n");
    fprintf(stdout,"hello world!\n");
    int a;
    //scanf("%d",&a);
    fprintf(stdout,"Please enter a number greater than 0\n");
    fscanf(stdin,"%d",&a);
    if(a<0){
       fprintf(stderr,"the input value must > 0\n");
       return 1;
    }
    return 0;
}
