// Running_Competition.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  
#include <cmath> 
#include <conio.h>
#include<fstream>
#include "User.h"
#include "Runner.h"
#include "Competition.h"
using namespace std;
typedef int zdefiniowana_zmienna;

zdefiniowana_zmienna id_zawodnikav = 1, id_zawodowv = 1;
auto lista_zawodow = [](vector<Competition>&b)->void { 
	cout << "Lista zawodow" << endl;
	for (size_t i = 0; i < b.size(); i++) {
		cout << "ID " << b[i].id_competition << " " << b[i].competition_name << endl;

	}


};
void nb_zawodnik(vector<Competition>&a, int b) {
	
	vector<int> dys;
	int kamil=0;
	for (size_t i = 0; i < a.size(); i++) {
		for (size_t j = 0; j < dys.size(); j++) {
			if (a[i].dystans == dys[j]) {
				kamil = 1;
			}
		}
		if (kamil == 0) {
			dys.push_back(a[i].dystans);
		}
	}
	for (size_t k = 0; k < dys.size(); k++) {
		vector<int> red;
		vector<int> min;
		for (size_t i = 0; i < a.size(); i++) {
			for (size_t j = 0; j < a[i].wyniki.size(); j++) {
				if (a[i].wyniki[j].id_z == b&&a[i].dystans == dys[k]) {
					red.push_back(i);
					min.push_back(a[i].wyniki[j].czas);
				}
			}
		}
		int min_z = min[0];
		int flaga = 0;
		for (size_t j = 0; j < min.size(); j++) {
			if (min[j] <= min_z) {
				flaga = j;
				min_z = min[j];
			}
		}
		min_z = red[flaga];
		cout << "Twoj najlepszy czas na " << dys[k] << "m: ";
		for (size_t j = 0; j < a[min_z].wyniki.size(); j++) {
			if (a[min_z].wyniki[j].id_z == b) {
				for (int i = 0; i < 10; i++) {
					cout << a[min_z].wyniki[j].wynik[i];
				}
			}
		}
		cout << endl;
	}
}
void nb_zawody(vector<Competition>&a,vector<Runner>&b) {

	vector<int> dys;
	int kamil = 0;
	for (size_t i = 0; i < a.size(); i++) {
		for (size_t j = 0; j < dys.size(); j++) {
			if (a[i].dystans == dys[j]) {
				kamil = 1;
			}
		}
		if (kamil == 0) {
			dys.push_back(a[i].dystans);
		}
	}
	for (size_t k = 0; k < dys.size(); k++) {
		vector<int> red;
		vector<int> min;
		for (size_t i = 0; i < a.size(); i++) {
			
				if (a[i].dystans == dys[k]) {
					red.push_back(i);
					min.push_back(a[i].wyniki[0].czas);
				
			}
		}
		int min_z = min[0];
		int flaga = 0;
		for (size_t j = 0; j < min.size(); j++) {
			if (min[j] <= min_z) {
				flaga = j;
				min_z = min[j];
			}
		}
		min_z = red[flaga];
		cout << "Najlepszy czas na " << dys[k] << "m: ";
		
				for (int i = 0; i < 10; i++) {
					cout << a[min_z].wyniki[0].wynik[i];
		}
				cout << " ";
				for (size_t j = 0; j < b.size(); j++) {
					if (b[j].id_zawodnika == a[min_z].wyniki[0].id_z) {
						cout << "Zawodnik: " << b[j].imie << " " << b[j].nazwisko;
					}
				}
		cout << endl;
	}
}
void worst_zawodnik(vector<Competition>&a, int b) {
	vector<int> red;
	vector<int> min;
	for (size_t i = 0; i < a.size(); i++) {
		for (size_t j = 0; j < a[i].wyniki.size(); j++) {
			if (a[i].wyniki[j].id_z == b) {
				red.push_back(i);
				min.push_back(a[i].wyniki[j].czas);
			}
		}
	}
	int min_z = min[0];
	int flaga = 0;
	for (size_t j = 0; j < min.size(); j++) {
		if (min[j] >= min_z) {
			flaga = j;
			min_z = min[j];
		}
	}
	min_z = red[flaga];
	cout << "Twoj najlepszy czas: ";
	for (size_t j = 0; j < a[min_z].wyniki.size(); j++) {
		if (a[min_z].wyniki[j].id_z == b) {
			for (int i = 0; i < 10; i++) {
				cout << a[min_z].wyniki[j].wynik[i];
			}
		}
	}
	cout << endl;

}
auto lista_zawodnikow = [](vector<Runner>&a)->void {
	cout << "Lista zawodnikow" << endl;
	for (size_t i = 0; i < a.size(); i++) {
		a[i].lista_zawodnikow();
	}


};
void zawody_admin(vector<Runner>&a, vector<Competition>&b,int d) {
	char i = 9;
	int zmienna;

	string exchange;
	int exchange_date;
	int nr, pok;
	while (i != '0') {
		cout << endl << "ZARZADZANIE ZAWODAMI" << endl;
		cout << "0.Wyjscie" << endl;
		cout << "1.Nowe zawody" << endl;
		cout << "2.Lista zawodów" << endl;
		cout << "3. Wprowadz wyniki" << endl;
		cout << "4. Wyniki zawodow" << endl;
		cout << "5. Najlepsze wyniki na poszczegolnych dystansach" << endl;
		cin >> i;
		switch (i) {
		case '1':
			b.push_back((d));
			d++;
			system("pause");
			system("cls");
			break;
		case '2':
			lista_zawodow(b);
			system("pause");
			system("cls");
			break;
		case '3':
			
			lista_zawodow(b);
			cout << "Podaj ID zawodow do których chcesz dodaæ wyniki"<<endl;
			cin >> nr;
			cout << "Ile wynikow chcesz dodac?"<<endl;
			cin >> pok;
			system("cls");
			
				for (size_t i = 0; i < b.size(); i++) {
					if (b[i].id_competition == nr) {
						for (int j = 0; j < pok; j++) {
							lista_zawodnikow(a);
							b[i].dodaj_wynik(a);
							system("cls");
						}
					
						
				}
			}
				for (size_t i = 0; i < b.size(); i++) {
					if (b[i].id_competition == nr) {
						b[i].sortowanie();
					}
				}
			break;
		case '4':
	
			lista_zawodow(b);
			cout << "Podaj ID zawodow ktorych wyniki chcesz wyswietlic" << endl;
			cin >> nr;
			system("cls");
			for (size_t i = 0; i < b.size(); i++) {
				if (b[i].id_competition == nr) {
					cout << "Nazwa zawodow: " << b[i].competition_name << endl;
					cout << "Dystans: " << b[i].dystans << endl;
					cout << "Liczba zawodnikow: " << b[i].wyniki.size() << endl;
					cout << "Najlepszy czas: ";
					for (int p = 0; p < 10; p++) {
						cout << b[i].wyniki[0].wynik[p];
					}
					cout << endl;
					b[i].srednia();
					b[i].wyswietl(a);
				}
			}
			system("pause");
			system("cls");
			break;
		case '5':
			nb_zawody(b, a);
			system("pause");
			system("cls");
			break;
		case '0':
			i = '0';
			break;
		}
	}
}
int sprawdz(vector<User>& b)
{
	string log, pass;
	int flaga = 0, id;
	char c;
	while (flaga != 1) {
		
		cout << "Podaj login: ";
		cin >> log;
		cout << "Podaj haslo: ";
		while ((c = _getch()) != 13) // 13, to kod ENTERA, który koñczy wpisywanie has³a                                                               
		{
			cout << "*";
			pass =pass+c;
		}
		for (size_t i = 0; i < b.size(); i++) {
			if ((log == b[i].login) && (pass == b[i].haslo)) {
				flaga = 1;
				id = b[i].id_user;
			}
		}
		if (flaga == 0) {
			cout <<endl<< "Bledny login lub/i haslo" << endl;
			system("pause");
		}
		system("cls");
	}
	return id;
}
void zawodnicy_admin(vector<Runner>&a, vector<Competition>&b,vector<User>&c, int k) {
		char i = 6;
		int zmienna;
		int p;
		int dz=0;
		string dodatek;
		string exchange;
		int exchange_date;
		while (i != '0') {
			cout << endl << "ZARZADZANIE ZAWODNIKAMI" << endl;
			cout << "0.Wyjscie" << endl;
			cout << "1.Dodaj zawodnika" << endl;
			cout << "2.Lista zawodnikow" << endl;
			cin >> i;
			switch (i) {
			case '1':
				a.push_back(Runner(k));
				k++;
				/*p= a[a.size() - 1].id_zawodnika;
				while (p!0) {
					p / 10;
					dz++;
				}
				c.push_back(User(a[a.size() - 1].id_zawodnika, a[a.size() - 1].imie+dodatek, a[a.size() - 1].imie));
				*/
				system("pause");
				system("cls");
				break;
			case '2':
				lista_zawodnikow(a);
				system("pause");
				system("cls");
				break;
			case '0':
				i = '0';
				break;
			}
	}

}
void zapisz_runner(vector <Runner> &s) {

	ofstream plik;
	string nazwa = "runner.txt";
	string kamil;
	plik.open(nazwa, std::ios::out);
	if (plik.good()) {
		for (size_t i = 0; i < s.size(); i++) {
			plik << ";" << " " << s[i].id_zawodnika << " " << s[i].imie << " " << s[i].nazwisko << endl;
		}
		plik << ">";
		plik.close();
	}
	else {
		cout << "\n\nPlik nie zostal wczytany\n";
	}
}
void wczytaj_runner(vector <Runner> &s) {
	ifstream plik;

	string a, b, c;
	string linia;
	int  d;
	string nazwa = "runner.txt";
	plik.open(nazwa, std::ios::in);
	if (plik.good()) {
		char rodzaj;
		while (!plik.eof()) {
			plik >> rodzaj;
			switch (rodzaj) {
			case ';':
				plik >> d >> a >> b ;
				s.push_back(Runner(d, a, b));
				if (id_zawodnikav <= d) {
					id_zawodnikav = d + 1;
				}
				break;
			case '>':
				break;
			}
		}


		plik.close();
	}

	else {
		cout << "\n\nPlik nie zostal wczytany\n";
	}
}
void zapisz_user(vector <User> &s) {

	ofstream plik;
	string nazwa = "user.txt";
	string kamil,linia;
	plik.open(nazwa, std::ios::out);
	if (plik.good()) {
		for (size_t i = 0; i < s.size(); i++) {
			plik << ";" << " " << s[i].id_user << " " << s[i].login << " " << s[i].haslo << endl;
		}
		plik << ">";
		plik.close();
	}
	else {
		cout << "\n\nPlik nie zostal wczytany\n";
	}
}
void wczytaj_user(vector <User> &s) {
	ifstream plik;

	string a, b, c;
	string linia;
	int  d;
	string nazwa = "user.txt";
	plik.open(nazwa, std::ios::in);
	if (plik.good()) {
		char rodzaj;
		while (!plik.eof()) {
			plik >> rodzaj;
			switch (rodzaj) {
			case ';':
				plik >> d >> a >> b;
				s.push_back(User(d, a, b));
				break;
			case '>':
				break;
			}
		}


		plik.close();
	}

	else {
		cout << "\n\nPlik nie zostal wczytany\n";
	}
}
void zapisz_comp(vector <Competition> &s) {
	ofstream plik;
	string kamil;
	string nazwa = "competition.txt";
	plik.open(nazwa, std::ios::out);
	if (plik.good()) {
		for (size_t i = 0; i < s.size(); i++) {
			kamil = s[i].competition_name;
			replace(kamil.begin(), kamil.end(), ' ', '_');
			plik << ";" << kamil << " " << s[i].id_competition<<" " << s[i].dystans << endl;
		}
		plik << ">";
		plik.close();
	}
	else {
		cout << "\n\nPlik nie zostal wczytany\n";
	}
}
void wczytaj_comp(vector <Competition> &s) {
	ifstream plik;
	int id,dys;
	string linia, spec;
	string nazwa = "competition.txt";
	plik.open(nazwa, std::ios::in);
	if (plik.good()) {
		char rodzaj;
		while (!plik.eof()) {
			plik >> rodzaj;
			switch (rodzaj) {
			case ';':
				plik >> linia >> id>>dys;
				replace(linia.begin(), linia.end(), '_', ' ');
				s.push_back(Competition(linia, id,dys));
				if (id_zawodowv <= id) {
					id_zawodowv = id + 1;
				}
				break;
			case '>':
				break;
			}
		}


		plik.close();
	}

	else {
		cout << "\n\nPlik nie zostal wczytany\n";
	}
}
void zapisz_result(vector <Competition> &s) {
	ofstream plik;
	string nazwa = "result.txt";
	plik.open(nazwa, std::ios::out);
	if (plik.good()) {
		for (size_t i = 0; i < s.size(); i++) {
			plik << "`" << " "<< s[i].id_competition << endl;
			for (size_t j = 0; j < s[i].wyniki.size(); j++) {
				plik << ";" << " " << s[i].wyniki[j].id_z << " ";
				for (int z = 0; z < 10; z++) {
					plik << s[i].wyniki[j].wynik[z];
				}
				plik << endl;
			}
		}
		plik << ">";
		plik.close();
	}
	else {
		cout << "\n\nPlik nie zostal wczytany\n";
	}
}
void wczytaj_result(vector <Competition> &s) {
	ifstream plik;
	int id,liczba,zawody,klucz;
	char  tab[10];
	string linia, spec;
	string nazwa = "result.txt";
	plik.open(nazwa, std::ios::in);
	if (plik.good()) {
		char rodzaj;
		while (!plik.eof()) {
			plik >> rodzaj;
			switch (rodzaj) {
			case '`':
				plik >> zawody;

				break;
			case ';':
				for (size_t m = 0; m < s.size(); m++) {
					if (zawody == s[m].id_competition) {
						klucz = m;
					}
				}
				plik >> id  >> linia;
				for (int i = 0; i < 10; i++) {
					tab[i] = linia[i];
				}
				s[klucz].wyniki.push_back(Result(id,tab));
				break;
			case '>':
				break;
			}
		}
		for (size_t m = 0; m < s.size(); m++) {
			for (size_t i = 0; i < s[m].wyniki.size(); i++) {
				s[m].wyniki[i].to_sec();
			}
		}
		plik.close();
	}

	else {
		cout << "\n\nPlik nie zostal wczytany\n";
	}
}
int main()
{
	setlocale(LC_ALL, "");
	vector <Competition> zawody;
	vector <Runner> zawodnik;
	vector <User> konto;
	char i = 9;
	int zmienna;
	int pokaz;
	string log, pass;
	int user = -1;
	wczytaj_user(konto);
	wczytaj_runner(zawodnik);
	wczytaj_comp(zawody);
	wczytaj_result(zawody);
	int id_d;
	int dzialanie = 1;
	int nr;
	if (konto.size() == 0) {
		konto.push_back(User(0, "admin", "admin"));
	}
	i = '9';
	system("cls");
	while (i != '0') {
		cout << "0.Wyjscie" << endl;
		cout << "1.Zaloguj sie" << endl;
		cin >> i;
		switch (i) {
		case '1':
			user = sprawdz(konto);
			system("cls");
			i = '0';
			break;
		case '0':
			dzialanie = 0;
			break;
		}
	}
	while (dzialanie != 0) {
		if (user == 0) {

			i = '9';
			while (i != '0') {
				cout << endl << "MENU ADMINISTRATORA" << endl;
				cout << "0.Wyjscie" << endl;
				cout << "1.Zawodnicy" << endl;
				cout << "2.Zawody" << endl;
				cout << "3.Zmien haslo uzytkownika" << endl;
				cout << "4.Zmien swoje haslo" << endl;
				cout << "5.Zaloz konto zawodnikowi" << endl;
				cout << "6. Lista kont" << endl;
				cin >> i;
				switch (i) {
				case '1':

					zawodnicy_admin(zawodnik, zawody,konto, id_zawodnikav);
					system("cls");
					break;
				case '2':
					zawody_admin(zawodnik, zawody, id_zawodowv);
					system("cls");
					break;
				case '3':
					lista_zawodnikow(zawodnik);
					cout << "Podaj ID zawodnika ktoremu chesz zmienic haslo";
					cin >> id_d;
					for (size_t i = 0; i < konto.size(); i++) {
						if (konto[i].id_user == id_d)
							konto[i].nowe_pass();
					}
					system("cls");
					break;
				case '4':
					for (size_t i = 0; i < konto.size(); i++) {
						if (konto[i].id_user == user)
							konto[i].nowe_pass();
					}
					system("cls");
					break;
				case '5':
					konto.push_back(User(zawodnik, konto));
					system("cls");
					break;
				case '6':
					for (size_t i = 0; i < konto.size(); i++) {
						cout << konto[i].id_user << " Login: " << konto[i].login << endl;
					}
					system("cls");
					break;
				case '0':
					i = '0';
					break;
				}
			}
		}
	
		i = 9;
		if (user != 0) {
			i = '9';
			while (i != '0') {
				cout << endl << "MENU UZYTKOWNIKA" << endl;
				cout << "0.Wyjscie" << endl;
				cout << "1.Moje wyniki" << endl;
				cout << "2. Moje najlepsze czasy" << endl;
				cout << "3. Zmien swoje haslo" << endl;
				cin >> i;
				switch (i) {
				case '1':
					cout << "Moje wyniki" << endl;
					for (size_t i = 0; i < zawody.size(); i++) {
						zawody[i].wyswietl(zawodnik, user);
					}
					system("pause");
					system("cls");
					break;
				case '2':
					nb_zawodnik(zawody, user);
					system("pause");
					system("cls");
					break;
				case '3':
					for (size_t i = 0; i < konto.size(); i++) {
						if (konto[i].id_user == user)
							konto[i].nowe_pass();
					}
					break;
				case '0':
					i = '0';
					break;
				}
			}
		}
		i = '9';
		system("cls");
		while (i != '0') {
			cout << "0.Wyjscie" << endl;
			cout << "1.Zaloguj sie" << endl;
			cin >> i;
			switch (i) {
			case '1':
				user = sprawdz(konto);
				system("cls");
				i = '0';
				break;
			case '0':
				dzialanie = 0;
				break;
			}
		}
		
	}
	zapisz_runner(zawodnik);
	zapisz_comp(zawody);
	zapisz_result(zawody);
	zapisz_user(konto);
    return 0;
}

