#include "server.h"
using namespace std;

Server::Server(){
	this->ip = "123.123.123.123";
	this->port = 1234;
	this->curPeerId = 0;

}

int Server::Connect() {
	

	/*
	1. using socket to connect to a real server
	2. the real server will add this client to  node table
	3. we need to open a listen socket in case that the server updates other nodes
	*/
	int oldPeerId = this->curPeerId++;
	return oldPeerId;
}

int Server::addPeer(Peer* peer) {
	if (this->peerTable.size() == 0) {
		this->peerTable[peer->id] = peer;
		this->activePeerTable[peer->id] = peer;
	}
	else {
		this->peerTable[peer->id] = peer;
	}
	return 0;
}

int Server::deletePeer(int peerId) {
	this->activePeerTable.erase(peerId);
	return 0;
}