输入流、输出流以及错误流的重定向
输出流：>表示覆盖文件原有内容，>>表示向文件追加内容。

sophist@ubuntu:~/workspace/les5$ ls
main.c
sophist@ubuntu:~/workspace/les5$ cc main.c
sophist@ubuntu:~/workspace/les5$ ls
a.out  main.c
sophist@ubuntu:~/workspace/les5$ ./a.out
input the int value numerator i:
10
input the int value denominator j:
5
10/5=2
sophist@ubuntu:~/workspace/les5$ ./a.out >>a.txt
10
5
sophist@ubuntu:~/workspace/les5$ cat a.txt
input the int value numerator i:
input the int value denominator j:
10/5=2
sophist@ubuntu:~/workspace/les5$ ls -l
total 28
-rwxr-xr-x 1 sophist sophist 16928 Mar 23 05:24 a.out
-rw-r--r-- 1 sophist sophist    75 Mar 23 05:25 a.txt
-rw-r--r-- 1 sophist sophist   311 Mar 23 05:21 main.c
sophist@ubuntu:~/workspace/les5$ ls -l >> les5.txt
sophist@ubuntu:~/workspace/les5$ ls
a.out  a.txt  les5.txt  main.c
sophist@ubuntu:~/workspace/les5$ cat les5.txt
total 28
-rwxr-xr-x 1 sophist sophist 16928 Mar 23 05:24 a.out
-rw-r--r-- 1 sophist sophist    75 Mar 23 05:25 a.txt
-rw-r--r-- 1 sophist sophist     0 Mar 23 05:25 les5.txt
-rw-r--r-- 1 sophist sophist   311 Mar 23 05:21 main.c
sophist@ubuntu:~/workspace/les5$ cat main.c
#include <stdio.h>


int main()
{
   int i,j;
   printf("input the int value numerator i:\n");
   scanf("%d",&i);
   printf("input the int value denominator j:\n");
   scanf("%d",&j);
   if(0 != j){
     printf("%d/%d=%d\n",i,j,i/j);
   }else{
     fprintf(stderr,"j != 0\n");
     return 1;
   }
   return 0;
}
sophist@ubuntu:~/workspace/les5$ cat main.c >> main.txt
sophist@ubuntu:~/workspace/les5$ ls
a.out  a.txt  les5.txt  main.c  main.txt
sophist@ubuntu:~/workspace/les5$ cat main.txt
#include <stdio.h>


int main()
{
   int i,j;
   printf("input the int value numerator i:\n");
   scanf("%d",&i);
   printf("input the int value denominator j:\n");
   scanf("%d",&j);
   if(0 != j){
     printf("%d/%d=%d\n",i,j,i/j);
   }else{
     fprintf(stderr,"j != 0\n");
     return 1;
   }
   return 0;
}
输入流 <

sophist@ubuntu:~/workspace/les5$ ls
a.out  a.txt  les5.txt  main.c  main.txt
sophist@ubuntu:~/workspace/les5$ vim input.txt
sophist@ubuntu:~/workspace/les5$ ls
a.out  a.txt  input.txt  les5.txt  main.c  main.txt
sophist@ubuntu:~/workspace/les5$ cat input.txt
10
5


sophist@ubuntu:~/workspace/les5$ ./a.out <input.txt
input the int value numerator i:
input the int value denominator j:
10/5=2
错误流：1>t.txt 2>f.txt
1是输出流，2是错误流

sophist@ubuntu:~/workspace/les5$ ls
a.out  main.c
sophist@ubuntu:~/workspace/les5$ vim input.txt
sophist@ubuntu:~/workspace/les5$ ls
a.out  input.txt  main.c
sophist@ubuntu:~/workspace/les5$ cat input.txt
10
5
sophist@ubuntu:~/workspace/les5$ ./a.out <input.txt 1>t.txt 2>f.txt
sophist@ubuntu:~/workspace/les5$ ls
a.out  f.txt  input.txt  main.c  t.txt
sophist@ubuntu:~/workspace/les5$ cat t.txt
input the int value numerator i:
input the int value denominator j:
10/5=2
sophist@ubuntu:~/workspace/les5$ cat f.txt
sophist@ubuntu:~/workspace/les5$ vim input.txt
sophist@ubuntu:~/workspace/les5$ cat input.txt
10
0
sophist@ubuntu:~/workspace/les5$ ./a.out <input.txt 1>t1.txt 2>f1.txt
sophist@ubuntu:~/workspace/les5$ ls
a.out  f1.txt  f.txt  input.txt  main.c  t1.txt  t.txt
sophist@ubuntu:~/workspace/les5$ cat t1.txt
input the int value numerator i:
input the int value denominator j:
sophist@ubuntu:~/workspace/les5$ cat f1.txt
j != 0


