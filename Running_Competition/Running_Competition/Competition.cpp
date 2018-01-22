#include "stdafx.h"
#include "Competition.h"
#include <algorithm>
#include <iostream>
using namespace std;

Competition::Competition(int a )
{
	this->id_competition = a;
	cout << "Podaj nazwe zawodow o ID " << id_competition << ": ";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, competition_name);
	cout << "Podaj dystans biegu: ";
	cin >> dystans;
}

void Competition::sortowanie()
{
	sort(wyniki.begin(),wyniki.end());

}

void Competition::srednia()
{
	char sred[10]= { '0',':','0','0',':','0','0',',','0','0' };
	int n = wyniki.size();
	int liczba=0, srednia;
	for (size_t i = 0; i < wyniki.size(); i++) {
		srednia = wyniki[i].czas / n;
		liczba = liczba + srednia;

	}
	int a;
	a = liczba / 360000;
	sred[0] = char(a+48);
	liczba = liczba - (a*360000);
	
	a = liczba / 60000;
	if (a!=0) {
		sred[2] = char(a+48);
	}
	liczba = liczba - (a*60000);
	
	a = liczba / 6000;
	if (a != 0) {
		sred[3] = char(a+48);
	}
	liczba = liczba - (a*6000);
	
	a = liczba / 1000;
	if (a != 0) {
		sred[5] = char(a + 48);
	}
	liczba = liczba - a*(1000);
	
	a = liczba / 100;
	if (a != 0) {
		sred[6] = char(a + 48);
	}
	liczba = liczba - (a*100);
	
	a = liczba / 10;
	if (a != 0) {
		sred[8] = char(a + 48);
	}
	liczba = liczba - (a*10);
	
	a = (liczba / 1);
	if (a != 0) {
		sred[9] = char(a + 48);
	}
	liczba = liczba - a;
	cout << "Œredni czas: ";
	for (int i = 0; i < 10; i++) {
		cout << sred[i];
	}
	cout << endl;
}


	void Competition::edit()
{
}

void Competition::wyswietl(vector<Runner> &a)
{
	int licz = 1;
	for (int i = 0; i <wyniki.size(); i++) {
			cout << "Miejsce:" << licz;
			wyniki[i].Review(a);
			licz++;

	}
}

void Competition::wyswietl(vector<Runner>& a, int b)
{
	int licz = 1;
	for (size_t i = 0; i < wyniki.size(); i++) {
		if (wyniki[i].id_z == b) {
			cout << competition_name << ": ";
			cout << "Miejsce: " << licz << " " << "Czas: ";
			for (int j = 0; j < 10; j++) {
				cout << wyniki[i].wynik[j];
			}
		}
		cout << endl;
		licz++;
	}
	
}

void Competition::dodaj_wynik(vector<Runner>& a)
{
	wyniki.push_back(Result(a,wyniki));
}


Competition::Competition(string a, int b,int c)
{
	this->competition_name = a;
	this->id_competition = b;
	this->dystans = c;
}

Competition::~Competition()
{
}





