#include "server.h"
using namespace std;

Server::Server(){
	Server("127.0.0.1",1234);
}

Server::Server(string ip, int port) {
	this->ip = ip;
	this->port = port;
	this->curPeerId = 0;


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