#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include "object.h"
#include "misc.h"
static int weightOfContents(OBJECT* container)
{
	int sum = 0;
	OBJECT* obj;
	for (obj = objs; obj < endOfObjs; obj++)
	{
		if (isHolding(container, obj))
			sum += obj->weight;
	}
	return sum;
}

static void describeMove(OBJECT* obj, OBJECT* to)
{
	if (to == player->location)
	{
		printf("You drop %s.\n", obj->description);
	}
	else if (to!=player)
		printf(to->health>0 ? "You put %s in %s.\n" : "You put %s in %s.\n", obj->description, to->description);
	//？会判断前面的是否成立，成立就执行后面的直到：
	else if (obj->location == player->location)
	{
		printf("You pick up %s.\n", obj->description);
	}
	else
	{
		printf("You get %s from %s.\n", obj->description, obj->location->description);
	}
}

void moveObject(OBJECT* obj, OBJECT* to)
{
	if (obj == NULL)      //不移动的各种条件
	{
		//已被处理
	}
	else if (to == NULL)
	{
		printf("There is nobody here to give that to.\n");
	}
	else if (obj->weight>to->capacity)  //有些物体无法拾取
	{
		printf("That is too heavy.\n");
	}
	else if (obj->destination != NULL)
	{
		printf("You can't pick up the road.\n");
	}
	else if (obj->health > 0)
	{
		printf("You can't get the NPC.\n");
	}
	else if (obj->weight + weightOfContents(to) > to->capacity)
	{
		printf("That would become too heavy.\n");
	}
	else
	{
		describeMove(obj, to);//移动对象
		obj->location = to;
	}
}