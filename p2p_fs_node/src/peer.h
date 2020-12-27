#ifndef PEER_H
#define PEER_H
#include <bits/stdc++.h>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

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
    Peer(string ip, int port);
    
    json toJson();
};
#endif // !PEER_H