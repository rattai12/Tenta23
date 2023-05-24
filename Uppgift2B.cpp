#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;


struct Fagel {
    string Fageltyp;
    string SvenskFagel;
    string LatinFagel;
    int observation;

};
void setWesternEuropeanCodePage() {
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252);
}

string printType(string Typ) { // Funktion som �vers�tter teckenkod till text
    string typfagel = "";
    if (Typ == "B") // "�vers�tter" statuskoden till text
        typfagel = "Boende art som h�ckar i Sverige";
    else if (Typ == "R")
        typfagel = "Rastande art som bes�ker Sverige under flyttning";
    else if (Typ == "b")
        typfagel = "Boplats som inte anses etablerad";
    else if (Typ == "O")
        typfagel = "Art som inte h�ckar i Sverige";
    else if (Typ == "R")
        typfagel = "Ovanlig f�gel";
    else if (Typ  == "M")
        typfagel = "Flyttf�gel";

    return typfagel;

}

void ReadBirdFromFile(vector<Fagel>& faglar) {
    setWesternEuropeanCodePage();
    //Skriv in filnamnet fr�n anv�ndare
    cout << "Ange filnamn: ";
    string filnamn;
    cin >> filnamn;

    //�ppna filen;

    ifstream infile(filnamn);
    if (!infile) {
        cout << "Kan inte hitta filen." << endl;
        return;
    }
    vector <Fagel> faglarna;
    string line;
    int raknare = 0;

    while (getline(infile, line) && raknare < 100) {  // && betyder and
        if (faglar.size() >= 100) {
            cout << "FELFEL: Endast 100 f�glar f�r skrivas in!" << endl;
            break;
        }
        istringstream iss(line);

        Fagel fagel;
        getline(iss >> ws, fagel.Fageltyp, ','); //getline l�ser varje rad och plockar ut varje del i structen. G�r en �vning f�r att plocka ur med hj�lp av substring och find. 
        getline(iss >> ws, fagel.SvenskFagel, ','); // iss >> ws, tar bort f�rsta whitespace, s� att f�rsta bokstaven l�ses.
        getline(iss >> ws, fagel.LatinFagel, ',');
        iss >> fagel.observation;

        string extra;
        getline(iss, extra);

        
        faglar.push_back(fagel); // l�gger in faglarna i vektorn
        raknare++;

    }
    }

void WriteToFile(vector<Fagel> faglar) {
    
    if (faglar.empty()) {
        cout << "Listan verkar vara tom..." << endl;
        return;
    }
    ofstream minfil("fagel_document.txt");

    if (minfil.is_open()) {

        for (int i = 0; i < faglar.size(); i++) {

            minfil << faglar[i].Fageltyp << "\n";
            minfil << faglar[i].SvenskFagel << "\n";
            minfil << faglar[i].LatinFagel << "\n";
            minfil << faglar[i].observation << "\n";
            minfil << "hej";
        }
        minfil.close();
    }

    
    

}
int main()
{

    setWesternEuropeanCodePage();
    int menyval;
    vector<Fagel> faglar;

    while (true) {

        cout << "#############################################################" << endl;
        cout << "######################## Uppgift 2B #########################" << endl;
        cout << "#############################################################" << endl;
        cout << "##                                                         ##" << endl;
        cout << "##             Totalt Antal F�glar: " << faglar.size() << "                      ##" << endl;
        cout << "##                                                         ##" << endl;
        cout << "##     1. L�gg till f�glar fr�n fil                        ##" << endl;
        cout << "##     2. Visa alla f�glar                                 ##" << endl;
        cout << "##     3. Visa vanliga f�glar                              ##" << endl;
        cout << "##     4. Skriv till fil                                   ##" << endl;
        cout << "##     5. T�m listan                                       ##" << endl;
        cout << "##     6. Avsluta                                          ##" << endl;

        cout << "#############################################################" << endl;
        cout << "Alternativ: ";
        cin >> menyval;

        switch (menyval)

        {

        case 1: {

            cout << "Menyval 1 \n L�gg till f�glar fr�n fil" << endl;
            system("cls"); //rensar consolen
            ReadBirdFromFile(faglar);//anropar funktionen
        }break;
        case 2: {
            system("cls");
            cout << "Menyval 2 \n Visa alla f�glar" << endl;
            int counter_print = 0;
            for (Fagel fagel : faglar) {
                cout << " Typ av f�gel: " << printType(fagel.Fageltyp) << "\n Svenskt namn: " << fagel.SvenskFagel << "\n Latinskt namn: " << fagel.LatinFagel << "\n Hur m�nga observationer som gjorts: " << fagel.observation << "\n" << endl;
                counter_print++;
                if (counter_print % 20 == 0) {
                    cout << "\u001b[31mTryck enter f�r att visa 20 nya f�glar...\u001b[0m" << endl;
                    cin.ignore();
                }
            }}
            break;


        case 3: {
            cout << "Menyval 3 \n Visa vanliga f�glar" << endl;
            int max_obs;
            cout << "Visa vanliga f�glar, ange minimum observationer: ";
            cin >> max_obs; 
            system("cls");
            int counter_print3 = 0;
            for (Fagel fagel : faglar) {
                if (fagel.observation >= max_obs) {
                    cout << " Typ av f�gel: " << printType(fagel.Fageltyp) << "\n Svenskt namn: " << fagel.SvenskFagel << "\n Latinskt namn: " << fagel.LatinFagel << "\n Hur m�nga observationer som gjorts: " << fagel.observation << "\n" << endl; // skriver ut alla f�glar, printtype anropar funktionen och skriver ut statusen i text ist�llet f�r kod
                    counter_print3++;
                    if (counter_print3 % 20 == 0) {
                        cout << "Tryck enter f�r att visa 20 nya f�glar..." << endl;
                        cin.ignore();
                    }
                    else {
                        continue;
                    }

                }
            }}
                break;

        case 4: {
            cout << "Vill du skriva f�glarna till fil? Tryck enter: ";
            cin.ignore();
            vector<Fagel>faglar;
            WriteToFile(vector<Fagel> (faglar));




        }
              break;

        case 5:
        {
            faglar.clear();
            
            cout << "T�mmer listan.. " << endl;

        }
        break;
        case 6:
            cout << "Menyval 5 \n Avslutar programmet..." << endl;
            return 0;
            break;
            }

        }
    }


    /* fstream file;
    file.open("fagel_fil_1.txt", ios_base::out);

    for (auto content : document)
    {
        file << content << endl;
    }
    file.close();
*/