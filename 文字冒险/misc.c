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