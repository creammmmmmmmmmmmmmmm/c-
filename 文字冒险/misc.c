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
	return to == NULL							   ? distUnknownObject ://û������
		   to == from							   ? distSelf ://������Լ���ʲô��
		   isHolding(from, to)					   ? distHeld ://���屻��ҳ���
		   isHolding(to, from)					   ? distLocation ://��������ҵ�λ��
		   isHolding(from->location, to)	       ? distHere ://����λ�õ������λ��
		   isHolding(from, to->location)		   ? distHeldContained ://��ҳ���һ������Ŀ�����������
		   isHolding(from->location, to->location) ? distHereContained ://���и�����������������ͬһ�ص�
		   getPassage(from->location, to) != NULL  ? distOverthere ://��������������ڵ���ͨ������
		                                             distNotHere;//���岻������
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
		if (obj != player && obj->location == location)//�ų��������ҵ�λ������&&����λ�������λ����ͬ
		{
			if (count++ == 0)//������Ϊ���ж�����һ�ν���ѭ���ȴ�ӡyou see�������Ǿʹ�ӡ��Ʒ
			{
				printf("You see:\n");
			}
			printf("%s\n", obj->description);
		}
	}
	return count;//������Ʒ������
}