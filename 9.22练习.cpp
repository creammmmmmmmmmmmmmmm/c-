// 9.22练习.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

//输入三个数，按从大到小输出
//int main()
//{
//    int a, b, c;
//    scanf("%d %d %d", &a, &b, &c);
//    if (a < b)
//    {
//        int tmp;
//        tmp = a;
//        a = b;
//        b = tmp;
//    }
//    if (a < c)
//    {
//        int tmp;
//        tmp = a;
//        a = c;
//        c = tmp;
//    }
//    if (b < c)
//    {
//        int tmp;
//        tmp = b;
//        b = c;
//        c = tmp;
//    }
//    printf("%d %d %d\n", a, b, c);
//    return 0;
//}



//int main()
//{
//	double x;
//	scanf("%lf", &x);
//	printf("%.2lf", x);
//
//}
//求最大公约数，辗转相除法
//int main()
//{
//	int m, n,r;
//	scanf("%d %d", &m, &n);
//	while (m % n)
//	{
//		r = m % n;
//		m = n;
//		n = r;
//	}
//	printf("%d", n);
//	return 0;
//}
//打印素数,这是优化后的，sqrt是开平方
int main()
{
	int a;
	int i = 2;
	scanf("%d", &a);
	while(i<=sqrt(a))
	{
		if (a % i!=0)
			i++;
		else
			break;
	}
	if (i >sqrt(a))
		printf("yes");
	else
		printf("no");
	return 0;
}





// 
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
