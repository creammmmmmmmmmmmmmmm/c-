// ConsoleApplication6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

int main()
{
	int N, a=0, b=0, e = 0, f = 0;
	float average1, average2,average, c = 0, d = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		if (a == 1) {
			c += b;
			e++;
		}
		if (a == 0) {
			d += b;
			f++;
		}
	}
	average = (d + c) / (e + f);
	if (e == 0) {
		average2 = d / f;
		printf("%f.1X %.1f\n", average,average2);
	}
	if (f == 0) {
		average1 = c / e;
		printf("%.1f%.1f X\n",average, average1);
	}
	else {
		average1 = c / e;
		average2 = d / f;
		printf("%.1f %.1f %.1f\n", average,average1, average2);
	}
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
