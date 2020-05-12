# include<stdio.h>
# include<stdlib.h>
# include<string.h>

/*

&p1 = 0x562a24f5a018
&p2 = 0x7fff8ce821f0
&p3 = 0x7fff8ce821f8
&p4 = 0x7fff8ce82200
&p5 = 0x562a24f5a020

p1 p5 in data sector 
p2 p3 p4 in stack sector

*/


char *p1; 
char *p5;
int main()   
{   
    printf("&p1 = %p\n",&p1);
  
    char *p2; // stack
    printf("&p2 = %p\n",&p2);    

    char* p3 = malloc(100); // heap
    printf("&p3 = %p\n",&p3);     
    char* p4 = malloc(100); // heap
    printf("&p4 = %p\n",&p4);     

    p5 = malloc(200);
    printf("&p5 = %p\n",&p5);  

    return 0;  
}