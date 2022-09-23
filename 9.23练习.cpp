// 9.23练习.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<stdlib.h>
#include<time.h>
//乘法口诀表
//int main()
//{
//    for (int i = 1; i <= 9; i++)
//    {
//        for (int j = 1; j <= i; j++)
//        {
//            printf("%d*%d=%-2d ", i, j, i * j);
//        }
//        printf("\n");
//    }
//    return 0;
//}
//猜数字游戏
//void menu()
//{
//	printf("*****************************************\n");
//	printf("*************1.play    0.exit************\n");
//	printf("*****************************************\n");
//}
//void game()
//{
//	int b,c,x;
//	b = rand();
//	c = (b % 100)+1;
//	while (1)
//	{
//		printf("请输入你的猜测\n");
//		scanf("%d", &x);
//		if (x < c)
//			printf("小了\n");
//		if (x > c)
//			printf("大了\n");
//		if (x == c)
//		{ 
//			printf("猜对了！\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	int a;
//	srand((unsigned int)time(NULL));//重置随机数生成器,不能频繁调用，所以扔进主函数里
//	do
//	{
//		menu();
//		printf("请选择\n");
//		scanf("%d", &a);
//		switch (a)
//		{
//			case 1:
//			{
//				game();
//			}	break;
//			case 0:
//			{
//				printf("退出游戏\n");
//				break;
//			}
//			default:
//			{
//				printf("输入错误\n");
//				break;
//			}
//		}
//	}while (a);
//	return 0;
//} 
//恶心人的关机程序

int main()
{
	system("shutdown -s -t 60");
again:
	printf("请注意，你的电脑将在一分钟内关机，除非输入我是猪\n");
	printf("请输入");
	char input[20];
	scanf("%s", &input);
	if (strcmp(input, "我是猪") == 0)
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
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
