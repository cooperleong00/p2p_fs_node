#ifndef PEER_H
#define PEER_H
#include <bits/stdc++.h>

using namespace std;

class Peer{
	
public:
    int id;
    string ip;
    int port;
    float bandWidth;
    float disconnectRate;

    float spaceSize;
    float spacePrice;
    float connectedTime;

    Peer();
    
};
#endif // !PEER_H