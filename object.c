#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "object.h"

static const char* tags0[] = { "field", NULL };
static const char* tags1[] = { "cave", NULL };
static const char* tags2[] = { "silver", "coin", "silver coin", NULL };
static const char* tags3[] = { "gold", "coin", "gold coin", NULL };
static const char* tags4[] = { "guard", "burly guard", NULL };
static const char* tags5[] = { "yourself", NULL };
static const char* tags6[] = { "east", "entrance", NULL };
static const char* tags7[] = { "west", "exit", NULL };
static const char* tags8[] = { "west", "north", "south", "forest", NULL };
static const char* tags9[] = { "east", "north", "south", "rock", NULL };

OBJECT objs[] =
{
   {"an open field"				 , tags0, NULL  ,NULL, NULL,"The field is a nice and quiet place under a clear blue sky.",NULL													,NULL												,9999		,9999,NULL},
   {"a little cave"			     , tags1, NULL  ,NULL, NULL,"The cave is just a cold, damp, rocky chamber."              ,NULL													,NULL												,9999		,9999,NULL},
   {"a silver coin"				 , tags2, field ,NULL, NULL,"The coin has an eagle on the obverse."                      ,NULL													,NULL												,1			,NULL,NULL},
   {"a gold coin"				 , tags3, cave  ,NULL, NULL,"The shiny coin seems to be a rare and priceless artefact."  ,NULL													,NULL												,1			,NULL,NULL},
   {"a burly guard"				 , tags4, field ,NULL, NULL,"The guard is a really big fellow."                          ,"He has"				                                ,NULL												,NULL		,20	 ,100 },
   {"yourself"					 , tags5, field ,NULL, NULL,"You would need a mirror to look at yourself."				 ,"You have"										    ,NULL												,NULL		,20  ,100 },
   {"a cave entrance to the east", tags6, field ,cave,field,"The entrance is just a narrow opening in a small outcrop."  ,NULL													,"The guard stops you from walking into the cave."	,9999		,NULL,NULL},
   {"an exit to the west"        , tags7, cave ,field, field,"Sunlight pours in through an opening in the cave's wall."  ,NULL													,"You walk out of the cave."						,9999		,NULL,NULL},
   {"dense forest all around"    , tags8, field, NULL, NULL,"The field is surrounded by trees and undergrowth."			 ,NULL													,"Dense forest is blocking the way."				,9999		,NULL,NULL},
   {"solid rock all around"      , tags9, cave , NULL, NULL,"Carved in stone is a secret password 'abccb'."				 ,NULL													,"Solid rock is blocking the way."					,9999		,NULL,NULL}
};	