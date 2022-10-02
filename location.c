#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include "object.h"
#include "misc.h"
#include "noun.h"


//#define numberOfLocations (sizeof objs/sizeof *objs)//��objs�Ǹ����飬*objs�������е�һ��Ԫ�صĴ�С������������Ĵ�Сȥ���Ե�һ��Ԫ�ش�С����������*����Ϊ�Լ�������
//static unsigned locationOfPlayer = 0; �ѱ����ã�����ѧϰ��¼

void executeLook(const char *noun)
{
	if (noun != NULL && strcmp(noun, "around") == 0)
	{
		printf("You are in %s.\n", player->location->description);
		listObjectsAtLocation(player->location);//�г���ǰ�ص���ڵ���Ʒ
	}
	else
	{
		OBJECT* obj = getVisible("what you want to look at", noun);
		switch (getDistance(player, obj))
		{
		case distHereContained:
			printf("Hard to see, try to get it first.\n");
			break;
		case distOverthere:
			printf("Too far away, move closer please.\n");
			break;
		case distNotHere:
			printf("You don't see any %s here.\n", noun);
			break;
		case distUnknownObject:
			// already handled by getVisible
			break;
		default:
			printf("%s\n", obj->details);
			listObjectsAtLocation(obj);
		}
	}
}
static void movePlayer(OBJECT* passage)
{
	printf("%s\n", passage->textGo);
	if (passage->destination != NULL)
	{
		player->location = passage->destination;
		printf("\n");
		executeLook("around");
	}
}
void executeGo(const char* noun)
{
	OBJECT* obj = getVisible("where you want to go", noun);
	switch (getDistance(player, obj))
	{
	case distOverthere:
		movePlayer(getPassage(player->location, obj));
		break;
	case distNotHere:
		printf("You don't see any %s here.\n", noun);
		break;
	case distUnknownObject://�ѱ�getVisible����
		break;
	default:
		if (obj->destination != NULL)
		{
			printf("OK.\n");
			player->location = obj->destination;//���������һ��ͨ�����������ִ�Ŀ�ĵ�
			executeLook("around");
		}
		else
		{
			printf("You can't get much closer than this.\n");
		}
	}
}