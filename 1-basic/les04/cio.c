#include <stdio.h>

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
