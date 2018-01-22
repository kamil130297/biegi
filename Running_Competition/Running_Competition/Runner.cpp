#include "stdafx.h"
#include "Runner.h"

void Runner::lista_zawodnikow()
{
		cout << "ID: " << id_zawodnika << " " << imie << " " << nazwisko << endl;
	
}

Runner::Runner(int a)
{
	this->id_zawodnika = a;
	cout << "Podaj imie zawodnika: ";
	cin >> imie;
	cout << "Podaj nazwisko zawodnika: ";
	cin >> nazwisko;
}

Runner::Runner(int a, string b, string c)
{
	this->id_zawodnika = a;
	this->imie = b;
	this->nazwisko = c;
}

Runner::~Runner()
{
}
