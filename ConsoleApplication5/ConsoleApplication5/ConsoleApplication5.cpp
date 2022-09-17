// ConsoleApplication5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include<stdio.h>

//int MAX(int x, int y)
//{
//    if (x > y)
//    {
//        return x;
//    }
//    else
//    {
//        return y;
//    }
//}
//int main()
//{
//    int max;
//    max=MAX(1, 2);
//    printf("%d", max);
//    return 0;
//}
//
//
//
//#include <stdio.h>
//
//     
//
//int main()
// {
//   int N,a=1;
//
//   scanf("%d", &N);
//   while (a <= N)
//   {
//       printf("%d\n", a);
//       a++;
//   }
//
//  return 0;
// }
//
//     /* 你的代码将被嵌在这里 */



//int main()
//{
//    int a = 0;
//    
//    scanf("%d", &a);
//    if (scanf("%d", &a) != 1)
//    {
//        printf("yes%d",a);
//    }
//    return 0;
//}

//int main() {
//
//    int k;
//    if (scanf("%d", &k) != 1) {	// 使用更严格的方式来使用输入和输出
//        printf("请输入整数!");
//    }
//    
//    return 0;
//}

//
//int main()
//{
//    char ch;
//
//    scanf("%3c", &ch);
//    printf("%c", ch);
//
//}


struct book
{
  char name[20];
  short price;
}; 

int main()
{
    struct book b1 = { "C语言程序设计基础",55};
    //描述了b1书
    char a[20];
    int b;
    scanf("%s %d", &a,&b);
    strcpy(b1.name, a);
    b1.price = b;
    printf("书名 = % s\n", b1.name);
    printf("价格 = % d\n", b1.price);//打印书中内容
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
