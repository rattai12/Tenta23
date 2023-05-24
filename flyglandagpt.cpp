#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Flygplan {
public:
    string flygplansid;
    string m�rke;
    int antalTimmarIDrift;
    int tillverknings�r;

    Flygplan(string id, string mark, int timmar, int �r) {
        flygplansid = id;
        m�rke = mark;
        antalTimmarIDrift = timmar;
        tillverknings�r = �r;
    }

    void print() {
        cout << "Flygplan ID: " << flygplansid << endl;
        cout << "M�rke: " << m�rke << endl;
        cout << "Antal timmar i drift: " << antalTimmarIDrift << endl;
        cout << "Tillverknings�r: " << tillverknings�r << endl;
    }
};

class Anst�lld {
public:
    string namn;
    string personnummer;
    string tj�nstetitel;

    Anst�lld(string name, string pnr, string title) {
        namn = name;
        personnummer = pnr;
        tj�nstetitel = title;
    }

    void print() {
        cout << "Anst�lld: " << namn << endl;
        cout << "Personnummer: " << personnummer << endl;
        cout << "Tj�nstetitel: " << tj�nstetitel << endl;
    }
};

class Resen�r {
public:
    string namn;
    string personnummer;

    Resen�r(string name, string pnr) {
        namn = name;
        personnummer = pnr;
    }

    void print() {
        cout << "Resen�r: " << namn << endl;
        cout << "Personnummer: " << personnummer << endl;
    }
};

class Flight {
public:
    string datumOchTid;
    Flygplan* flygplan;
    vector<Anst�lld*> personal;
    vector<Resen�r*> resen�rer;

    Flight(string datetime, Flygplan* plane, vector<Anst�lld*> crew, vector<Resen�r*> passengers) {
        datumOchTid = datetime;
        flygplan = plane;
        personal = crew;
        resen�rer = passengers;
    }

    void print() {
        cout << "Datum och tid: " << datumOchTid << endl;
        cout << "Flygplan: " << flygplan->flygplansid << endl;
        cout << "Personal:" << endl;
        for (Anst�lld* a : personal) {
            cout << "- " << a->namn << endl;
        }
        cout << "Resen�rer:" << endl;
        for (Resen�r* r : resen�rer) {
            cout << "- " << r->namn << endl;
        }
    }

    void updateTid(string newTime) {
        datumOchTid = newTime;
    }

    void addResen�r(Resen�r* passenger) {
        resen�rer.push_back(passenger);
    }

    void updatePersonal(vector<Anst�lld*> newCrew) {
        personal = newCrew;
    }
};

int main() {
    // Skapa flygplan
    Flygplan* plane1 = new Flygplan("ABC123", "Boeing 737", 5000, 2010);
    Flygplan* plane2 = new Flygplan("XYZ789", "Airbus A320", 3000, 2015);

    // Skapa anst�llda
    Anst�lld* employee1 = new Anst�lld("John Doe", "19800101-1234", "Pilot");
    Anst�lld* employee2 = new Anst�lld("Jane Smith", "19900505-5678", "Kabinpersonal");

    // Skapa resen�rer
    Resen�r* passenger1 = new Resen�r("Alice Johnson", "19851212-9876");
    Resen�r* passenger2 = new Resen�r("Bob Anderson", "19771122-6543");

    // Skapa flighter
    vector<Anst�lld*> crew1 = { employee1, employee2 };
    vector<Resen�r*> passengers1 = { passenger1, passenger2 };
    Flight* flight1 = new Flight("2023-05-24 10:00", plane1, crew1, passengers1);

    vector<Anst�lld*> crew2 = { employee2 };
    vector<Resen�r*> passengers2 = { passenger1 };
    Flight* flight2 = new Flight("2023-05-25 12:30", plane2, crew2, passengers2);

    // Anropa metoder f�r att uppdatera flight
    flight1->updateTid("2023-05-24 11:30");
    flight1->addResen�r(passenger2);
    flight2->updatePersonal(crew1);

    // Skriv ut all data
    plane1->print();
    cout << endl;
    plane2->print();
    cout << endl;
    employee1->print();
    cout << endl;
    employee2->print();
    cout << endl;
    passenger1->print();
    cout << endl;
    passenger2->print();
    cout << endl;
    flight1->print();
    cout << endl;
    flight2->print();

    // Rensa minne
    delete plane1;
    delete plane2;
    delete employee1;
    delete employee2;
    delete passenger1;
    delete passenger2;
    delete flight1;
    delete flight2;

    return 0;
}
