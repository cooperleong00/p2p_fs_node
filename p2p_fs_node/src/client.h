#ifndef CLIENT_H
#define CLIENT_H
#include <bits/stdc++.h>
#include <thread>
#include <winsock2.h>
#include "peer.h"
using namespace std;

#pragma comment(lib, "ws2_32.lib")
#define MAX_SIZE 65536

class Client{

public:
	SOCKET cSocket;
	Peer myPeer;
	map<int,Peer*> peerTable;
	
	Client();

	Client(string ip, int port);
	
	int Connect2Peer(string peerId);

	int Connect2Sever(string sIp, int sPort);

	void listen();

	int keepConnection(int peerId);

	int quitNetwork();

	int assessPerformance();

	int assessCrediblity();
};

#endif // !CLIENT_H