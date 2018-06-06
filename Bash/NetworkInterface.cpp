#define _CRT_SECURE_NO_WARNINGS
#include "NetworkInterface.h"

NetworkInterface* NetworkInterface::networkInterface;

NetworkInterface::NetworkInterface() {
	
}

NetworkInterface::~NetworkInterface() {
	if (networkInterface) {
		delete networkInterface;
		networkInterface = nullptr;
	}
}

char* NetworkInterface::GetCurrentIP() {
	char *host = new char;
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);// initialize socket's using Ws2_32.dll for the process
	char HostName[1024]; // creating buffer for host name    
	if (!gethostname(HostName, 1024)) { // extracting host name
		if (LPHOSTENT lphost = gethostbyname(HostName)) // receiving host's IP address
			strcpy(host, inet_ntoa(*((in_addr*)lphost->h_addr_list[0]))); //reforming LPIN_ADDR instance to  DWORD    
	}
	//WSACleanup();
	return host;
}

NetworkInterface* NetworkInterface::getInstance() {
	if (networkInterface == NULL) {
		networkInterface = new NetworkInterface;
		return networkInterface;
	}
	else return NULL;
}


