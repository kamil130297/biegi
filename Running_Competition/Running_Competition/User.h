#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Runner.h"
using namespace std;
class User
{
public:
	int id_user;
	string login;
	string haslo;
	User(vector<Runner>&a, vector<User>&b);
	User();
	User(int,string,string);
	void nowe_pass();
	~User();
};

