// 10.9练习.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include<math.h>

uint64_t multimod(uint64_t, uint64_t, uint64_t);

void test(uint64_t a, uint64_t b, uint64_t m) {
#define U64 "%" PRIu64
	printf(U64 " * " U64 " mod " U64 " = " U64 "\n", a, b, m, multimod(a, b, m));
}

int main() 
{
	test(123, 456, 789);
	test(123, 456, -1ULL);
	test(114514,1,52);
	test(-2ULL, -2ULL, -1ULL); // should be 1
	test(9223372036854775808, 9223372036854775808, 9223372036854775809);
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
