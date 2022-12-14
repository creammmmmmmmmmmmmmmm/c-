// 9.30练习.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//递归
//void print(int a)
//{
//    if (a > 9)
//    {
//        print(a/10);
//    }
//    
//    printf("%d ", a % 10);
//}
//
//int main()
//{
//    int m;
//    scanf("%d", &m);
//    print(m);
//    return 0;
//}

//写一个自己的strlen函数

//int mystrlen(char* a)
//{
//	int m=0;
//	if (*a != '\0')
//	{
//		return 1 + mystrlen(a + 1);
//	}
//	else 
//	return 0;
//}
//int main()
//{
//	char a[] = "bit";
//	printf("%d", mystrlen(a));
//	return 0;
//}

//递归实现阶乘

//int fac(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * fac(n - 1);
//}
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	int b = fac(a);
//	printf("%d", b);
//	return 0;
//}

//求斐波那契数列(这玩意效率极低)

//int fb(int a)
//{
//	if (a > 2)
//	{
//		return fb(a - 1) + fb(a - 2);
//	}
//	else
//		return 1;
//}
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	printf("%d", fb(a));
//	return 0;
//}

//来个高效的

//int fb(int n)
//{
//	if (n > 2)
//	{
//		int a, b, c;
//		a = 1, b = 1;
//		for (int i = 3; i <= n; i++)
//			c = a + b, a = b, b = c;
//		return c;
//	}
//	else
//		return 0;
//}
//
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	printf("%d", fb(a));
//	return 0;
//}

//汉诺塔问题
//int main()
//{
//	void turn(int n, char a, char b, char c);//声明hanoi函数
//	int m;
//	printf("请输入总数:");
//	scanf("%d", &m);
//	printf("移动步骤为:\n");
//	turn(m, 'A', 'B', 'C');
//	return 0;
//}
//
//void turn(int n, char a, char b, char c)
//{
//	void move(char a, char c);
//	if (n == 1)
//		move(a, c);
//	else
//	{
//		turn(n - 1, a, c, b);
//		move(a, c);
//		turn(n - 1, b, a, c);
//	}
//}
//
//void move(char x, char y)
//{
//	printf("从%c移到%c\n", x, y);
//}

//青蛙跳台阶问题，可以化为斐波那契数列问题，高效方法同上
#include<math.h>
int jump(int n)
{
	if ( n == 1 )
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	else if (n > 2)
	{
		int i = jump(n - 1) + jump(n - 2);
		return i;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", jump(n));
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
