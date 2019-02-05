#pragma once
#ifndef USER_H
#define USER_H
#endif // !USER_H
#include"signup.h"
#include<iostream>
#include<string>
#include "Email.h"

using namespace std;

class signup;

class user
{
protected:
	friend class signup;
	string name;
	string address;
	string email;      //might call an email object
	string id;


public:
	user();
	~user();
	void draw();
	void gotoXY(int x,int y);
	void mainmenu();
};

