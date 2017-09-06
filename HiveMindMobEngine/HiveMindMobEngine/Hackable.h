#pragma once
#include "Access.h"

//TODO: rename to "System"?
class Hackable {
public:
    Hackable();
    ~Hackable();

    //should test accesses inputted & returns true if function granted
    bool attemptHack(Access &a, bool usingPriv = true) = 0;
    //function to find out if the function above involves honeypots and alerts
    bool hasHoneyPot(AccessAction a) = 0;
    bool hasAlert(AccessAction a) = 0;

protected:
    //TODO: provide functions for children to use carrying out honeypots & alerts
};