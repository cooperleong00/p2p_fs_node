#include "peer.h"
using namespace std;

Peer::Peer() {
	this->id = -1;
	this->ip = "0.0.0.0";
	this->port = 12345;
	this->bandWidth = 100;
	this->disconnectRate = 0;
	this->connectedTime = -1;
	this->spaceSize = 1;
	this->spacePrice = 1;
}