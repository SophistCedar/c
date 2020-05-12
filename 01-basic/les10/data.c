#include<stdio.h>
#include<stdlib.h>
/*

&a: 0x559db94c3048  4
&b: 0x559db94c3038  1
&c: 0x559db94c3040  8
&d: 0x559db94c3030  8
&e: 0x559db94c3018  4
&f: 0x559db94c301c  1
&g: 0x559db94c3020  8
&h: 0x559db94c3028  8
&i: 0x7ffde95025c4
a c b d h g f e i
i  e  f  g  h  d  b  c  a
   18 1c 20 28 30 38 40 48
     4  4  8  8  8  8  8
the memory address printed out is the last/final location of the variable
由此可知，
1.变量在内存中的顺序可能和我们定义的不一致，编译器会自动优化。
2.全局变量，静态变量和常量会存储在数据区。

*/

int a; // int type: 4 bytes
char b; // 1
int * c; // 8
char * d;

int main()
{
    static int e;
    static char f;
    static int * g;
    static char * h;
    const int i = 2;

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
