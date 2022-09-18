// 9.18日练习.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
//密码输入确认
//int main()
//{
//    char password[20];
//    scanf("%s", password);
//    while ((getchar())!='\n')
//    {
//    
//    }
//    printf("请输入Y/N\n");
//    char a=getchar();
//    if (a == 'Y')
//    {
//        printf("确认成功");
//    }
//    else
//    {
//        printf("确认失败");
//    }
//    return 0;
//}


//只打印0~9
//int main()
//{
//	char ch;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch>'9')
//			continue;
//			printf("%c", ch);
//	}
//	return 0;
//}


//只打印1~10

//int main()
//{
//	int i = 0;
//	for (i = 1; i < 11; i++)
//	{
//		printf("%d", i);
//	}
//	return 0;
//}
//输入一个N，后面接N个数求和，要能连续计算而不退出程序
//int main()
//{
//	int N,i,a,sum=0;
//	scanf("%d", &N);
//	for (i = 1; i <= N; i++)
//	{
//		scanf("%d", &a);
//		sum += a;
//		if (i == N)
//		{
//			printf("%d", sum);
//			i = 0;
//			sum = 0;
//			scanf("%d", &N);
//		}
//	}
//	return 0;
//}

//输入N，求下面N行两个数的和
//int main()
//{
//	int N,i=1,a,b,c;
//	scanf("%d", &N);
//	while(i<=N)
//	{
//		scanf("%d%d", &a,&b);
//		c = a + b;
//		printf("%d\n",c);
//		i++;
//	}
//	return 0;
//}

//n的阶乘
//int main()
//{
//	int N,i=1;
//	long e = 1;
//	scanf("%d", &N);
//	do
//	{
//		e *= i;
//		i++;
//	}
//	while (i <= N);
//	printf("%d", e);
//	return 0;
//}
//

//1!+2!+....+n!
//int main()
//{
//	int N=0, i,e,f=1,sum=0;
//	scanf("%d",&N);
//	for (i = 1;i <= N; i++)
//	{
//		for (e = 1; e <=i; e++)
//		{
//			f *= e;
//		}
//		sum += f;
//	}
//	printf("%d", sum);
//	return 0;
//}


int main()
{
	int N,M,e;
	int arr[9999];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int sum = 0;
		scanf("%d", &M);
		for (int a = 0; a < M; a++)
		{
			scanf("%d", &e);
			sum += e;
		}
		arr[i] = sum;
	}
	for (int i = 0; i < N - 1;i++)
	{
		printf("%d\n\n", arr[i]);
	}
	printf("%d\n", arr[N - 1]);
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
