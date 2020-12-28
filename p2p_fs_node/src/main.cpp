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

	Client client1 = Client("127.0.0.1",12345);
	client1.Connect2Sever(cServer.ip, cServer.port);

	Client client2 = Client("127.0.0.1", 12346);
	client2.Connect2Sever(cServer.ip, cServer.port);


	Sleep(1000);
	cout << cServer.curPeerId << endl;
	cout << cServer.APT.size() << endl;
	cout << cServer.PT.size() << endl;

	system("pause");
	WSACleanup();
	return 0;
}