#include <stdio.h>
#include "max.h"//多个 .c 文件如何处理
#include "min.h"

int main()
{
    int a1 = 33;
    int a2 = 21;
    int maxNum = max(a1,a2);
    int minNum = min(a1,a2);
    printf("the maxNum is %d\n",maxNum);
    printf("the minNum is %d\n",minNum);
    return 0;
}
