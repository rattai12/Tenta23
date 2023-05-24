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

string printType(string Typ) { // Funktion som översätter teckenkod till text
    string typfagel = "";
    if (Typ == "B") // "Översätter" statuskoden till text
        typfagel = "Boende art som häckar i Sverige";
    else if (Typ == "R")
        typfagel = "Rastande art som besöker Sverige under flyttning";
    else if (Typ == "b")
        typfagel = "Boplats som inte anses etablerad";
    else if (Typ == "O")
        typfagel = "Art som inte häckar i Sverige";
    else if (Typ == "R")
        typfagel = "Ovanlig fågel";
    else if (Typ  == "M")
        typfagel = "Flyttfågel";

    return typfagel;

}

void ReadBirdFromFile(vector<Fagel>& faglar) {
    setWesternEuropeanCodePage();
    //Skriv in filnamnet från användare
    cout << "Ange filnamn: ";
    string filnamn;
    cin >> filnamn;

    //Öppna filen;

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
            cout << "FELFEL: Endast 100 fåglar får skrivas in!" << endl;
            break;
        }
        istringstream iss(line);

        Fagel fagel;
        getline(iss >> ws, fagel.Fageltyp, ','); //getline läser varje rad och plockar ut varje del i structen. Gör en övning för att plocka ur med hjälp av substring och find. 
        getline(iss >> ws, fagel.SvenskFagel, ','); // iss >> ws, tar bort första whitespace, så att första bokstaven läses.
        getline(iss >> ws, fagel.LatinFagel, ',');
        iss >> fagel.observation;

        string extra;
        getline(iss, extra);

        
        faglar.push_back(fagel); // lägger in faglarna i vektorn
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
        cout << "##             Totalt Antal Fåglar: " << faglar.size() << "                      ##" << endl;
        cout << "##                                                         ##" << endl;
        cout << "##     1. Lägg till fåglar från fil                        ##" << endl;
        cout << "##     2. Visa alla fåglar                                 ##" << endl;
        cout << "##     3. Visa vanliga fåglar                              ##" << endl;
        cout << "##     4. Skriv till fil                                   ##" << endl;
        cout << "##     5. Töm listan                                       ##" << endl;
        cout << "##     6. Avsluta                                          ##" << endl;

        cout << "#############################################################" << endl;
        cout << "Alternativ: ";
        cin >> menyval;

        switch (menyval)

        {

        case 1: {

            cout << "Menyval 1 \n Lägg till fåglar från fil" << endl;
            system("cls"); //rensar consolen
            ReadBirdFromFile(faglar);//anropar funktionen
        }break;
        case 2: {
            system("cls");
            cout << "Menyval 2 \n Visa alla fåglar" << endl;
            int counter_print = 0;
            for (Fagel fagel : faglar) {
                cout << " Typ av fågel: " << printType(fagel.Fageltyp) << "\n Svenskt namn: " << fagel.SvenskFagel << "\n Latinskt namn: " << fagel.LatinFagel << "\n Hur många observationer som gjorts: " << fagel.observation << "\n" << endl;
                counter_print++;
                if (counter_print % 20 == 0) {
                    cout << "\u001b[31mTryck enter för att visa 20 nya fåglar...\u001b[0m" << endl;
                    cin.ignore();
                }
            }}
            break;


        case 3: {
            cout << "Menyval 3 \n Visa vanliga fåglar" << endl;
            int max_obs;
            cout << "Visa vanliga fåglar, ange minimum observationer: ";
            cin >> max_obs; 
            system("cls");
            int counter_print3 = 0;
            for (Fagel fagel : faglar) {
                if (fagel.observation >= max_obs) {
                    cout << " Typ av fågel: " << printType(fagel.Fageltyp) << "\n Svenskt namn: " << fagel.SvenskFagel << "\n Latinskt namn: " << fagel.LatinFagel << "\n Hur många observationer som gjorts: " << fagel.observation << "\n" << endl; // skriver ut alla fåglar, printtype anropar funktionen och skriver ut statusen i text istället för kod
                    counter_print3++;
                    if (counter_print3 % 20 == 0) {
                        cout << "Tryck enter för att visa 20 nya fåglar..." << endl;
                        cin.ignore();
                    }
                    else {
                        continue;
                    }

                }
            }}
                break;

        case 4: {
            cout << "Vill du skriva fåglarna till fil? Tryck enter: ";
            cin.ignore();
            vector<Fagel>faglar;
            WriteToFile(vector<Fagel> (faglar));




        }
              break;

        case 5:
        {
            faglar.clear();
            
            cout << "Tömmer listan.. " << endl;

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