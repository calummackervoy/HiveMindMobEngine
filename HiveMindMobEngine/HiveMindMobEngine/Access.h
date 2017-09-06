#pragma once
#include "Item.h"

//Author: Calum Mackervoy
//Purpose: (part of hacking system) obtained with vulnerabilties --> must have sequence overcoming all guards

//TODO: split into Lock and Key

class Access {
public:
    Access(Privilege priv = PRIVILEGE_OUTSIDER, AccessAction action = ACCESS_DDOS);
    ~Access();

    inline Privilege getPriv() {return priv;};
    inline AccessAction getAction() {return action;};

    inline void setPriv(Privilege val) {priv = val;};
    inline void setAction(AccessAction val) {action = val;};

    //TODO: adding, removing & getting required vulnerabilties

protected:
    //TODO: required vulnerabilties vector

    //access attempts will use a privilege type (can be user or access to specific element)
    Privilege priv;
    //access attempts will have a target action being attempted by the hacker
    AccessAction action;
};