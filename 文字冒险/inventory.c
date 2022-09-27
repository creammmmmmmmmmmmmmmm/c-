#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include "location.h"
#include "parsexec.h"
#include "object.h"
#include "noun.h"
#include "move.h"
#include"misc.h"

void executeGet(const char *noun)//����Ƿ�Ϸ����Ұ���
{
	OBJECT* obj = getVisible("what you want to get", noun);
	if (obj == NULL)
	{
		//�ѱ�����
	}
	else if (obj == player)
	{
		printf("You should not be doing that to yourself.\n");
	}
	else if (obj->location == player)
	{
		printf("You already have %s.\n", obj->description);
	}
	else if (obj->location == guard)
	{
		printf("You should ask %s nicely.\n", obj->location->description);
	}
	else
	{
		obj->location = player;
		printf("You get %s\n", obj->description);
		//moveObject(obj, player);
		//���ڽ������䵽����λ��
	}
}
void executeDrop(const char* noun)
{
	moveObject(getPossession(player, "drop", noun), player->location);
}
void executeAsk(const char* noun)
{
	moveObject(getPossession(actorHere(), "ask", noun), player);
}
void executeGive(const char* noun)
{
	moveObject(getPossession(player, "give", noun), actorHere());
}
void executeInventory(void)
{
	if (listObjectsAtLocation(player) == 0)  //��������ֵ���������ж��ٸ�����
	{
		printf("You are empty-handed.\n"); //�����û�ɶҲû��
	}
}