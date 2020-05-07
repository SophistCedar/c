#include<stdio.h>
#include<stdlib.h>
// Endian表示数据在内存中的存放顺序
// 大端模式：是指数据的高字节保存在内存的低地址端，数据的低字节保存在内存的高地址端。
// 小端模式，是指数据的高字节保存在内存的高地址端，数据的低字节保存在内存的低地址端。
// 数据的高低位在内存的高低地址对应关系。
// 高位对高地址 --> 小端  符合计算机思维
// 高位对低地址 --> 大端  符合人类思维
// 0x12345678 在内存中如何存储？假设左边低地址，右边高地址。
// 大端：12 34 56 78 
// 小端：78 56 34 12


// 验证方法是：对数据赋值，值不超过数据的低位，取数据在内存中的低地址，对低地址取值
// 判断低位数据和对低地址取值的数据是否相同，相同则是小端，否则是大端
// 此处的低位一般指最低的8位，低地址指的是最低的1字节内存地址，当然也可以是低16位对应2字节的内存低地址


// 1.利用地址强制类型转换
void funtest1(){
	int i = 1; //4字节，32位 00000000 00000000 00000000 00000001
	char j = *((char*)&i); //强制转换成字符数组，取数组首元素的内存地址，内存低地址
	char j0 = ((char*)&i)[0];
	char j1 = ((char*)&i)[1];
	char j2 = ((char*)&i)[2];
	char j3 = ((char*)&i)[3];
	printf("j: %d\n",j);
	printf("j0: %d, j1: %d, j2: %d, j3: %d\n",j0,j1,j2,j3);//字符可以直接转换成整数输出
	if (j == 1)// 数据低位存在低地址当中 --> 小端
	{ 
		printf("little endian\n");
	}
	else
		printf("big endian\n");
}

// 2.利用共用体性质：不同类型变量共享同一块内存
// 共用体各个成员在内存中的分布，在内存中被“对齐”到一头
// 修改char c 修改的是内存地址前八位，修改short j修改的是内存地址前16位，修改int i 修改的是全部内存地址
void funtest2(){
	union UN
	{
		int i; // 4字节，32位
		char c; // 1字节，8位
	}u;
	u.i = 1; 
	// 此时共用体内存应该是 00000000 00000000 00000000 00000001 
	printf("sizeof(UN): %lu\n",sizeof(union UN));

	if (u.c == 1)// 内存低地址，存放了数据低位
	{
		printf("little endian\n");
	}
	else
		printf("big endian\n");
}


void funtest3(){
	union UN
	{
		int i; // 4字节，32位
		short j; // 2字节，16位
		char c; // 1字节，8位
	}u;
	printf("sizeof(UN): %lu\n",sizeof(union UN));
	u.c = 1;
	printf("change c: u.c = %d, u.j = %d, u.i = %d\n",u.c,u.j,u.i);
	u.j = 256;
	printf("change j: u.c = %d, u.j = %d, u.i = %d\n",u.c,u.j,u.i);
	u.j = 258;
	printf("change j: u.c = %d, u.j = %d, u.i = %d\n",u.c,u.j,u.i);
	u.i = 65536;
	printf("change i: u.c = %d, u.j = %d, u.i = %d\n",u.c,u.j,u.i);
	u.i = 65538;
	printf("change i: u.c = %d, u.j = %d, u.i = %d\n",u.c,u.j,u.i);

}
int main()
{
	//测试大端和小端
    funtest1();
    funtest2();
	short int x; //2字节，16位，取地址再强制转换成字符指针，成为包含两个字符的字符数组
	char x0,x1;
	x = 0x1122;
	x0 = ((char *)&x)[0]; //低地址单元
	x1 = ((char *)&x)[1]; //高地址单元
	if(x0 == 0x11){
		printf("big endian\n");
	}else{
		printf("little endian\n");
	}
	printf("x0=%#x,x1=%#x\n",x0,x1);// 若x0=0x11,则是大端; 若x0=0x22,则是小端......

	// 测试共用体成员的内存分布
	printf("-------------------\n");
	funtest3();

    return 0;

}
