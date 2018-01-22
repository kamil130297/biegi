#pragma once
#include <string>
#include <iostream>
#include "Result.h"
#include <vector>
using namespace std;
class Competition
{
public:
	string competition_name;
	int id_competition;
	int dystans;
	vector<Result>  wyniki;
	Competition(int);
	void sortowanie();
	void srednia();
	void edit();
	void wyswietl(vector<Runner> &a);
	void wyswietl(vector<Runner> &a,int b);
	void dodaj_wynik(vector<Runner> &a);
	Competition(string, int,int);
	~Competition();
};

