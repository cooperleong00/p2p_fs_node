#include <bits/stdc++.h>
#include "server.h"
#include "peer.h"
using namespace std;

class client{

public:
	Peer myPeer;
	map<string,Peer*> peerTable;
	Server* centralServer;
	
	client();
	
	int Connect2Peer(string peerId);

	int Connect2Sever(Server* centralServer);

	int keepConnection();

	int quitNetwork();

	int assessPerformance();

	int assessCrediblity();
};
