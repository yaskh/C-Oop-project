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
#include <Windows.h>

using namespace std;

user::user()
{
}

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void user:: gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}


void user::draw() 
{
	int y = 10;
	int width = 100;
	int length = 25;
	for (int i = 0; i<length; i++)
	{
		gotoXY(30, y);
		y++;
		for (int j = 0; j<width; j++)
		{
			if (i == 0 || i == length - 1 || j == 0 || j == width - 1)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
}
user::~user()
{
}
