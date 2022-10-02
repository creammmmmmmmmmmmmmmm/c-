#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include "object.h"
#include "misc.h"
#include "noun.h"


//#define numberOfLocations (sizeof objs/sizeof *objs)//，objs是个数组，*objs是数组中第一个元素的大小，用整个数组的大小去除以第一个元素大小，数组遇到*就认为自己传参了
//static unsigned locationOfPlayer = 0; 已被弃用，留作学习记录

void executeLook(const char *noun)
{
	if (noun != NULL && strcmp(noun, "around") == 0)
	{
		printf("You are in %s.\n", player->location->description);
		listObjectsAtLocation(player->location);//列出当前地点存在的物品
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
	case distUnknownObject://已被getVisible处理
		break;
	default:
		if (obj->destination != NULL)
		{
			printf("OK.\n");
			player->location = obj->destination;//若玩家走向一条通道，就让他抵达目的地
			executeLook("around");
		}
		else
		{
			printf("You can't get much closer than this.\n");
		}
	}
}