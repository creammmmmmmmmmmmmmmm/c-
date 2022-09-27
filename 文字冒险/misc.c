#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "object.h"

OBJECT *actorHere(void)
{
	OBJECT* obj;
	for (obj = objs; obj < endOfObjs; obj++)
	{
		if (obj->location == player->location && obj == guard)
		{
			return obj;
		}
	}
	return NULL;
}



int listObjectsAtLocation(OBJECT* location)
{
	int count = 0;
	OBJECT* obj;
	for (obj = objs; obj < endOfObjs; obj++)
	{
		if (obj != player && obj->location == location)//排除玩家在玩家的位置这种&&物体位置与玩家位置相同
		{
			if (count++ == 0)//这里是为了判断若第一次进入循环先打印you see，若不是就打印物品
			{
				printf("You see:\n");
			}
			printf("%s\n", obj->description);
		}
	}
	return count;//返回物品的数量
}