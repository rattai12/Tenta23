/*
* 
* int main()
{
    //setWesternEuropeanCodePage();
    setlocale(LC_ALL, "sv_SE.UTF-8"); // G�r s� svenska tecken fungerar i programmet. 

    int menyval;
    while (true) {
        //setColor(FOREGROUND_BLUE);
        cout << "\033[1;34m#############################################################" <<endl;
        cout << "######################## Uppgift 1 ##########################" << endl;
        cout << "#############################################################" << endl;
        cout << "##                                                         ##" << endl;
        cout << "##\033[0m    1. Gissa en siffra                                   \033[1;34m##"<< endl;
        cout << "##\033[0m    2. Skriv ut alla kort i en kortlek                   \033[1;34m##" << endl;
        cout << "##\033[0m    3. R�kna ut om ett �r �r ett skott�r                 \033[1;34m##" << endl;
        cout << "##\033[0m    4. G�r avancerade matematiska ber�kningar            \033[1;34m##" << endl;
        cout << "##\033[0m    5. Inst�llningar                                     \033[1;34m##" << endl;
        cout << "##\033[0m    0. Avbryt                                            \033[1;34m##" << endl;
        cout << "#############################################################" << endl;
        cout << "Alternativ: ";
        cin >> menyval;

        switch (menyval) {

        case 1:
            gissatal();
            Sleep(3000); // f�rdr�jer 3sek innan man �terv�nder till menyn
            clear(); // rensar konsolen, inte snyggt, men g�r jobbet.
            break; //avbryter och �terv�nder till huvudmenyn
        case 2:
            slumpakort();
            Sleep(3000);
            clear();
            break;
        case 3:
            skottar();
            Sleep(3000);
            clear();
            break;
        case 4:
            funktion();
            Sleep(3000);
            clear();
            break;
        case 5: 
            installningar();
            Sleep(3000);
            clear();
            break;
        case 0:
            return 0;
        }

        cout << endl;
        
    }
    return 0;

}
    


*/