// 9.20练习.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<Windows.h>
//展示，从两边到中间显示
//int main()
//{
//    char arr1[] = "welcome to bit";
//    char arr2[] = "##############";
//    int left = 0;
//    int right = strlen(arr1) - 1;
//    while (left < right)
//    {
//        arr2[left] = arr1[left];
//        arr2[right] = arr1[right];
//        left++;
//        right--;
//        printf("%s", arr2);
//        Sleep(1000);
//        system("cls");
//    }
//    printf("%s", arr1);
//    return 0;
//}
//输入密码，限制三次

//int main()
//{
//	char password[10]={0};
//	int i = 1;
//	while (i <= 3)
//	{
//		scanf("%s", password);
//		if (strcmp(password,"123456")==0)
//		{
//			printf("密码正确");
//			break;
//		}
//		else
//		{
//			printf("密码错误\n");
//			i++;
//		}
//	}
//	if (i == 4)
//	{
//		printf("别玩我！！！");
//	}
//	return 0;
//}


//复习昨日的二分查找
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k;
//	scanf("%d", &k);
//	int left = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (k < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else if (k > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else if (k = arr[mid])
//		{
//			printf("找到了，下标是%d", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到");
//	}
//	return 0;
//}

//复习
//int main()
//{
//	char arr1[] = "welcome to bit";
//	char arr2[] = "##############";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//	while (left < right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		left++;
//		right--;
//		printf("%s", arr2);
//		Sleep(500);
//		system("cls");
//	}
//	printf("%s", arr1);
//	return 0;
//}


//复习

//int main()
//{
//	int i;
//	char password[10];
//	for (i = 1; i <= 3; i++)
//	{
//		scanf("%s", &password);
//		if (strcmp(password,"123456")==0)
//		{
//			printf("密码正确");
//			break;
//		}
//		else
//		{
//			printf("密码错误\n");
//		}
//	}
//	if (i > 3)
//	{
//		printf("别耍我");
//	}
//	return 0;
//}

//复习18号的，输入一个N，计算下面N行整数的和，每行开头代表这行有几个待计算整数，本身不参与计算；
//int main()
//{
//	int i = 0;
//	int n, m, e;
//	int arr[9999];
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		int sum = 0;
//		scanf("%d", &m);
//		for (int a = 1; a <= m; a++)
//		{
//			scanf("%d", &e);
//			sum += e;
//		}
//		arr[i] = sum;
//	}
//	for (int b = 0; b <=i-1; b++)
//	{
//		printf("%d\n", arr[b]);
//	}
//	return 0;
//}


//复习平均分
//int main()
//{
//	int n, a, b, c=0, d=0;
//	double aver1, aver2, e=0, f=0;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d%d", &a, &b);
//		if (a == 0)
//		{
//			c++;
//			e += b;
//		}
//		else if (a == 1)
//		{
//			d++;
//			f += b;
//		}
//	}
//	if (c == 0)
//	{
//		aver1 = f / d;
//		printf("%.1f X", aver1);
//	}
//	else if (d == 0)
//	{
//		aver2 = e / c;
//		printf("X %.1f", aver2);
//	}
//	else
//	{
//		aver1 = f / b;
//		aver2 = e / c;
//		printf("%.1f %.1f", aver1, aver2);
//	}
//	return 0;
//}





// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
