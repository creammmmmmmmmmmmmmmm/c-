
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "object.h"
#include "misc.h"
static int objectHasTag(OBJECT* obj, const char* noun)//�ж�����������Ƿ���ȷ��Ӧ��Ʒ�ı�ǩ���������Ǹ�������ѭ��ʹ�ã������ж�������Ƿ���ĳ����Ʒ�ı�ǩ
{
    if(noun != NULL && *noun != '\0');
    {
        char** tag;
        for (tag = obj->tags; *tag != NULL; tag++)
        {//tag**ָ�����tag*����tag��һ�����飬tag*ָ����tag�ĵ�һ��Ԫ�أ����������ľ���
            if ( strcmp(*tag, noun) == 0) 
                return 1;
        }
    }
    return 0;
}
static OBJECT ambiguousNoun;

static OBJECT* getObject(const char* noun, OBJECT* from, DISTANCE maxDistance)
{
    OBJECT* obj, * res = NULL;
    for (obj = objs; obj < endOfObjs; obj++)
    {
        if (objectHasTag(obj, noun) && getDistance(from, obj) <= maxDistance)//�ж������Ƿ��ڿɵ��ﷶΧ
        {
            res = res == NULL ? obj : &ambiguousNoun;//????????????????
        }
    }
    return res;
}

OBJECT* getVisible(const char* intention, const char* noun)
{
    OBJECT* obj = getObject(noun,player,distNotHere);
    if (obj == NULL)
    {
        if (getObject(noun, player, distNotHere) == NULL)
        {
            printf("I don't understand %s.\n", intention);
        }
        else
        {
            printf("You don't see any %s here.\n", noun);
        }
    }
    else if (obj == &ambiguousNoun)//ģ��ƥ��
    {
        printf("Please be specific about which %s you mean.\n", noun);
        obj = NULL;
    }
    return obj;
}

OBJECT* getPossession(OBJECT* from, const char* verb, const char* noun)
{
    OBJECT* obj = NULL;
    if (from == NULL)
    {
        printf("I don't understand who you want to %s.\n", verb);
    }
    else if ((obj = getObject(noun, player, distHeldContained)) == NULL)//obj���ڿɲ�����Χ��
    {
        if (getObject(noun, player, distNotHere) == NULL)
        {
            printf("I don't understand what you want to %s.\n", verb);
        }
        else if (from == player)
        {
            printf("You are not holding any %s.\n", noun);
        }
        else
        {
            printf("There appears to be no %s you can get from %s.\n",
                noun, from->description);
        }
    }
    else if (obj == from)
    {
        printf("You should not be doing that to %s.\n", obj->description);
        obj = NULL;
    }
    else if (obj == &ambiguousNoun)//ģ��ƥ��
    {
        printf("Please be specific about which %s you want to %s.\n",noun, verb);
        obj = NULL;
    }
    return obj;
}