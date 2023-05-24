#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Flygplan {
public:
    string flygplansid;
    string märke;
    int antalTimmarIDrift;
    int tillverkningsår;

    Flygplan(string id, string mark, int timmar, int år) {
        flygplansid = id;
        märke = mark;
        antalTimmarIDrift = timmar;
        tillverkningsår = år;
    }

    void print() {
        cout << "Flygplan ID: " << flygplansid << endl;
        cout << "Märke: " << märke << endl;
        cout << "Antal timmar i drift: " << antalTimmarIDrift << endl;
        cout << "Tillverkningsår: " << tillverkningsår << endl;
    }
};

class Anställd {
public:
    string namn;
    string personnummer;
    string tjänstetitel;

    Anställd(string name, string pnr, string title) {
        namn = name;
        personnummer = pnr;
        tjänstetitel = title;
    }

    void print() {
        cout << "Anställd: " << namn << endl;
        cout << "Personnummer: " << personnummer << endl;
        cout << "Tjänstetitel: " << tjänstetitel << endl;
    }
};

class Resenär {
public:
    string namn;
    string personnummer;

    Resenär(string name, string pnr) {
        namn = name;
        personnummer = pnr;
    }

    void print() {
        cout << "Resenär: " << namn << endl;
        cout << "Personnummer: " << personnummer << endl;
    }
};

class Flight {
public:
    string datumOchTid;
    Flygplan* flygplan;
    vector<Anställd*> personal;
    vector<Resenär*> resenärer;

    Flight(string datetime, Flygplan* plane, vector<Anställd*> crew, vector<Resenär*> passengers) {
        datumOchTid = datetime;
        flygplan = plane;
        personal = crew;
        resenärer = passengers;
    }

    void print() {
        cout << "Datum och tid: " << datumOchTid << endl;
        cout << "Flygplan: " << flygplan->flygplansid << endl;
        cout << "Personal:" << endl;
        for (Anställd* a : personal) {
            cout << "- " << a->namn << endl;
        }
        cout << "Resenärer:" << endl;
        for (Resenär* r : resenärer) {
            cout << "- " << r->namn << endl;
        }
    }

    void updateTid(string newTime) {
        datumOchTid = newTime;
    }

    void addResenär(Resenär* passenger) {
        resenärer.push_back(passenger);
    }

    void updatePersonal(vector<Anställd*> newCrew) {
        personal = newCrew;
    }
};

int main() {
    // Skapa flygplan
    Flygplan* plane1 = new Flygplan("ABC123", "Boeing 737", 5000, 2010);
    Flygplan* plane2 = new Flygplan("XYZ789", "Airbus A320", 3000, 2015);

    // Skapa anställda
    Anställd* employee1 = new Anställd("John Doe", "19800101-1234", "Pilot");
    Anställd* employee2 = new Anställd("Jane Smith", "19900505-5678", "Kabinpersonal");

    // Skapa resenärer
    Resenär* passenger1 = new Resenär("Alice Johnson", "19851212-9876");
    Resenär* passenger2 = new Resenär("Bob Anderson", "19771122-6543");

    // Skapa flighter
    vector<Anställd*> crew1 = { employee1, employee2 };
    vector<Resenär*> passengers1 = { passenger1, passenger2 };
    Flight* flight1 = new Flight("2023-05-24 10:00", plane1, crew1, passengers1);

    vector<Anställd*> crew2 = { employee2 };
    vector<Resenär*> passengers2 = { passenger1 };
    Flight* flight2 = new Flight("2023-05-25 12:30", plane2, crew2, passengers2);

    // Anropa metoder för att uppdatera flight
    flight1->updateTid("2023-05-24 11:30");
    flight1->addResenär(passenger2);
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
