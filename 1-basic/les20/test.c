#include <stdio.h>
#include <string.h>
//第一行输入国家个数 N
//接下来 N 行分别输入字符串 金牌数 银牌数 铜牌数，空格分隔开的
//要求输出排序后的字符串
//排序要求  金牌数 银牌数 铜牌数 如果全部相同就按照字符串升序排序
void swap_str(char s1[],char s2[]){
    char temp[80];
    strcpy(temp,s1);
    strcpy(s1,s2);
    strcpy(s2,temp);
}

void swap_int(int *i,int *j){
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

int main(){
    // input
    int N;
    scanf("%d",&N);
    char name[N][80];
    int G[N];
    int S[N];
    int B[N];
    int i;
    for(i=0;i<N;i++){
        scanf("%s %d %d %d",name[i],&G[i],&S[i],&B[i]);
    }

    for(i=0;i<N;i++){
        printf("%-10s %-3d %-3d %-3d\n",name[i],G[i],S[i],B[i]);
    }
    printf("\n");

    int j;
    //bubble sort
    for(i=0;i<N-1;i++){
        for(j=0;j<N-1-i;j++){
            if(G[j]<G[j+1])
            {
                swap_str(name[j],name[j+1]);
                swap_int(&G[j],&G[j+1]);
                swap_int(&S[j],&S[j+1]);
                swap_int(&B[j],&B[j+1]);
            }
            else if(G[j]==G[j+1] && S[j]<S[j+1])
            {
                swap_str(name[j],name[j+1]);
                swap_int(&G[j],&G[j+1]);
                swap_int(&S[j],&S[j+1]);
                swap_int(&B[j],&B[j+1]);
            }
            else if(G[j]==G[j+1] && S[j] == S[j+1] && B[j]<B[j+1])
            {
                swap_str(name[j],name[j+1]);
                swap_int(&G[j],&G[j+1]);
                swap_int(&S[j],&S[j+1]);
                swap_int(&B[j],&B[j+1]);
            }
            else if(G[j]==G[j+1] && S[j] == S[j+1] && B[j]==B[j+1] && (strcmp(name[j],name[j+1])) > 0)
            {
                swap_str(name[j],name[j+1]);
                swap_int(&G[j],&G[j+1]);
                swap_int(&S[j],&S[j+1]);
                swap_int(&B[j],&B[j+1]);
            }   
            
        }

    }
    // output, use pipeline to do the input
    // ./text.out < input.txt
    for(i=0;i<N;i++){
        printf("%-10s %-3d %-3d %-3d\n",name[i],G[i],S[i],B[i]);
    }

    return 0;
}