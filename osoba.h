#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class osoba
{
public:
	static int id;
	string ime;
	string prezime;
	int god{};
	void setName();
	void setLname();
	void setGod();
	string getName();
	string getLname();
	int getGod();
	void unosDat();
	void ispisOsoba();
	void ispisOdrOsoba(int brid);
	void izbrisiOsobu(int brid);
	int maxID();
	int maxID2();
	bool findID(int brid);
	void orderAllIDs();
	osoba();
	~osoba(){}
};

