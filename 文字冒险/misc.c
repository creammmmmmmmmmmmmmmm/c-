#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "object.h"
#include "misc.h"
int isHolding(OBJECT* container, OBJECT* obj)
{
	return obj->location != NULL && obj->location == container;
}
OBJECT* getPassage(OBJECT* from, OBJECT* to)
{
	if (from != NULL && to != NULL)
	{
		OBJECT* obj;
		for (obj = objs; obj < endOfObjs; obj++)
		{
			if (obj->location == from && obj->destination)
			{
				return obj;
			}
		}
	}
	return NULL;
}
DISTANCE getDistance(OBJECT* from, OBJECT* to)
{
	return to == NULL							   ? distUnknownObject ://没这玩意
		   to == from							   ? distSelf ://你想对自己做什么？
		   isHolding(from, to)					   ? distHeld ://物体被玩家持有
		   isHolding(to, from)					   ? distLocation ://物体是玩家的位置
		   isHolding(from->location, to)	       ? distHere ://物体位置等于玩家位置
		   isHolding(from, to->location)		   ? distHeldContained ://玩家持有一个含有目标物体的容器
		   isHolding(from->location, to->location) ? distHereContained ://含有该物体的容器与玩家在同一地点
		   getPassage(from->location, to) != NULL  ? distOverthere ://该物体与玩家所在地有通道连接
		                                             distNotHere;//物体不在这里
}

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