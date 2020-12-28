#ifndef SERVER_H
#define SERVER_H
#include <bits/stdc++.h>
#include <thread>
#include <winsock2.h>
#include "peer.h"
using namespace std;

#pragma comment(lib, "ws2_32.lib")
#define MAX_SIZE 65536

/*
    local central server simulator
*/

class Server{
public:
    string ip;
    int port;
    int curPeerId; 

    SOCKET sSocket;

    map<int,Peer*> APT; // activate peer table
    map<int,Peer*> PT; // peer table

    Server();
    Server(string ip, int port);
    int buildServer();
    void listen();
};
#endif // !SERVER_H