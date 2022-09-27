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
	//�����ж�ǰ����Ƿ������������ִ�к����ֱ����
	else
	{
		printf("You get %s from %s.\n", obj->description, obj->location->description);
	}
}

void moveObject(OBJECT* obj, OBJECT* to)
{
	if (obj == NULL)      //���ƶ��ĸ�������
	{
		//�ѱ�����
	}
	else if (to == NULL)
	{
		printf("There is nobody here to give that to.\n");
	}
	else if (obj->location == NULL)  //��Щ�����޷�ʰȡ������ʶ���������ں���õ��Ľ�
	{
		printf("That is too heavy.\n");
	}
	else
	{
		describeMove(obj, to);//�ƶ�����
		obj->location = to;
	}
}