#ifndef CLIENT_H
#define CLIENT_H
#include <bits/stdc++.h>
#include <winsock2.h>
#include "server.h"
#include "peer.h"
using namespace std;

#pragma comment(lib, "ws2_32.lib")

class Client{

public:
	Peer myPeer;
	map<int,Peer*> peerTable;
	Server* centralServer;
	
	Client();
	
	int Connect2Peer(string peerId);

	int Connect2Sever();

	int keepConnection(int peerId);

	int quitNetwork();

	int assessPerformance();

	int assessCrediblity();
};

#endif // !CLIENT_H