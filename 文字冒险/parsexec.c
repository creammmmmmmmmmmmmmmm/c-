#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <string.h>
#include "location.h"
#include "noun.h"
#include"inventory.h"
#include <stdbool.h>
int parseAndExecute(char *input)
{	//��һ�����������һ�����������飬�ڶ��������Ǽ�Ϸ��������κ�һ�������ϣ����������ǿո�ͻ��м��
	char* verb = strtok(input," \n");//���������һ����������NULL�����������¼��һ��\n��λ��,�����������������\n��λ��ָ�룬Ҫ��ָ�����
	char* noun = strtok(NULL," \n");//���������һ��������NULL������Ӽ�¼���Ǹ�λ�ÿ�ʼ��������
	if (verb != NULL)//����ֵ�����NULL˵��input�ж���
	{
		if (strcmp(verb, "quit") == 0)
		{
			return false;//����ֵΪfalse�ᵼ����ѭ������
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
	return true;//������ȷ����������������
}