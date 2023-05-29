#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;

void setWesternEuropeanCodePage() {
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
}
int main() {
	setWesternEuropeanCodePage();
	string myText; int counter = 0;


	ifstream fil("text.txt");
	if (fil.is_open()); {
		string rad;
		int antal_rad= 0;
		int antal_ord= 0;
		int antal_ord_stycke = 0;
		int vilket_stycke = 1;

		while (getline(fil, rad)) {
			antal_rad++;
		}


		if (rad.empty());
		antal_rad++;
		cout << "Ord i stycke: " << vilket_stycke<< antal_ord_stycke<<endl;
		antal_ord_stycke = 0;
		vilket_stycke++;
		
	}



	while (getline(fil, myText)) {
		counter++;
	}
	cout << "antal ord: " << counter;
	fil.close();


}