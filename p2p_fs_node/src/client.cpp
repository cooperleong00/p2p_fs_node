#include "client.h"
#include "peer.h"
using namespace std;

Client::Client() {
	myPeer = Peer();
}

Client::Client(string ip, int port) {
	myPeer = Peer(ip, port);
}


int Client::Connect2Sever(string sIp, int sPort) {
	cSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	sockaddr_in clientIn;
	clientIn.sin_family = AF_INET;
	clientIn.sin_port = htons(myPeer.port);
	clientIn.sin_addr.S_un.S_addr = inet_addr(myPeer.ip.c_str());

	if (::bind(cSocket, (sockaddr*)&clientIn, sizeof(clientIn)) == SOCKET_ERROR)
	{
		printf("Client: Bind error\n");
		closesocket(cSocket);
	}

	sockaddr_in remoteIn;
	remoteIn.sin_family = AF_INET;
	remoteIn.sin_port = htons(sPort);
	remoteIn.sin_addr.S_un.S_addr = inet_addr(sIp.c_str());

	json sendJson;
	sendJson["type"] = 0;
	sendJson["data"] = myPeer.toJson();
	string sendData = sendJson.dump();

	sendto(cSocket, sendData.c_str(), sendData.length(), 0, (sockaddr*)&remoteIn, sizeof(remoteIn));
	
	thread t_listen(&Client::listen, this);
	t_listen.detach();

	return 0;
}

void Client::listen() {
	sockaddr_in remoteAddr;
	int nAddrLen = sizeof(remoteAddr);
	while (true)
	{
		char recvData[MAX_SIZE];
		int ret = recvfrom(cSocket, recvData, MAX_SIZE, 0, (sockaddr*)&remoteAddr, &nAddrLen);
		if (ret > 0)
		{
			recvData[ret] = 0x00;
			printf("Client: Receiving from£º%s:%d \n", inet_ntoa(remoteAddr.sin_addr), remoteAddr.sin_port);
			printf(recvData);
			printf("\n");
		}

	}
	closesocket(cSocket);
}

int Client::Connect2Peer(int peerId) {
	return 0;
}

int Client::keepConnection(int peerId) {
	return 0;
}

int Client::quitNetwork() {
	return 0;
}

int Client::assessPerformance() {
	return 0;
}

int Client::assessCrediblity() {
	return 0;
}