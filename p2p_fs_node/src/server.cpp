#include "server.h"
using namespace std;

Server::Server(){
	this->ip = "127.0.0.1";
	this->port = 1234;
	curPeerId = 0;
}

Server::Server(string ip, int port) {
	this->ip = ip;
	this->port = port;
	curPeerId = 0;
}

int Server::buildServer() {

	sSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (sSocket == INVALID_SOCKET)
	{
		cout << "Server: socket error" << endl;
		return 0;
	}

	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.S_un.S_addr = inet_addr(ip.c_str());

	if (::bind(sSocket, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("Server: Bind error");
		closesocket(sSocket);
	}

	thread t_listen(&Server::listen,this);
	t_listen.detach();
	return 0;
}

void Server::listen() {
	sockaddr_in remoteAddr;
	int nAddrLen = sizeof(remoteAddr);
	while (true)
	{

		char recvData[MAX_SIZE];
		int ret = recvfrom(sSocket, recvData, MAX_SIZE, 0, (sockaddr*)&remoteAddr, &nAddrLen);
		if (ret > 0)
		{
			recvData[ret] = 0x00;
			printf("Receiving from£º%s:%d \n", inet_ntoa(remoteAddr.sin_addr),remoteAddr.sin_port);
			printf(recvData);
			break;
		}
		/*
		string data = jsonCreateString();

		const char* sendData = data.c_str();
		//std::cout << sendData << std::endl;
		//const char* sendData = "·¢ËÍ\n";
		sendto(sk_ptr, sendData, strlen(sendData), 0, (sockaddr*)&remoteAddr, nAddrLen);
		//if (i++ > 1000) break;
		*/
	}
	closesocket(sSocket);
}

int Server::addPeer(Peer* peer) {
	if (peerTable.size() == 0) {
		peerTable[peer->id] = peer;
		activePeerTable[peer->id] = peer;
	}
	else {
		peerTable[peer->id] = peer;
	}
	return 0;
}

int Server::deletePeer(int peerId) {
	this->activePeerTable.erase(peerId);
	return 0;
}