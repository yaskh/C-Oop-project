#include "stdafx.h"
#include <iostream>
#include <Windows.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void draw()
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