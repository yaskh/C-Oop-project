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
#include "menu.h"


using namespace std;
menu::menu()
{

}


menu::~menu()
{
}

void menu::notification(string name, string email, string address, int x)

{
	int index;
	std::this_thread::sleep_for(std::chrono::seconds(x));
	for (int i = 300; i < 1000; i += 10)
	{
		Beep(i, 100);
	}
}


int menu::display()
{
	system("cls");
	draw();
	ifstream file("data.txt", ios::in);
	if (!file)
	{
		gotoXY(40, 35);
		cout << "File absent";
		exit(1);
	}
	else
	{
		while (!file.eof())
		{
			getline(file, arr[count].name, ',');
			getline(file, temp, ',');
			arr[count].price = stof(temp);
			count++;
		}
	}
	int y = 12;
	for (int i = 0; i < count; i++)
	{
		gotoXY(35, y);
		cout << i << '\t' << arr[i].name << '\t' << arr[i].price;
		y++;
	}
	return y;
}


void menu::selection(string name, string email, string address, int y)
{
	int count = 0;
	ofstream file;
	file.open("bill.dat", ios::out);
	file.clear();
	file << "************************Your Bill****************************\n\n\n\n\n\n\n";
	file << "Thanks for ordering from Hideout Food Service";
	file << "\n\n";
	file << "\n\nName:" << name;
	file << "\nAddress:" << address;
	int choice;
	do
	{
		gotoXY(35, y);
		cout << "Select the respective number to add the item to your bill :";
		cin >> choice;
		if (choice < 0 || choice>15)
		{
			cout << "Invalid item selected";
			cout << "Press y if you wanted add a new item";
		}
		else
		{

			file << endl << count << '\t' << '\t' << arr[choice].name << '\t' << '\t' << '\t' << arr[choice].price << endl;
			gotoXY(35, ++y);
			cout << "Perhaps Another item?[y/n]";
			count++;
		}
	} while (_getche() != 'n');
	system("notepad.exe bill.dat");
	send.sendEmail(email);
	list(name, email, address);

}


void menu::list(string name, string email, string address)
{
	system("cls");
	draw();
	gotoXY(35, 12);
	cout << "Press the respective keys";
	gotoXY(35, 15);
	cout << "1) To view the menu list";
	gotoXY(35, 20);
	cout << "2) To set the reminder time";
	gotoXY(35, 25);
	cout << "3) To logout";
	gotoXY(35, 30);
	int choice;
	do
	{
		gotoXY(35, 29);
		cout << "Your choice:   ";
		cin >> choice;
		int index;
		switch (choice)
		{
		case 1:
			system("cls");
			index = display();
			selection(name, email, address, index);
			break;
		case 2:
			gotoXY(50, 25);
			cout << "Enter the notifier time:";
			int time;
			cin >> time;
			notification(name, email, address, time);
			system("cls");
			//index = display();
			//selection(name, email, address, index);
			list(name, email, address);
			break;
		case 3:
			cout << "\n The screen will now return to the Main menu";
			system("cls");
			std::this_thread::sleep_for(std::chrono::seconds(1));
			obj_s->mainmenu();
			break;
		default:
			gotoXY(35, 29);
			cout << "Invalid key selected";
		}
	} while (choice>3);
}


