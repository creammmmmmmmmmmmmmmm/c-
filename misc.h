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
//是否持有物体
extern OBJECT* getPassage(OBJECT* from, OBJECT* to);
//获取通道
extern DISTANCE getDistance(OBJECT* from, OBJECT* to);
//计算距离
extern OBJECT* actorHere(void);
extern int listObjectsAtLocation(OBJECT* location);
