#include<stdio.h>
#include<string.h>
void sort(char (*str)[100],int n){
    int i,j;
    char tmp[100];
    for(i=0;i<n-1;i++){
        int min = i;
        for(j=i+1;j<n;j++){
            if((strcmp(str[j],str[min])) < 0){
                min = j;
            }
        }
        strcpy(tmp,str[min]);
        strcpy(str[min],str[i]);
        strcpy(str[i],tmp);
    }
}
int main(void){
    char str[100][100];
    char tmp[100];
    const char * delim = ",";
    int i = 0;
    while((scanf("%s",tmp)) != EOF){
        char * p = strtok(tmp,delim);
        while(p != NULL){
            strcpy(str[i],p);
            i++;
            p = strtok(NULL,delim);
        }
        sort(str,i);
        for(int j=0;j<i;j++){
            printf("%s",str[j]);
            if(j<i-1) printf(",");
        }
        i = 0;
        printf("\n");
    }
    return 0;
}