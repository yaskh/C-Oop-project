// ProjectFinalFinal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "signup.h"	  
#include "user.h"
#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<sstream>
#include<cstring>
#include<stdio.h>
#include<conio.h>
#include "Email.h"
#include <chrono>
#include <thread>
#include <windows.h>

#pragma comment(lib, "user32")


using namespace std;


int main()
{
	SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	
	/*std::ofstream ofs;
	ofs.open("users.dat", std::ofstream::out | std::ofstream::trunc);
	ofs.close();*/
//SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	signup obj;
	
	obj.drawMain();
	obj.mainmenu();
	system("pause");
	return 0;
}