#include "server.h"
#include "client.h"
#include "peer.h"

using namespace std;

int main() {

	/*
	int WSAStartup(__in WORD wVersionRequested,__out  LPWSADATA lpWSAData);
		�˺�����Ӧ�ó����г�ʼ��winsockDLL��ֻ�д˺������óɹ���Ӧ�ó���ſ��Ե���Windows SocketsDLL�е�����API���������������κκ�����������ʧ��
		wVersionRequested -- ���ó���ʹ��windows socket����߰汾�� ���ֽ�ָ��С�İ汾�ţ����ֽ�ָ���ߵİ汾�š�
		lpWSAData -- ָ��WSADATA���ݽṹ��ָ�룬����Windows Socket��ʵ��ϸ�ڡ�
	����ֵ
		����ɹ���WSAStartup��������0�����򣬷��ش����롣
	*/

	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		return 0;
	}

	return 0;
}