#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include "location.h"
#include "parsexec.h"
#include "object.h"
#include "noun.h"
#include "move.h"
#include "misc.h"

void executeGet(const char* noun)//����Ƿ�Ϸ�����ʰ����Ʒ
{
	OBJECT* obj = getVisible("what you want to get", noun);
	switch (getDistance(player, obj))
	{
	case distSelf:
		printf("You should not be doing that to yourself.\n");
		break;
	case distHeld:
		printf("You already have %s.\n", obj->description);
		break;
	case distOverthere:
		printf("Too far away, move closer please.\n");
		break;
	case distUnknownObject:
		// �ѱ��ж��Ƿ���Ӻ�������
		break;
	default:
		if (obj->location != NULL && obj->location->health >0)
		{
			printf("You should ask %s nicely.\n", obj->location->description);
		}
		else
		{
			moveObject(obj, player);
		}
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