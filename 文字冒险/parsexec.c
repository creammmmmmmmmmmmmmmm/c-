#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <string.h>
#include "location.h"
#include "noun.h"
#include"inventory.h"
#include <stdbool.h>
int parseAndExecute(char *input)
{	//下一行这个函数第一个参数是数组，第二个参数是间断符，遇到任何一个都会间断，比如下面是空格和换行间断
	char* verb = strtok(input," \n");//这个函数第一个参数不是NULL，所以它会记录第一个\n的位置,这个函数输出的是这个\n的位置指针，要用指针接受
	char* noun = strtok(NULL," \n");//这个函数第一个参数是NULL，他会从记录的那个位置开始继续查找
	if (verb != NULL)//返回值如果是NULL说明input有读入
	{
		if (strcmp(verb, "quit") == 0)
		{
			return false;//返回值为false会导致主循环结束
		}
		else if (strcmp(verb, "look") == 0)
		{
			executeLook(noun);
		}
		else if (strcmp(verb, "go") == 0)
		{
			executeGo(noun);
		}
		else if (strcmp(verb, "get") == 0)
		{
			executeGet(noun);
		}
		else if (strcmp(verb, "give") == 0)
		{
			executeGive(noun);
		}
		else if (strcmp(verb, "ask") == 0)
		{
			executeAsk(noun);
		}
		else if (strcmp(verb, "drop") == 0)
		{
			executeDrop(noun);
		}
		else if (strcmp(verb, "inventory") == 0)
		{
			executeInventory();
		}
		else
		{
			printf("I don't know how to '%s'.\n", verb);
		}
	}
	return true;//返回正确处理结果，继续处理
}