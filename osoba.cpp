#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "osoba.h"

using namespace std;

void osoba::setName()
{
	cout << "Unesite ime: ";
	getline(cin, this->ime);
}

void osoba::setLname()
{
	cout << "Unesite prezime: ";
	getline(cin, this->prezime);
}

void osoba::setGod()
{
	cout << "Unesite broj godina osobe: ";
	cin >> this->god;
	cin.ignore();
}

string osoba::getName()
{
	return this->ime;
}

string osoba::getLname()
{
	return this->prezime;
}

int osoba::getGod()
{
	return this->god;
}

void osoba::unosDat()
{
	fstream allfiles;
	allfiles.open("C:/Users/Public/Documents/SaveFiles/allfiles.txt", ios::in);
	if (allfiles.is_open())
	{
		string allid;
		while (getline(allfiles, allid))
		{
			if (stoi(allid) == id)
			{
				id++;
			}
			//cout << allid << endl;
		}
		cout << "ID kreirane osobe je: " << id << endl; // works
		allfiles.close();
	}
	setName();
	setLname();
	setGod();
	allfiles.clear();
	allfiles.open("C:/Users/Public/Documents/SaveFiles/allfiles.txt", ios::app); //"allfiles.txt"
	if (allfiles.is_open())
	{
		allfiles << id << endl;
		allfiles.close();
	}
	else cout << "File couldn't be open." << endl;
	//cout << to_string(id) << endl;
	orderAllIDs();
	fstream file;
	//file.open(getName() + ".txt", ios::app); // works
	//file.open(ime + ".txt", ios::app); // works
	file.open("C:/Users/Public/Documents/SaveFiles/" + to_string(id) + ".txt", ios::out);
	if (file.is_open())
	{
		file << "ID: " << id << endl;
		file << "Ime: " << ime << " " << prezime << endl;
		file << "Godina: " << god << endl;
		file.close();
	}
	else cout << "File is not found!";
	//cout << getName() << " ==> ID: " << id << endl;
}

int osoba::maxID()
{
	int maxID = 0;
	string line;
	fstream allfiles;
	allfiles.open("C:/Users/Public/Documents/SaveFiles/allfiles.txt", ios::in);
	if (allfiles.is_open())
	{
		while (getline(allfiles, line))
		{
			maxID++;
		}
		return maxID;
		allfiles.close();
	}
	else
	{
		cout << "Ne postoji file!";
		return maxID;
	}
}

int osoba::maxID2()
{
	int maxID2 = 0;
	string line;
	fstream allfiles;
	allfiles.open("C:/Users/Public/Documents/SaveFiles/allfiles.txt", ios::in);
	if (allfiles.is_open())
	{
		while (getline(allfiles, line))
		{
			if (stoi(line) > maxID2)
			{
				maxID2 = stoi(line);
			}
		}
		return maxID2;
		allfiles.close();
	}
	else
	{
		cout << "Ne postoji file!";
		return maxID2;
	}
}

void osoba::ispisOsoba()
{
	fstream file;
	osoba o;
	for (int i = 0; i <= o.maxID2(); i++) // o.maxID()
	{
		file.open("C:/Users/Public/Documents/SaveFiles/" + to_string(i) + ".txt", ios::in);
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				cout << line << endl;
			}
			cout << "----------------------------" << endl;
		}
		file.close();
	}
}

bool osoba::findID(int brid)
{
	fstream allfiles;
	allfiles.open("C:/Users/Public/Documents/SaveFiles/allfiles.txt", ios::in);
	if (allfiles.is_open())
	{
		string line;
		while (getline(allfiles, line))
		{
			if (stoi(line) == brid)
			{
				return true;
			}
		}
	}
	else cout << "File ne postoji!" << endl;
	allfiles.close();
}

void osoba::ispisOdrOsoba(int brid)
{
	fstream file;
	file.open("C:/Users/Public/Documents/SaveFiles/" + to_string(brid) + ".txt", ios::in);
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			cout << line << endl;
		}
	}
	else cout << "File ne postoji!";
	file.close();
}

void osoba::izbrisiOsobu(int brid)
{
	string s = "C:/Users/Public/Documents/SaveFiles/" + to_string(brid) + ".txt";
	if (remove(s.c_str()) != 0)
	{
		cout << "File ne postoji!" << endl;
	}
	else cout << "File uklonjen!" << endl;
	fstream allfiles, allfiles2;
	allfiles.open("C:/Users/Public/Documents/SaveFiles/allfiles.txt", ios::in);
	allfiles2.open("C:/Users/Public/Documents/SaveFiles/allfiles2.txt", ios::out);
	if (allfiles.is_open() && allfiles2.is_open())
	{
		string line;
		while (getline(allfiles, line))
		{
			if (stoi(line) != brid)
			{
				allfiles2 << line << endl;
			}
		}
	}
	allfiles.close();
	allfiles2.close();
	string str = "C:/Users/Public/Documents/SaveFiles/allfiles.txt";
	string str2 = "C:/Users/Public/Documents/SaveFiles/allfiles2.txt";
	remove(str.c_str());
	//rename(str2.c_str(), str.c_str());
	if (rename(str2.c_str(), str.c_str()) == 0)
	{
		//cout << "Uspjesno promjenjeno ime file - a!" << endl;
	}
	else cout << "Ime file - a se nije promjenilo. Doslo je do greske!" << endl;
}

void osoba::orderAllIDs()
{
	fstream allfiles, allfiles2;
	vector<int> order;
	allfiles.open("C:/Users/Public/Documents/SaveFiles/allfiles.txt", ios::in);
	allfiles2.open("C:/Users/Public/Documents/SaveFiles/allfiles2.txt", ios::out);
	if (allfiles.is_open() && allfiles2.is_open())
	{
		string line;
		while (getline(allfiles, line))
		{
			order.push_back(stoi(line));
		}
		sort(order.begin(), order.end());
		for (int i = 0; i < order.size(); i++)
		{
			allfiles2 << order[i] << endl;
			//cout << order[i] << endl;
		}
	}
	else cout << "Jedan od file - ova ne postoji!" << endl;
	allfiles.close();
	allfiles2.close();
	string str = "C:/Users/Public/Documents/SaveFiles/allfiles.txt";
	string str2 = "C:/Users/Public/Documents/SaveFiles/allfiles2.txt";
	remove(str.c_str());
	if (rename(str2.c_str(), str.c_str()) == 0)
	{
		//cout << "Ime uspjesno promjenjeno!" << endl;
	}
	else cout << "Doslo je do greske!" << endl;
}

osoba::osoba()
{

}