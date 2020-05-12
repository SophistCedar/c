#include<stdio.h>
/*
从第一个成员或者中间成员考虑
原则1、数据成员对齐规则：结构（struct或union）的数据成员，第一个数据成员放在offset为0的地方，
以后每个数据成员相对于起始地址的偏移能够被其自身字节大小整除，如果不能则在前一个成员后面补充字节。
中间成员内有结构体
原则2、结构体作为成员：如果一个结构里有某些结构体成员，则结构体成员要从其内部最大元素字节大小的
整数倍地址开始存储。（struct a里存有struct b，b里有char，int，double等元素，那b应该从8的整数倍开始存储。）
最后一个成员一起考虑
原则3、收尾工作：结构体的总大小，也就是sizeof的结果，必须是其内部最大成员的整数倍，不足的要补齐，
此种情况不包括嵌套结构体的情况，比如对下面的struct A末尾增加char gg[5]的字符数组，struct A字节数32，struct B字节数56。
*/
struct A{
  int a;//4字节，补齐到8，此时8
  double b;//8字节，此时16
  float c;//4字节，补齐到8，此时24
  // char gg[5];
};
struct B{
  char e[2];//2 补齐两个，因为下一个是int型，此时4
  int f;//4,此时8
  double g; //不需要补齐，正好是8，此时16
  short h;//是16，不需要因为short h补齐，此时18，但是因为struct内的double是8个字节，需要补齐到8的倍数
  struct A i;//补齐到24，此时48
};

int main(void)
{
    struct A testA;     
    printf("\n============================================\n");
    printf("testA addr   = %p\n", &testA);
    printf("testA.a addr   = %p\n", &testA.a);
    printf("testA.b addr   = %p\n", &testA.b);
    printf("testA.c addr   = %p\n", &testA.c);
    printf("sizeof(struct A) = %ld\n", sizeof(struct A));
    printf("============================================\n");
    struct B testB;  
    printf("\n============================================\n");
    printf("testB addr   = %p\n", &testB);
    printf("testB.e addr   = %p\n", &testB.e);
    printf("testB.f addr   = %p\n", &testB.f);
    printf("testB.g addr   = %p\n", &testB.g);
    printf("testB.h addr   = %p\n", &testB.h);
    printf("testB.A.a addr   = %p\n", &testB.i.a);
    printf("testB.A.b addr   = %p\n", &testB.i.b);
    printf("testB.A.c addr   = %p\n", &testB.i.c);
    printf("sizeof(struct B) = %ld\n", sizeof(struct B));
    printf("============================================\n");

    return 0;
}