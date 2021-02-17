#include <iostream>
#include <fstream>
#include "osoba.h"

using namespace std;

int osoba::id = 0;

void ui(int &broj)
{
	POC:
	cout << "[1] Unesite osobu u sistem" << endl;
	cout << "[2] Ispisite sve osobe u sistemu" << endl;
	cout << "[3] Ispisite odredjenu osobu pomocu ID - a" << endl;
	cout << "[4] Obrisite osobu iz sistema" << endl;
	cout << "[5] Napustiti sistem" << endl;
	cout << "Opcija koju birate: ";
	cin >> broj;
	if (broj > 0 && broj < 6)
	{
		if (broj == 1)
		{
			cin.ignore();
			system("CLS");
			osoba o;
			o.unosDat();
			cout << "ID: " << o.id << endl;
			cout << "Ime: " << o.ime << " " << o.prezime << endl;
			cout << "Godina: " << o.god << endl;
			o.id++;
			system("PAUSE");
			system("CLS");
			goto POC;
		}
		else if (broj == 2)
		{
			system("CLS");
			osoba o;
			cout << "Ukupno je registrovano " << o.maxID() << " osoba u sistem." << endl;
			o.ispisOsoba();
			//o.orderAllIDs(); // test
			system("PAUSE");
			system("CLS");
			goto POC;
		}
		else if (broj == 3)
		{
			cin.ignore();
			int brid;
			system("CLS");
			osoba o;
			cout << "Unesite id osobe cije podatke zelite prikazati: ";
			cin >> brid;
			if (o.findID(brid) == true)
			{
				cout << "Osoba s tim ID - om postoji!" << endl;
				o.ispisOdrOsoba(brid);
			}
			else
			{
				cout << "Unijeli ste pogresan ID!" << endl;
			}
			system("PAUSE");
			system("CLS");
			goto POC;
		}
		else if (broj == 4)
		{
			cin.ignore();
			int brid;
			system("CLS");
			osoba o;
			cout << "Unesite id osobe cije podatke zelite obrisati: ";
			cin >> brid;
			if (o.findID(brid) == true)
			{
				cout << "Osoba s tim ID - om postoji!" << endl;
				o.izbrisiOsobu(brid);
				o.id = 0;
			}
			else
			{
				cout << "Unijeli ste pogresan ID!" << endl;
			}
			system("PAUSE");
			system("CLS");
			goto POC;
		}
		else if (broj == 5)
		{
			system("EXIT");
		}
	}
	else if(cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		system("CLS");
		cout << "Unijeli ste pogresan broj, unesite drugi broj!" << endl;
		goto POC;
	}
	else
	{
		system("CLS");
		cout << "Unijeli ste pogresan broj, unesite drugi broj!" << endl;
		goto POC;
	}
}

int main()
{
	int br;
	ui(br);
	return 0;
}