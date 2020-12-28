#include "server.h"
#include "client.h"
#include "peer.h"

using namespace std;

void showMap(map<int,Peer*> m) {
	for (auto it = m.begin(); it != m.end(); it++) {
		Peer* tmp = it->second;
		printf("Client %d: %s:%d; ", tmp->id, tmp->ip.c_str(), tmp->port);
	}
	printf("\n");
}

int main() {

	// initialize socket lib
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		return 0;
	}


	Server cServer = Server();
	cServer.buildServer();

	Client client0 = Client("127.0.0.1",12345);
	client0.Connect2Sever(cServer.ip, cServer.port);

	Client client1 = Client("127.0.0.1", 12346);
	client1.Connect2Sever(cServer.ip, cServer.port);

	Client client2 = Client("127.0.0.1", 12347);
	client2.Connect2Sever(cServer.ip, cServer.port);

	Sleep(1000);
	printf("\n");
	printf("Activated Peer Table: ");
	showMap(cServer.APT);
	printf("Peer Table: ");
	showMap(cServer.PT);
	printf("\n");

	client0.Connect2Peer(1);
	client2.Connect2Peer(1);
	client0.Connect2Peer(2);

	Sleep(1000);
	printf("\n");
	printf("Activated Peer Table: ");
	showMap(cServer.APT);
	printf("Peer Table: ");
	showMap(cServer.PT);
	printf("\n");

	system("pause");
	WSACleanup();
	return 0;
}