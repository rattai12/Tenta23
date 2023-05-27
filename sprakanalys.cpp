#include <iostream>
#include<windows.h>
#include <fstream>
#include <sstream>
#include <string>
#include "ordlista.h"
#include <iomanip>
#include <vector>

using namespace std;
vector<string>ordlista; //global så alla kan komma åt
void svenska() {
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
}
void clearOrdlista() {
	ordlista.clear();
}


void readFile(string filnamn) {

	string rad;
	string ord;
	ifstream minText(filnamn);
	if (!minText) {
		cout << "Kan inte hitta filen." << endl;
		return;
	}
	else {

		while (getline(minText, rad)) {
			stringstream ss(rad);
			while (ss >> ord)
				ordlista.push_back(ord);
		}
	};

}

float decideLanguage(int antal_ord) {

	if (antal_ord == 0) {
		return 0;
	}
	else {
		float procent = static_cast<float>(size(ordlista) / antal_ord);
		return procent;
	}
}

void countWordsSwed(vector <string> ordlistaCompare) { // denna funktion ska räkna igenom och jämföra texten med de svenska orden. 
	int word_counter_sve = 0;
	int tot_word = 0;
	for (int i = 0; i < size(ord_sve); i++) {
		word_counter_sve = 0;
		for (int j = 0; j < size(ordlistaCompare); j++) {
			if (ord_sve[i] == ordlistaCompare[j]) {
				word_counter_sve++;
				tot_word++;
			}
			else {
				continue;
			}


		}
		cout << setw(10) << ord_sve[i] << setw(5) << word_counter_sve << endl;
		


	}
	cout << " Totalt antal svenska ord är " << tot_word << endl;
	cout << decideLanguage(tot_word) << " % andel svenska ord" <<endl;
}

void countWordsEng(vector<string>ordlistaCompareEng) {
	int word_counter_eng = 0;
	int tot_word_eng = 0;
	for (int i = 0; i < size(ord_eng); i++) {
		word_counter_eng = 0;
		for (int j = 0; j < size(ordlistaCompareEng); j++) {
			if (ord_eng[i] == ordlistaCompareEng[j]) {
				word_counter_eng++;
				tot_word_eng++;
			}
			else {
				continue;
			}


		}
		cout << setw(10) << ord_eng[i] << setw(5) << word_counter_eng << endl;
		

	}
	cout << " Totalt antal engelska ord är " << tot_word_eng << endl;
	cout <<  decideLanguage(tot_word_eng) << " % andel engelska ord"<<endl;
}



int main() {
	svenska();
	bool run = true;
	while (run) {

		string filnamn;

		cout << "Ange vilken fil du vill jämföra(0 för att avsluta) : ";
		cin >> filnamn;
		if (filnamn == "0") {
			run = false;
		}
		readFile(filnamn);
		cout << "Totalt antal ord i texten: " << size(ordlista) << endl;
		countWordsSwed(ordlista); 
		countWordsEng(ordlista);
		clearOrdlista();

	}


}