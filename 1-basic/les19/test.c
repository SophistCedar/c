#include <stdio.h>
#include <string.h>
//第一行输入字符串个数 N
//接下来 N 行分别输入字符串
//要求输出排序后的字符串
int main(){
    // input
    int N;
    scanf("%d",&N);
    int i;
    char s[N][80];
    for(i=0;i<N;i++){
        scanf("%s",s[i]);
    }
    int j;
    char temp[80];
    //selection sort
    for(i=0;i<N-1;i++){
        int min = i;
        for(j=i+1;j<N;j++){
            if((strcmp(s[j],s[min])) < 0){
                min = j;
            }
        }
        strcpy(temp,s[min]);
        strcpy(s[min],s[i]);
        strcpy(s[i],temp);
    }
    // output, use pipeline to do the input
    // ./text.out < input.txt
    for(i=0;i<N;i++) printf("%s ",s[i]);
    printf("\n");

    return 0;
}