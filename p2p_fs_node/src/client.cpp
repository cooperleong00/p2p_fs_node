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
	serverIp = sIp;
	serverPort = sPort;
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
	sendJson["trgId"] = -1;
	string sendData = sendJson.dump();

	sendto(cSocket, sendData.c_str(), sendData.length(), 0, (sockaddr*)&remoteIn, sizeof(remoteIn));
	
	thread t_listen(&Client::listen, this);
	t_listen.detach();

	return 0;
}

void Client::listen() {
	sockaddr_in remoteIn;
	int inLen = sizeof(remoteIn);
	while (true)
	{
		char recvData[MAX_SIZE];
		int ret = recvfrom(cSocket, recvData, MAX_SIZE, 0, (sockaddr*)&remoteIn, &inLen);
		if (ret > 0)
		{
			recvData[ret] = 0x00;
			printf("Client: Receiving from£º%s:%d \n", inet_ntoa(remoteIn.sin_addr), remoteIn.sin_port);
			//printf(recvData);
			//printf("\n");

			json recvJson = json::parse(recvData);
			// contains the src peer info
			Peer* tmpPeer = Peer::json2Peer(recvJson["data"]);

			if (recvJson["type"] == 2){

				json sendJson;
				sendJson["type"] = 6;
				sendJson["data"] = myPeer.toJson();
				string sendData = sendJson.dump();

				sendto(cSocket, sendData.c_str(), sendData.length(), 0, (sockaddr*)&remoteIn, inLen);

			}
			else if (recvJson["type"] == 6) {
				tmpPeer->ip = inet_ntoa(remoteIn.sin_addr);
				tmpPeer->port = remoteIn.sin_port;
				PT[tmpPeer->id] = tmpPeer;
			}
			else if (recvJson["type"] == 4) {
				PT.erase(tmpPeer->id);
			}
			else if (recvJson["type"] == 5) {
				myPeer.id = tmpPeer->id;
				myPeer.ip = tmpPeer->ip;
				myPeer.port = tmpPeer->port;
			}
		}

	}
	closesocket(cSocket);
}

int Client::Connect2Peer(int peerId) {
	sockaddr_in remoteIn;
	remoteIn.sin_family = AF_INET;
	remoteIn.sin_port = htons(serverPort);
	remoteIn.sin_addr.S_un.S_addr = inet_addr(serverIp.c_str());

	json sendJson;
	sendJson["type"] = 1;
	sendJson["data"] = myPeer.toJson();
	sendJson["trgId"] = peerId;
	string sendData = sendJson.dump();

	sendto(cSocket, sendData.c_str(), sendData.length(), 0, (sockaddr*)&remoteIn, sizeof(remoteIn));
	return 0;
}

int Client::keepConnection(int peerId) {
	return 0;
}

int Client::quitNetwork() {
	
	sockaddr_in remoteIn;
	remoteIn.sin_family = AF_INET;
	remoteIn.sin_port = htons(serverPort);
	remoteIn.sin_addr.S_un.S_addr = inet_addr(serverIp.c_str());

	json sendJson;
	sendJson["type"] = 3;
	sendJson["data"] = myPeer.toJson();
	string sendData = sendJson.dump();

	sendto(cSocket, sendData.c_str(), sendData.length(), 0, (sockaddr*)&remoteIn, sizeof(remoteIn));

	for (auto it = PT.begin(); it != PT.end(); it++) {
		sockaddr_in remoteIn;
		remoteIn.sin_family = AF_INET;
		remoteIn.sin_port = htons(it->second->port);
		remoteIn.sin_addr.S_un.S_addr = inet_addr(it->second->ip.c_str());

		json sendJson;
		sendJson["type"] = 4;
		sendJson["data"] = myPeer.toJson();
		string sendData = sendJson.dump();

		sendto(cSocket, sendData.c_str(), sendData.length(), 0, (sockaddr*)&remoteIn, sizeof(remoteIn));
	}

	return 0;
}

int Client::assessPerformance() {
	return 0;
}

int Client::assessCrediblity() {
	return 0;
}