#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "object.h"
OBJECT objs[] = 
{
   {"an open field"  , "field"   , NULL  ,NULL},
   {"a little cave"  , "cave"    , NULL  ,NULL},
   {"a silver coin"  , "silver"  , field ,NULL},
   {"a gold coin"    , "gold"    , cave  ,NULL},
   {"a burly guard"  , "guard"   , field ,NULL},
   {"yourself"       , "player"  , field ,NULL},
   {"a cave entrance", "entrance", field ,cave},
   {"an exit"        , "exit"    , cave  ,field}
};