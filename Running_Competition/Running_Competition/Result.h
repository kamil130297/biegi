#pragma once
#include "Runner.h"
#include <vector>
class Result
{
public:
	int id_z;
	char wynik[10];
	int czas;
	void Review(vector<Runner> &);
	void Review(vector<Runner> &b, int a);
	void edit(vector<Runner>&a, vector<Result>&b);
	void dodaj(vector<Runner>&,  vector<Result>&b);
	void to_sec();
	bool operator < (const Result &x)const
	{
		return czas<x.czas;
	}

	
	Result(vector<Runner>&,  vector<Result>&b);
	Result(int,char c[10]);
	~Result();
};

