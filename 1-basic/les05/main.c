#include <stdio.h>
//输入流 输出流 错误流
//./a.out <input.txt 1>t.txt 2>f.txt
//1是输出流，2是错误流
int main()
{
   int i,j;
   printf("input the int value numerator i:\n");
   scanf("%d",&i);
   printf("input the int value denominator j:\n");
   scanf("%d",&j);
   if(0 != j){
     printf("%d/%d=%d\n",i,j,i/j);
   }else{
     fprintf(stderr,"j != 0\n");
     return 1;
   }
   return 0;
}
