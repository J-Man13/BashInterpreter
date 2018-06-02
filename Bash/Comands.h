#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<vector>
#include<string>
#include<iostream>
#include <stdio.h>  
#include <strsafe.h>
#include <conio.h>
/* defines FILENAME_MAX */
#define WINDOWS  
#include <direct.h>
#define GetCurrentDir _getcwd
//for changeDirectory
#include <Windows.h>
#include <windows.h> 
#include <stdio.h>
#include <tchar.h>
#define BUFSIZE MAX_PATH
//for file outputting
#include <fstream>
//for directory list
#include<experimental/filesystem>
namespace fs = std::experimental::filesystem;
//for file creation
#include<fstream>
//for directory creation
#include<direct.h>


using namespace std;


class Comands
{
public:
	~Comands();
	static void printComands();
	static void addToHistory(std::string comand);
	static void printHistory();
	static Comands* getInstance();
	static std::string GetCurrentWorkingDir(void);
	static void changeDirectory(std::string PATH);
	static void clear();
	static void printFile(std::string fileName);
	static void listDirectory(std::string PATH = NULL);
	static void createFile(std::string PATH);
	static void createDirectory(std::string PATH);
	static void removeInstance(std::string PATH);
	static void moveFile(std::string target, std::string destination);
	static void copyFile(std::string target, std::string destination);
	static std::string* comandExists(std::string* comandToCheck);
	static unsigned long long instanceSize(std::string PATH);
	static std::vector<string>* parseConsoleString(std::string str);
	static void showTotal(std::string PATH);
private:
	Comands();
	Comands static *comand;
	std::vector<std::string> static *comands;
	std::vector<std::string> static *history;
	static bool checkIfDirectory(std::string filePath);
};

