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

	sockaddr_in serverIn;
	serverIn.sin_family = AF_INET;
	serverIn.sin_port = htons(port);
	serverIn.sin_addr.S_un.S_addr = inet_addr(ip.c_str());

	if (::bind(sSocket, (LPSOCKADDR)&serverIn, sizeof(serverIn)) == SOCKET_ERROR)
	{
		printf("Server: Bind error");
		closesocket(sSocket);
	}

	thread t_listen(&Server::listen,this);
	t_listen.detach();
	return 0;
}

void Server::listen() {
	sockaddr_in remoteIn;
	int inLen = sizeof(remoteIn);
	while (true)
	{

		char recvData[MAX_SIZE];
		int ret = recvfrom(sSocket, recvData, MAX_SIZE, 0, (sockaddr*)&remoteIn, &inLen);
		if (ret > 0)
		{
			recvData[ret] = 0x00;
			printf("Server: Receiving from£º%s:%d \n", inet_ntoa(remoteIn.sin_addr), remoteIn.sin_port);
			//printf(recvData);
			//printf("\n");

			json recvJson = json::parse(recvData);
			Peer* tmpPeer = Peer::json2Peer(recvJson["data"]);
			
			if (recvJson["type"] == 0) {
				tmpPeer->ip = inet_ntoa(remoteIn.sin_addr);
				tmpPeer->port = remoteIn.sin_port;
				if (PT.size() == 0) {
					tmpPeer->id = curPeerId++;
					APT[tmpPeer->id] = tmpPeer;
					PT[tmpPeer->id] = tmpPeer;
				}
				else if (PT.find(tmpPeer->id) == PT.end()) {
					if (tmpPeer->id == -1)
						tmpPeer->id = curPeerId++;
					PT[tmpPeer->id] = tmpPeer;
				}

				json sendJson;
				sendJson["type"] = 5;
				sendJson["data"] = tmpPeer->toJson();
				string sendData = sendJson.dump();

				sendto(sSocket, sendData.c_str(), sendData.length(), 0, (sockaddr*)&remoteIn, inLen);

			}

		}
		
		
	}
	closesocket(sSocket);
}