#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>

using namespace std;
struct Temperatur {
	string town;
	string temp;
	string season;

};

int fahrToCelcius(string fahr) {
	int celcius;
	int stringfahr;
	stringfahr = stoi(fahr);
	celcius = (stringfahr - 32) * 5 / 9;
	return celcius;
}

void readFile(string filnamnread, string filnamnwrite) {
	bool run = true;
	Temperatur temperatur;
	
		


		string line;
		ifstream MyReadFile(filnamnread);
		while (getline(MyReadFile, line)) {

			stringstream ss(line);
			getline(ss, temperatur.town, ',');
			getline(ss, temperatur.temp, ',');
			getline(ss, temperatur.season);

			cout << temperatur.town << "," << fahrToCelcius(temperatur.temp) << "," << temperatur.season << endl;
			ofstream myWriteFile(filnamnwrite, ios::app);
			myWriteFile << temperatur.town << "," << fahrToCelcius(temperatur.temp) << "," << temperatur.season << endl;
			myWriteFile.close();



		}
		MyReadFile.close();


	

}



int main() {
	bool run = true;

	while (run) {
		string filnamnread;
		string filnamnwrite;
		Temperatur temperatur;


		cout << "Ange vilken fil du vill öppna:(0 för att avsluta) ";
		cin >> filnamnread;
		if (filnamnread == "0")
			break;

		cout << "Ange vilken fil du vill skriva till: ";
		cin >> filnamnwrite;
		
		readFile(filnamnread, filnamnwrite);

		

	}
}