#pragma once
#include "Access.h"

//TODO: rename to "System"?
//TODO: system map
class Hackable {
public:
    Hackable();
	//TODO: generate a System?
	~Hackable();

    //should test accesses inputted & returns true if function granted
    virtual bool attemptHack(Access &a, bool usingPriv = true) = 0;

	//TODO: get details about a system
	//function to find out if the function above involves honeypots and alerts
	bool hasHoneyPot(AccessAction a) { return honeyPot; };
	bool hasAlert(AccessAction a) { return alert; };

	//TODO: getting access to vulnerabilities by information

protected:
    //TODO: provide functions for children to use carrying out honeypots & alerts
	bool honeyPot;
	bool alert;
};