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
		printf("I don't understand what you want to see.\n");
	}
}

void executeGo(const char *noun)
{
	OBJECT *obj= getVisible("where you want to go", noun);
	if(obj==NULL)
	{
	 //�ѱ�getvisisible����
	}
	else if (obj->location == NULL && obj->location != player->location)
	{
		printf("OK.\n");
		player->location = obj;
		executeLook("around");
	}
	else
	{
		printf("You can't get much closer than this.\n");
	}
}