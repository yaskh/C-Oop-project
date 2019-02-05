#pragma once
#ifndef SIGNUP_H
#define SIGNUP_H
#endif // !SIGNUP
#include "user.h"
#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<sstream>
#include<cstring>
#include<stdio.h>
#include<conio.h>
#include "menu.h"
#include "Email.h"

using namespace std;

class signup;
class signup : public user
{
private:
	friend class menu;
	menu obj;
	menu *obj_m;
public:

	bool checkEmail(const std::string& );
	user userObj;
	void title();
	signup();	 //delete if not needed
	virtual void getInfo();
	virtual void checkInfo();
	int getUser_id();
	void setUser_id(int user_id);
	void mainmenu();
	void drawMain();
	virtual ~signup();
};

