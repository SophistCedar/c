#include <stdio.h>
#include <string.h>
/*
题目描述
计算字符串最后一个单词的长度，单词以空格隔开。 
输入描述:
一行字符串，非空，长度小于1000。
输出描述:
整数N，最后一个单词的长度。
*/
int main(){
    //input
    char str[1000];
    //scanf("%s",str);//遇到空格就结束了，
    //一开始打算使用gets函数，gets函数读取一行数据，只有遇到回车键时才认为字符串输入结束
    //gets不能在linux下使用，这里使用fgets函数，指定stdin
    fgets(str,sizeof(str),stdin);
    
    //split
    const char *delim = " ";//分隔符
    char *token = NULL;//返回的字符串
    token = strtok(str,delim);
    char *last;//记录最后一个字符串
    while(token){
        last = token;
        token = strtok(NULL,delim);
    }
    
    //output
    printf("%ld\n",strlen(last)-1);//减去换行符
    return 0;
}