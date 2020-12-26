#include <bits/stdc++.h>
#include "peer.h"
using namespace std;

class Server{
public:
    string ip;
    int port;

    map<string,Peer> activePeerTable;
    map<string,Peer> peerTable;

    Server();
};