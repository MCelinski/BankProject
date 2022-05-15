#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "klasy.h"
#include <conio.h>
#include <ctime>
#include <stdlib.h>
using namespace std;


void zapisp(vector <KontoPrywatne> &klienciP, KontoPrywatne &klientP){

        fstream dane;
        dane.open("dane.txt",ios::out);
        dane.clear();
        dane.close();
        dane.open("dane.txt",ios::out);
        for(int i=0;i<klienciP.size();i++)
        {
       dane << klienciP[i].imie<<"\n";
        dane << klienciP[i].nazwisko<<"\n";
        dane << klienciP[i].miejscowosc<<"\n";
        dane << klienciP[i].pesel<<"\n";
        dane << klienciP[i].login<<"\n";
        dane << klienciP[i].haslo<<"\n";
        dane << klienciP[i].srodki<<"\n";
        dane << klienciP[i].nr_k<<"\n";
        }
    dane.close();
    }

   void zapisf(vector <KontoFirmowe> &klienciF, KontoFirmowe &klientF){

        fstream dane;
        dane.open("danef.txt",ios::out);
        dane.clear();
        dane.close();
        dane.open("danef.txt",ios::out);
        for(int i=0;i<klienciF.size();i++)
        {
        dane << klienciF[i].nazwa_firmy<<"\n";
        dane << klienciF[i].nip<<"\n";
        dane << klienciF[i].miejscowosc<<"\n";
        dane << klienciF[i].login<<"\n";
        dane << klienciF[i].haslo<<"\n";
        dane << klienciF[i].srodki<<"\n";
        dane << klienciF[i].rachunekVAT<<"\n";
        dane << klienciF[i].nr_k<<"\n";
        }
    dane.close();
    }

int main()
{
	int n = 1;
	admin administrator; // login: admin, haslo: admin
	KontoPrywatne klientP;
	vector <KontoPrywatne> klienciP;
	KontoFirmowe klientF;
	vector<KontoFirmowe> klienciF;


    fstream plik;
    plik.open("dane.txt", ios::in);
    if(plik.good())
    klientP.odczytpliku(klientP, klienciP); //jeœli plik nie istnieje, idziemy do menu
    plik.close();
	//system ("cls");
	fstream plikf;
    plikf.open("danef.txt", ios::in);
    if(plikf.good())
        klientF.odczytplikuf(klientF, klienciF); //jeœli plik nie istnieje, idziemy do menu
    plikf.close();
	while (n != 0)
	{
	    system("cls");
		cout << "Witaj w banku Grupy nr.6\n";
		cout << "Co chcesz zrobic?\n1.Zaloguj sie\n2.Stworz nowe konto\n3.Administrator\n0.Zapisz i wyjdz\nWybor:";
        while (!(cin >> n ))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }
		switch (n) {
            case 1:
                system("cls");
                int w;
                cout<<"1.Konto prywatne\n2.Konto firmowe\n";
                while (!(cin >> w ))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }
                switch(w){
                    case 1:
                        system("cls");
                        klientP.logowanie(klienciP);
                        system("cls");
                        break;
                    case 2:
                        klientF.logowanief(klienciF,klienciP);
                        system("cls");
                        break;
                }
                break;
		case 2:
		    system("cls");
			int f;
			cout << "1.Konto prywatne\n2.Konto firmowe\n";
			while (!(cin >> f ))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }
			system("cls");
			switch (f) {

			case 1:
				klientP.tworzenieKontaPrywatnego();
				klienciP.push_back(klientP);
				system("cls");
				//administrator.raport(klienciP);

				break;
            case 2:
                klientF.tworzenieKontaFirmowego();
                klienciF.push_back(klientF);
                system("cls");
			}
			break;
		case 3:
		    system("cls");
		    cout << "1. Wyswietl liste klientow. \n2. Historia dzialan klientow \n3. Usun konto prywatne\n4. Usun konto firmowe" << endl;
		    int a;
		    cin >> a;
			switch(a)
			{
            case 1:

			    administrator.raport(klienciP,klienciF); getch(); break;
            case 2:
                administrator.wyswietl(); break;
            case 3:
                {
                    KontoPrywatne::usunP(klienciP);
                    break;
                }
            case 4:
                {
                    KontoFirmowe::usunF(klienciF);
                    break;
                }


			}
	 case 9:

	break;


		}
		zapisp(klienciP,klientP);
		zapisf(klienciF,klientF);
	}
	return 0;
	}

