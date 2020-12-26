#ifndef CLIENT_H
#define CLIENT_H
#include <bits/stdc++.h>
#include "server.h"
#include "peer.h"
using namespace std;

class Client{

public:
	Peer myPeer;
	map<int,Peer*> peerTable;
	Server* centralServer;
	
	Client();
	
	int Connect2Peer(string peerId);

	int Connect2Sever(Server* centralServer);

	int keepConnection(int peerId);

	int quitNetwork();

	int assessPerformance();

	int assessCrediblity();
};

#endif // !CLIENT_H