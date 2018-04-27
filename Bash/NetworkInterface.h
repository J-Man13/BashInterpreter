//For ip Address///////////////
#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma once
#include <winsock2.h>
#pragma comment(lib, "ws2_32")
#include<iostream>

class NetworkInterface
{
public:
	~NetworkInterface();
	static NetworkInterface* getInstance();
	char* GetCurrentIP();
private:
	NetworkInterface static *networkInterface;
	NetworkInterface();
};

