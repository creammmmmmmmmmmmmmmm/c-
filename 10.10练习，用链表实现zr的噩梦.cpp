// 10.10练习，用链表实现zr的噩梦.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define  _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<malloc.h>
typedef struct student
{
    int z;
    struct student *next;
}s;

s* s4;

s* creat(int m)
{
    s* head, * node, * end;
    head = (s*)malloc(sizeof(s));
    end = head;
    for (int i = 0; i < m; i++)
    {
        node = (s*)malloc(sizeof(s));
        end->next = node;
        end = node;
    }
    end->next = head->next;
    return head;
}

void zr(int n,s* s1)
{
    s* t = s1;
    for (int i = 0; i < n; i++)
    {
        s1->z = i + 1;
        s1 = s1->next;
    }
}

s* del(s* s1,s* s2)
{
    s* s3 = s1;
    while (s3->next != s2)
    {
        s3 = s3->next;
    }
    return s3;
}

bool check(s* s1, int m,int k)
{
    s* s2= s1;
    for (int i = 0; i < m-1; i++)
    {
        s2 = s2->next;
    }
    if (s2 == NULL)
        return false;
    if (s2->z == k)
    {
        return true;
    }
    else
    {
        s* s3 = del(s1, s2);
        s3->next = s2->next;
        s4 = s3->next;
        return false;
    }
}

int main()
{
    int m, n, k;
    scanf("%d %d %d", & m, &n, &k);
    if (m == 0 && n == 0 && k == 0)
    {
        printf("别耍我");
        return 0;
    }
    static s* s1=creat(m);
    zr(m, s1);
    while (1)
    {
        if (check(s1, n, k) == true)
        {
            break;
        }
        s1 = s4;
        m -= 1;
        if (m < n)
        {
            printf("no");
            return 0;
        }
    }
    printf("yes");
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
