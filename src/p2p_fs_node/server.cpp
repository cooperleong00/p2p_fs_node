#include "server.h"
using namespace std;

Server::Server(){
	this->ip = "123.123.123.123";
	this->port = 1234;
	this->curPeerId = 0;

}

int Server::Connect() {
	

	/*
	using socket to connect to a real server
	*/
	int oldPeerId = this->curPeerId++;
	return oldPeerId;
}

int Server::updatePeerTable(Peer* peer) {
	if (this->peerTable.size() == 0) {
		this->peerTable[peer->id] = peer;
		this->activePeerTable[peer->id] = peer;
	}
	else {
		this->peerTable[peer->id] = peer;
	}
}