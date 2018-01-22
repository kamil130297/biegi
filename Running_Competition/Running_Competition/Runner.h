#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Runner
{
public:
	int id_zawodnika;
	string imie;
	string nazwisko;
	void lista_zawodnikow();
	Runner(int);
	Runner(int, string, string);
	~Runner();
};

