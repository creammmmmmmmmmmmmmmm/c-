#pragma once
typedef enum {
    distSelf,
    distHeld,
    distHeldContained,
    distLocation,
    distHere,
    distHereContained,
    distOverthere,
    distNotHere,
    distUnknownObject
} DISTANCE;

extern int isHolding(OBJECT* container, OBJECT* obj);
//�Ƿ��������
extern OBJECT* getPassage(OBJECT* from, OBJECT* to);
//��ȡͨ��
extern DISTANCE getDistance(OBJECT* from, OBJECT* to);
//�������
extern OBJECT* actorHere(void);
extern int listObjectsAtLocation(OBJECT* location);
