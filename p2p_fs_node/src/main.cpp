#include "server.h"
#include "client.h"
#include "peer.h"

using namespace std;

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

	Client client1 = Client();
	client1.Connect2Sever(cServer.ip, cServer.port);

	system("pause");
	WSACleanup();
	return 0;
}