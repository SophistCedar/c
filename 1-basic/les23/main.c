#include<stdio.h>
#define N 10000
void bubble_sort(int arr[],int len)
{
    int i,j,tmp;
    for(i=0;i<len-1;i++)
    {
        for(j=0;j<len-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

//删除数组内的重复元素，返回新的数组长度
int del_same(int arr[],int len)
{
    int i,j,k;// for loop
    for (i = 0; i < len; i++)//遍历所有的值
    {
        for (j = i + 1; j < len;)//对于每一个元素，遍历该元素后面所有的元素，判断后面是否有相同的值
        {
            if (arr[j] == arr[i])//如果该元素与后面有相同元素
            {
                for (k = j; k < len; k++)//将后面的所有元素全部前移一位
                {
                    arr[k] = arr[k + 1];
                }
                len--;//此时数组长度减 1
            }
            else
            {
                j++;//如果和后面的元素不相等，依次判断，继续遍历
            }
        }
    }
    return len;//返回数组长度
}

int main()
{
    int num;
    int arr[N];
    
    while (scanf("%d", &num) != EOF)
    {
        for (int i=0; i < num; i++)
            scanf("%d", &arr[i]);
        int length=del_same(arr,num);                    //去重
        bubble_sort(arr,length);                             //排序
        for (int i=0; i<length; i++)       //输出
            printf("%d\n", arr[i]);
    }
    return 0;
}
/*
题目描述
明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了N个1到1000之间的随机整数（N≤1000），对于其中重复的数字，只保留一个，
把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。
请你协助明明完成“去重”与“排序”的工作(同一个测试用例里可能会有多组数据，希望大家能正确处理)。

Input Param
n               输入随机数的个数
inputArray      n个随机整数组成的数组

Return Value
OutputArray    输出处理后的随机整数

注：测试用例保证输入参数的正确性，答题者无需验证。测试用例不止一组。
样例输入解释：
样例有两组测试
第一组是3个数字，分别是：2，2，1。
第二组是11个数字，分别是：10，20，40，32，67，40，20，89，300，400，15。

输入描述:
输入多行，先输入随机整数的个数，再输入相应个数的整数
输出描述:
返回多行，处理后的结果
*/