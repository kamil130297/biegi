#include "stdafx.h"
#include "Result.h"
#include <string>
#include <iostream>
#include<fstream>
using namespace std;
void Result::Review(vector<Runner> &a)
{
	for (size_t i = 0; i < a.size(); i++) {
		if (id_z == a[i].id_zawodnika) {
			cout << " "<< a[i].imie << " " << a[i].nazwisko << "\t";
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << wynik[i];
		if (i == 9) {
			cout << endl;
		}
	}
	
}

void Result::Review(vector<Runner>&a, int b)
{
	for (size_t i = 0; i < a.size(); i++) {
		if (b == id_z) {
			cout << "Czas: ";
			for (int i = 0; i < 10; i++) {
				cout << wynik[i];
			}
		}
	}
	
}

void Result::edit(vector<Runner>&a, vector<Result>&b)
{
	int v, pom[10],k;
	char m;
	string czas;
	k = 0;
	int i = 0, z = 0;
	int t = 0;
	string res;
	int choice = 5;
	while (choice != '0') {
		system("cls");
		cout << "1. Edytuj ID zawodnika" << endl;
		cout << "2. Edytuj czas zawodnika" << endl;
		cout << "0. Koniec programu" << endl;
		cin >> choice;
		int flaga = 0, flaga1 = 0, petla = 0;
		system("cls");
		switch (choice) {

		case '1':
			 t = 0;
			cout << "Podaj nowe ID zawodnika: ";
			flaga = 0;
			flaga1 = 0;
			petla = 0;
			while (petla != 1) {
				cout << "Podaj ID zawodnika: ";
				cin >> id_z;
				for (size_t i = 0; i < a.size(); i++) {
					if (a[i].id_zawodnika == id_z) {
						flaga = 1;
						petla = 1;
					}
				}
				for (size_t i = 0; i < b.size(); i++) {
					if (b[i].id_z == id_z) {
						flaga1 = 1;
						petla = 0;
					}
				}


				if (flaga == 0) {
					cout << "Zawodnik o tym ID nie istnieje" << endl;
				}
				if (flaga1 == 1) {
					cout << "Zawodnik ju¿ ma wynik w tym biegu" << endl;
				}

			}
			break;
		case '0':
			break;
		default:
			cout << "Brak dzialania dla znaku";
			system("pause");
			break;

		}
	}
}

void Result::dodaj(vector<Runner>&a, vector<Result>&b)
{
	string res;
	int t = 0,k;
	char m;
	char pom[10] = { '0',':','0','0',':','0','0',',','0','0' };
	
	int flaga = 0,flaga1=0,petla=0;
	while (petla != 1) {
		cout << "Podaj ID zawodnika: ";
		cin >> id_z;
		for (size_t i = 0; i < a.size(); i++) {
			if (a[i].id_zawodnika == id_z) {
				flaga = 1;
				petla = 1;
			}
		}
		for (size_t i = 0; i < b.size(); i++) {
			if (b[i].id_z == id_z) {
				flaga1 = 1;
				petla = 0;
			}
		}
		
		
		if (flaga == 0) {
			cout << "Zawodnik o tym ID nie istnieje"<<endl;
		}
		if (flaga1 == 1) {
			cout << "Zawodnik ju¿ ma wynik w tym biegu" << endl;
		}

	}
	cout << "Format wyniku: H:MM:SS,SS" << endl;
	flaga = 0;
	int i = 0,z=0;
	while (flaga != 1) {
		cout << "Podaj wynik zawodnika o ID " << id_z << ": ";
		cin >> res;
		int i = 9;
		z = 0;
		for (int j = res.length() - 1; j >= 0; j--) {
			if (i == 0 || i == 2 || i == 3 || i == 5 || i == 6 || i == 8 || i == 9) {
				m = res[j];
				k = int(m);
				if (k >= 48 && k <= 57) {
					pom[i] = m;
				}
				else {
					z = 1;
				}
			}
			if (i == 1 || i == 4 ) {
				m = res[j];
				k = int(m);
				if (k==58) {
					pom[i] = m;
				}
				else {
					z = 1;
				}
			}
			if (i == 7) {
				m = res[j];
				k = int(m);
				if (k == 44) {
					pom[i] = m;
				}
				else {
					z = 1;
				}
				
			}
			i--;
		}
		if (z == 0) {
			flaga = 1;
		}
		else {
			cout << "Blad w formacie czasu" << endl;
		}
		
	}
	for (int i = 0; i < 10; i++) {
		wynik[i] = pom[i];
	}
	cout << endl;
	to_sec();
}

void Result::to_sec()
{
	czas = ((int(wynik[0])-48)*360000) + ((int(wynik[2]) - 48) *60000) + ((int(wynik[3]) - 48) *6000) + ((int(wynik[5]) - 48) *1000) + ((int(wynik[6]) - 48) *100) + ((int(wynik[8]) - 48) *10) + (int(wynik[9]) - 48);
	
}


Result::Result( vector<Runner>&a, vector<Result>&b)
{
	dodaj(a,b);
}

Result::Result(int a, char c[10])
{
	this->id_z = a;
	for (int i = 0; i < 10; i++) {
		wynik[i] = c[i];
	}
	
}


Result::~Result()
{
}
