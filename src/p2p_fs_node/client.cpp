#include "client.h"
#include "peer.h"
using namespace std;


int Client::Connect2Sever(Server* centralServer) {
	int curPeerId;
	
	if(!centralServer->isConnected){
		curPeerId = centralServer->Connect();
	}
	if (&this->myPeer == nullptr) {
		this->myPeer = Peer();
		this->myPeer.id = curPeerId;
	}
	
	centralServer->addPeer(&this->myPeer);
	this->centralServer = centralServer;
	return 0;
}