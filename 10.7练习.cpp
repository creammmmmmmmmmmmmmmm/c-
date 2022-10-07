// 10.7练习.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//zr的噩梦

int check(int n, int m, int k)
{
	if (n > m)
	{
		if (k == m)
		{
			return 1;
		}
		if (m > n)
			return 0;
		if (m > k)
		{
			k = n - m + k;
		}
		else if (m < k)
		{
			k = k - m;
		}
		n -= 1;
		m += 1;
		check(n, m, k);

	}
}

int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	if (check(n, m, k))
		printf("yes");
	else
		printf("no");
}




