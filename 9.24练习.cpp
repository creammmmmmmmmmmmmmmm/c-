// 9.24练习.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<math.h>
//
//int main()
//{
//    char arr[] = "hello world";
//    memset(arr, '*', 5);
//    printf("%s", arr);
//    return 0;
//}
// 
//定义函数来交换ab的值，需要用取地址，在地址上进行交换，所以在函数中设置的变量是指针变量
//void swap(int* x, int* y)
//{
//	int tmp = 0;
//	tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//int main()
//{
//	int a = 10, b = 20;
//	swap(&a, &b);
//	printf("%d %d", a, b);
//	return 0;
//}
//输入数字，判断是否是素数，用函数表示
//int judge(int x)
//{
//	int i;
//	for (i = 2; i <= sqrt(x); i++)
//	{
//		if (x % i == 0)
//			return 0;//这个可以直接结束函数，无需break了
//	}
//		return 1;
//}
//
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	if (judge(a))
//		printf("%d", a);
//	else
//		printf("wrong");
//	return 0;
//}

//二分查找，函数模式，关于数组的传参
//int search(int x, int sum[],int sz)
//{
//	int left = 0;
//	int right = sz-1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (x < sum[mid])
//		{
//			right = mid - 1;
//		}
//		else if (x > sum[mid])
//		{
//			left = mid + 1;
//		}
//		else
//			return mid;
//	}
//	return -1;
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int a;
//	int sz = (sizeof(arr) / sizeof(arr[0]));
//	scanf("%d", &a);
//	int b = search(a, arr,sz);
//	if (b == -1)
//		printf("找不到");
//	else
//		printf("找到了，下标是%d", b);
//	return 0;
//}

//函数声明和定义
#include"add.h"
int main()
{
	int a = 1, b = 2;
	int sum = add(a, b);
	printf("%d", sum);
	return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
