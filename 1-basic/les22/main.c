#include <stdio.h>
#include <string.h>

int main(){
    //input
    char str[1000];
    fgets(str,sizeof(str),stdin);
    char c;
    c = getchar();//fgetc(stdin);

    //count
    int count = 0;
    //将一个小写字符转换成大写字符，只需要将这个字符减去32；
    //将一个大写字符转换成小写字符，则给这个字符加上32；
    //a=97 A=65
    if(c>='a' && c<='z')//c是小写字母
    {
        for(int i=0;i<strlen(str);i++)
        {
            if(c==str[i] || c==str[i]+32) count++;
        }
    }
    
    if(c>='A' && c<='Z')//c是大写字母
    {
        for(int i=0;i<strlen(str);i++)
        {
            if(c==str[i] || c==str[i]-32) count++;
        }
    }

    //output
    printf("%d\n",count);
    return 0;
}
/*
题目描述
写出一个程序，接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。
输入描述:
第一行输入一个有字母和数字以及空格组成的字符串，第二行输入一个字符。
输出描述:
输出输入字符串中含有该字符的个数。
*/