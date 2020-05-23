#include <stdio.h>
//命令行参数 int argv   char *argc[]
//默认情况喜爱，argv=1,argc[0]是可执行文件名称

/*
sophist@ubuntu:~/workspace/les3$ ls
main.c
sophist@ubuntu:~/workspace/les3$ cc main.c 
sophist@ubuntu:~/workspace/les3$ ls
a.out  main.c
sophist@ubuntu:~/workspace/les3$ ./a.out 
argv:1
argc[0] is ./a.out
hello world!
sophist@ubuntu:~/workspace/les3$ ./a.out -l
argv:2
argc[0] is ./a.out
argc[1] is -l
hello world!
sophist@ubuntu:~/workspace/les3$ ./a.out -l -a
argv:3
argc[0] is ./a.out
argc[1] is -l
argc[2] is -a
hello world!
sophist@ubuntu:~/workspace/les3$ ./a.out -l -a -csbjcbs
argv:4
argc[0] is ./a.out
argc[1] is -l
argc[2] is -a
argc[3] is -csbjcbs
hello world!
*/

int main(int argv, char *argc[])
{

    printf("argv:%d\n",argv);
    //argv是输入参数的个数，终端执行命令时，参数交互的，表示包括执行可执行文件，总共多少段。
    int i;
    for(i=0;i<argv;i++){
      printf("argc[%d] is %s\n",i,argc[i]);
    }
    //argc是可执行文件后面可以加的字符，可以有不同的功能，argc[0]是执行可执行文件的命令；
    //这里以ls命令为例子，argc[0] is ls, argc[1] is -l；
    //这样子，当我们开发了一个小工具，可以设置不同参数，以至于终端内使用达到不同的功能。
    printf("hello world!\n");
    return 0;
    //终端内echo $?命令可以查看返回的代码，0意味着运行成功。
    //如果运行成功，可以使用&&连接两个命令，&&会自动判别前一个命令返回值是否为0决定下一个命令是否接着运行。
    //gcc main.c -o main.out && ./main.out  表示先编译可执行文件，再接着执行。
}
