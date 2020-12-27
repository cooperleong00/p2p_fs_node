#include "server.h"
#include "client.h"
#include "peer.h"

using namespace std;

int main() {

	/*
	int WSAStartup(__in WORD wVersionRequested,__out  LPWSADATA lpWSAData);
		此函数在应用程序中初始化winsockDLL，只有此函数调用成功后，应用程序才可以调用Windows SocketsDLL中的其他API函数，否则后面的任何函数都将调用失败
		wVersionRequested -- 调用程序使用windows socket的最高版本。 高字节指定小的版本号，低字节指定高的版本号。
		lpWSAData -- 指向WSADATA数据结构体指针，接收Windows Socket的实现细节。
	返回值
		如果成功，WSAStartup函数返回0。否则，返回错误码。
	*/

	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		return 0;
	}

	return 0;
}