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
	SOCKET cSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(sPort);
	sin.sin_addr.S_un.S_addr = inet_addr(sIp.c_str());
	int len = sizeof(sin);

	const char* sendData = "";
	sendto(cSocket, sendData, strlen(sendData), 0, (sockaddr*)&sin, len);
	/*
	while (true)
	{
		const char* sendData = "";
		sendto(sclient, sendData, strlen(sendData), 0, (sockaddr*)&sin, len);

		int ret = 0;
		char recvData[MAX_SIZE];
		ret = recvfrom(sclient, recvData, MAX_SIZE, 0, (sockaddr*)&sin, &len);
		if (ret <= 0) break;
		if (ret > 0)
		{
			recvData[ret] = 0x00;
			//printf(recvData);
			json o = json::parse(recvData);
			for (json::iterator it = o.begin(); it != o.end(); ++it)
				std::cout << it.key() << " : " << it.value() << "\n";
		}
	}
	*/
	closesocket(cSocket);
	return 0;
}