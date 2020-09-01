#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//size_t memsize = (size_t)1024*1024*1024*4+1024*1024*32;//malloc success, but memset fail
//size_t memsize = (size_t)1024*1024*1024*2+1024*1024*256*2;//both malloc and memset success
size_t memsize = (size_t)1024*1024*1024*2+1024*1024;//both malloc and memset success
int main(void)
{
    char * buf = (char *)malloc(memsize);
    if (buf != NULL){
        printf("malloc success\n");
    }
    else{
        printf("malloc fail\n");
        exit(1);
    }
    memset(buf,0xCC,memsize);
    printf("memset success\n");
    return 0;
}
