#include<stdio.h>

typedef struct TestStruct
{
    char a; // 2
    short b;// 2 bytes  
    char c; // 4    
    int d;  // 4
    char e; // 4
}TestStruct;
// 编译器会自动给我们的结构体变量填充一些空白字节，这些填充字节我们是看不到的，是隐性的。
// 在结构体变量占用相同内存的情况下，我们可以显性的表示出这些填充字节，即创建一些保留成员 。
// 这样当我们需要给这个结构体添加一些成员时，我们可以把保留的成员替换为实际的成员。
// 这样在一定程度下有利于我们节省内存空间。如下这个结构体仍然占据16个字节。
typedef struct TestStruct2
{
    char a;  
    char reserve0;    /* 保留成员 */
    short b;     
    char c;     
    int d;
    char e;
    char reserve1[3]; /* 保留成员 */
}TestStruct2;

// 调整顺序，优化结构体占用的内存，没有办法彻底优化，但是会比之前的少一点
typedef struct TestStruct3
{
    char a;// 1
    char c;// 1 
    char e;// 2
    short b;// 4         
    int d;// 4
}TestStruct3;

typedef struct TestStruct4
{
    char a;// 1
    char c;// 1 
    char e;// 2
    char reserve1;
    short b;// 4
    char reserve[2];         
    int d;// 4
}TestStruct4;


int main(void)
{
    TestStruct test_s;  
    printf("\n============================================\n");
    printf("test_s addr   = %p\n", &test_s);
    printf("test_s.a addr = %p\n", &test_s.a);
    printf("test_s.b addr = %p\n", &test_s.b);
    printf("test_s.c addr = %p\n", &test_s.c);
    printf("test_s.d addr = %p\n", &test_s.d);
    printf("test_s.e addr = %p\n", &test_s.e);
    printf("sizeof(TestStruct) = %ld\n", sizeof(TestStruct));
    printf("============================================\n");


    printf("sizeof(TestStruct2) = %ld\n", sizeof(TestStruct2));

    TestStruct3 test_s3;  
    printf("\n============================================\n");
    printf("test_s addr   = %p\n", &test_s3);
    printf("test_s.a addr = %p\n", &test_s3.a);
    printf("test_s.b addr = %p\n", &test_s3.b);
    printf("test_s.c addr = %p\n", &test_s3.c);
    printf("test_s.d addr = %p\n", &test_s3.d);
    printf("test_s.e addr = %p\n", &test_s3.e);
    printf("sizeof(TestStruct3) = %ld\n", sizeof(TestStruct3));
    printf("============================================\n");
    printf("sizeof(TestStruct4) = %ld\n", sizeof(TestStruct4));


    return 0;
}