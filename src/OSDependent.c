#include "OSDependent.h"

 struct SOSFunctions handlers[BT_NUMOS] = {0};

const struct SOSFunctions* GetOSFunctions(){
    return &handlers[BT_OSTYPE];
}