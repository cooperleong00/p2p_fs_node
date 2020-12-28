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
	json j;
	j["id"] = id;
	j["ip"] = ip;
	j["port"] = port;
	j["bandWidth"] = bandWidth;
	j["disconnectRate"] = disconnectRate;
	j["connectedTime"] = connectedTime;
	j["spaceSize"] = spaceSize;
	j["spacePrice"] = spacePrice;
	return j;
}

Peer* Peer::json2Peer(json j) {
	Peer* p = new Peer();
	p->id = j["id"];
	p->ip = j["ip"];
	p->port = j["port"];
	p->bandWidth = j["bandWidth"];
	p->disconnectRate = j["disconnectRate"];
	p->connectedTime = j["connectedTime"];
	p->spaceSize = j["spaceSize"];
	p->spacePrice = j["spacePrice"];
	return p;
}