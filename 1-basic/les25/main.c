#include<stdio.h>
int main1(void){
    int tmp,sum=0;
    char flag;
    while(scanf("%d",&tmp) != EOF){
        sum += tmp;
        flag = getchar();
        printf("%c",flag);
        if (flag == '\n'){
            printf("%d\n",sum);
            sum = 0;
        }
    }
    return 0;
}
int main(){
    char c;
    //space is also a char
    while((c=getchar()) != '\n'){
        putchar(c);
    }
}