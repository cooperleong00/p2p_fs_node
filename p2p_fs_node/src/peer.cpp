#include "peer.h"
using namespace std;

Peer::Peer() {
	id = -1;
	this->ip = "127.0.0.1";
	this->port = 12345;
	bandWidth = 100;
	disconnectRate = 0;
	connectedTime = -1;
	spaceSize = 1;
	spacePrice = 1;
}

Peer::Peer(string ip, int port) {
	id = -1;
	this->ip = ip;
	this->port = port;
	bandWidth = 100;
	disconnectRate = 0;
	connectedTime = -1;
	spaceSize = 1;
	spacePrice = 1;
}

json Peer::toJson() {
	json dict;
	dict["id"] = id;
	dict["ip"] = ip;
	dict["port"] = port;
	dict["bandWidth"] = bandWidth;
	dict["disconnectRate"] = disconnectRate;
	dict["connectedTime"] = connectedTime;
	dict["spaceSize"] = spaceSize;
	dict["spacePrice"] = spacePrice;
	return dict;
}