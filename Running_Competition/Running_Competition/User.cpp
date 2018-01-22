#include "stdafx.h"
#include "User.h"



#include <conio.h>
using namespace std;


User::User(vector<Runner>&a,vector<User>&b)
{
	
	int flaga1 = 0,flaga2=0,flaga=0;
	while (flaga != 1)
	{
		cout << "Podaj ID zawodnika ktoremu chcesz zalozyc konto";
		cin >> id_user;
		for (size_t i = 0; i < a.size(); i++) {
			if (a[i].id_zawodnika == id_user) {
				flaga1 = 1;
				flaga = 1;
			}

		}
		for (size_t i = 0; i < b.size(); i++) {
			if (b[i].id_user == id_user) {
				flaga2 = 1;
				flaga = 0;
			}
			if (flaga1 == 0) {
				cout << "Uzytkownik o tym ID nie istnieje" << endl;
			}
			if (flaga2 == 1) {
				cout << "Uzytkownik o tym ID ma ju¿ konto" << endl;
			}
		}
	}
	flaga = 0;
	flaga1 = 0;
	flaga2 = 0;
	string lg;
	while (flaga != 1)
	{
		
		cout << "Nowy login dla USER " << id_user << ": ";
		cin >> lg;
		flaga = 1;
		for (size_t i = 0; i < b.size(); i++) {
			if (b[i].login == lg) {
				flaga2 = 1;
				flaga = 0;
			}
			else {
			}
		}
			if (flaga2 == 1) {
				cout << "Login zajety wprowadz inny" << endl;
			}
		
	}
	login = lg;
	cout << "Nowy haslo dla USER " << id_user << ": ";
	cin >> haslo;
}

User::User()
{
	this->id_user = 0;
	cout << "Nowy login dla ADMIN " << id_user << ": ";
	cin >> login;
	cout << "Nowy haslo dla ADMIN " << id_user << ": ";
	cin >> haslo;
}

User::User(int a, string b, string c)
{
	this->id_user = a;
	this->login = b;
	this->haslo = c;
}

void User::nowe_pass()
{
	int flaga = 0;
	char c;
	string a, b;
	while (flaga != 1) {
		cout << "Podaj nowe haslo";
		while ((c = _getch()) != 13) // 13, to kod ENTERA, który koñczy wpisywanie has³a                                                               
		{
			cout << "*";
			a = a + c;
		}
		cout << "Powtorz nowe haslo";
		while ((c = _getch()) != 13) // 13, to kod ENTERA, który koñczy wpisywanie has³a                                                               
		{
			cout << "*";
			b = b + c;
		}
		if (a == b) {
			haslo = a;
			flaga = 1;
			cout << "Zmieniles haslo";
		}
		else {
			cout << "Rozne hasla" << endl;
		}
	}

}



User::~User()
{
}
