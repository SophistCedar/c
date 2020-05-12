#include<stdio.h>
#include<stdlib.h>
/*
&a: 0x55798a1fc020
&b: 0x55798a1fc018
&c: 0x7ffedfd968b8
&d: 0x7ffedfd968c0
*/
char* a;
char* b;

int main()
{
    a = malloc(10);
    b = malloc(20);
    char* c = malloc(30);
    char* d = malloc(40);

    printf("&a: %p\n",&a);
    printf("&b: %p\n",&b);
    printf("&c: %p\n",&c);
    printf("&d: %p\n",&d);
}

