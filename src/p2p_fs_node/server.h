#ifndef SERVER_H
#define SERVER_H
#include <bits/stdc++.h>
#include "peer.h"
using namespace std;

/*
central server simulator
*/

class Server{
public:
    bool isConnected;
    string ip;
    int port;
    int curPeerId; 

    map<int,Peer*> activePeerTable;
    map<int,Peer*> peerTable;

    Server();

    int Connect();
    int addPeer(Peer* peer);
    int deletePeer(int peerId);
};
#endif // !SERVER_H