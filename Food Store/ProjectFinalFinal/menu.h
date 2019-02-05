#pragma once
class menu: private user
{
private :
	struct f1
	{
		string name;
		float price;
	}arr[6];
	string temp;
	int count = 0; 
	Email send;
	friend class signup;
	signup  *obj_s;

public:
	menu();
	void list(string, string, string);
	void notification(string,string,string,int x);
	int display();
	void selection(string, string, string, int);
	virtual~menu();
};

