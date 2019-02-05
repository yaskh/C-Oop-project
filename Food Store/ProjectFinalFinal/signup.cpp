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
#include <cwchar>
#include <windows.h>
#include <cstdlib>
#include "regex"
using namespace std;
signup::signup()  //delete if unnecessary
{
	
}

bool signup:: checkEmail(const std::string& email)
{
	const std::regex pattern
	("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	return std::regex_match(email, pattern);

}
void signup::getInfo()
{
	ifstream inFile;
	system("cls");
	inFile.open("users.dat", ios::in);
	
	if (inFile.fail())
	{

		gotoXY(35, 20);
		cerr << "-Error opening file" << endl;
		exit(1);
	}
	else
	{
		draw();
		int flag = 2;
		while (true)
		{
		while (getchar() != '\n');
		gotoXY(35, 14);
		cout << "Enter Email:";
		getline(cin,userObj.email);
		
			if (checkEmail(userObj.email) == 1) //Validate email
			{
				string temp_e, temp_n, temp_a, temp_id;
				while (true)
				{
					getline(inFile, temp_e, ',');
				
					/*
					getline(inFile, temp_n, ',');
					getline(inFile, temp_a, ',');
					getline(inFile, temp_id, ',');*/
					if (inFile.eof())
					{
						flag = 1;
						break;
					}

					if (userObj.email.compare(temp_e) == 0)
					{

						gotoXY(35, 22);
						cout << "Email already registered";
						flag = 0;
						_getch();
						break;
					}
			

					//outFile << userObj.email << "," << endl;
				}
			}
			if (flag == 1)
			{
				int user_id = getUser_id();
				user_id++;
				setUser_id(user_id);
				
				//itoa(user_id, userObj.id, 10);
				string convert = to_string(user_id);        // for visual studio

				ofstream outFile;
				outFile.open("users.dat", ios::app);
				outFile << convert << ",";
				gotoXY(35, 19);
				cout << "Your id is: " << user_id << ".Use this id for logging in!" << endl;
				gotoXY(35, 24);
				cout << "Enter name:"; cin >> userObj.name;
				outFile << userObj.name << ",";
				gotoXY(35, 28);
				cout << "Enter Address:"; cin >> userObj.address;
				outFile << userObj.address << ",";
				outFile << userObj.email << "," << endl;
				gotoXY(35, 30);
				cout << "Press any key to continue...";
				system("cls");
				mainmenu();
				break;
			}
			if(flag==2)
			{
				gotoXY(35, 16);
			
				cout << "Invalid email";
				gotoXY(35, 17);
				cout << "Returning to main menu";
				mainmenu();
				getch();
				break;
			}
			if (flag == 0)
			{
				gotoXY(35, 22);
				cout << "Returning to main menu!";
				system("cls");
				mainmenu();
			}
		
		}


	}
}
void signup::drawMain()
{
		draw();
		gotoXY(62, 18);
		cout << "***  Welcome to \"Hide Out Cafe\"  ***   \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		gotoXY(50, 25);
		cout << "Hide Out Offers Special Desi Food For People Who Are Away From\n ";
		gotoXY(60, 26);
		cout << "Their Home And Miss Their \"Ghar Ka Khana\"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	
}

void signup::checkInfo()
{
	string idCheck, nameCheck;
	system("cls");
	draw();
	gotoXY(35, 20);
	while (getchar() != '\n');
	cout << "Enter name: ";
	getline(cin, nameCheck);
	gotoXY(35, 25);
	cout << "Enter your id ";
	getline(cin, idCheck);

	int flag = 0;
	char choice;

	ifstream inFile;
	inFile.open("users.dat", ios::in);
	if (inFile.fail())
	{
		gotoXY(40, 30);
		cout << "Error opening file" << endl;
	
		exit(1);
	}
	while (!inFile.eof())
	{
		getline(inFile, userObj.id, ',');
		getline(inFile, userObj.name, ',');
		getline(inFile, userObj.address, ',');
		getline(inFile, userObj.email, ',');
		if ((nameCheck.compare(userObj.name)) == 0)
		{
			if ((idCheck.compare(userObj.id)) == 0)
			{
				inFile.close();
				flag = 1;
				obj_m = &obj;
				obj_m->list(userObj.name, userObj.email, userObj.address);
				break;
			}
		}
	}
	if (flag == 0)
	{
		system("cls");
		draw();
		gotoXY(35, 15);
		cout << "No such registration number found";
		gotoXY(35, 20);
		cout << "\nTry again" << endl;
		gotoXY(35, 25);
		cout << "Enter 's' for signup or 'l' for login. Press 'e' to exit";
		gotoXY(35, 30);
		cin >> choice;
		switch (choice)
		{
		case 's':
			getInfo();
			break;
		case 'l':
			checkInfo();
			break;
		case 'e':
			exit(1);
		default:
		{
			gotoXY(35, 40);
			cout << "Invalid selection" ;
			system("cls");
			mainmenu();
			break;
		}
		}
	}
}

int signup::getUser_id()
{
	int user_id;
	ifstream file_id;
	file_id.open("usersId.dat", ios::in);
	if (file_id.fail())
	{
		cerr << "No such file exists" << endl;
	}

	file_id >> user_id;
	file_id.close();
	return user_id;
}

void signup::setUser_id(int user_id)
{
	ofstream file_id;
	file_id.open("usersId.dat", ios::out);
	if (file_id.fail())
	{
		cerr << "no such file exists" << endl;
	}
	file_id << user_id;
	file_id.close();
}
/****************MENU*************/
void signup::mainmenu()
{
	while (getchar() != '\n');
	int choice;
	do
	{
		system("cls");
		draw();
		gotoXY(60, 12);
		cout << "\t\tWELCOME";
		gotoXY(35, 15);
		cout << "1] Sign up";
		gotoXY(35, 20);
		cout << "2] Log in";
		gotoXY(35, 25);
		cout << "3] Exit";
		gotoXY(35, 30);
		cout << "Enter your choice ";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			signup::getInfo();
			break;
		case 2:
			signup::checkInfo();
			break;
		case 3:
			exit(1);
		default:
		{
			cout << "You entered wrong choice\n";

		}
		}
	} while (choice > 3);
}


void signup :: title()
{
	draw();
		
}

signup::~signup()
{
}
