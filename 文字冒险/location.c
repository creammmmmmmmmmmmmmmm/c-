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
		printf("I don't understand what you want to see.\n");
	}
}

void executeGo(const char* noun)
{
	OBJECT* obj = getVisible("where you want to go", noun);
	switch (getDistance(player, obj))
	{
	case distOverthere:
		printf("OK.\n");
		player->location = obj;
		executeLook("around");
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