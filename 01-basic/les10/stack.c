#include<stdio.h>
#include<stdlib.h>
/*

&a: 0x7ffde4bf82a4
&b: 0x7ffde4bf82a2
&c: 0x7ffde4bf82b0
&d: 0x7ffde4bf82b8
&e: 0x7ffde4bf82a8
&f: 0x7ffde4bf82ac
&g: 0x7ffde4bf82a3
&h: 0x7ffde4bf82c0
h  d  c  f  e  a  g  b 
c0 b8 b0 ac a8 a4 a3 a2
  8  8  4  4  4  1  1
first: pointer type
second: int type
third: char type
*/
int main()
{
    int a = 1; // int type: 4 bytes
    char b; // 1
    int * c; // 8
    char * d;
    int e;
    int f;
    char g;
    int * h;
    int i = a;
    printf("&a: %p\n",&a);
    printf("&b: %p\n",&b);
    printf("&c: %p\n",&c);
    printf("&d: %p\n",&d);
    printf("&e: %p\n",&e);
    printf("&f: %p\n",&f);
    printf("&g: %p\n",&g);
    printf("&h: %p\n",&h);
    printf("&i: %p\n",&i);

}

