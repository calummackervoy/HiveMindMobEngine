#pragma once
#include "Typedef.h"

//Author: Calum Mackervoy
//Purpose: models a basic network for use in the game..
//example uses: transport network, AI (GOAP), intranet for hacking sim etc

const suint MAX_NODES = 255;

struct Node {
	suint id;
};

struct NodePath {
	suint* ids;
	suint numNodes;
};

class Network {
public:
	Network();
	~Network();

	NodePath findPath(suint start, suint dest);
	
protected:
	Node* net[MAX_NODES];
};