#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "object.h"

static void describeMove(OBJECT* obj, OBJECT* to)
{
	if (to == player->location)
	{
		printf("You drop %s.\n", obj->description);
	}
	else if (to!=player)
		printf(to == guard ? "You put %s in %s.\n" : "You put %s in %s.\n", obj->description, to->description);
	//？会判断前面的是否成立，成立就执行后面的直到：
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
	else if (obj->location == NULL)  //有些物体无法拾取，具体识别条件将在后面得到改进
	{
		printf("That is too heavy.\n");
	}
	else
	{
		describeMove(obj, to);//移动对象
		obj->location = to;
	}
}