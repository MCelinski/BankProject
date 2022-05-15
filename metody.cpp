#include <iostream>
#include "klasy.h"
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;

// gettery

long KontoPrywatne::g_nr_k(){ return nr_k;}
float KontoPrywatne::g_srodki() { return srodki; }
string KontoPrywatne::g_imie() { return imie; }
string KontoPrywatne::g_nazwisko() { return nazwisko; }
string KontoPrywatne::g_miejscowosc() { return miejscowosc; }
long KontoPrywatne::g_pesel() { return pesel; }
string KontoPrywatne::g_login() { return login; }
string KontoPrywatne::g_haslo() { return haslo; }

long KontoFirmowe::g_nr_k(){ return nr_k;}
float KontoFirmowe::g_srodki() { return srodki; }
string KontoFirmowe::g_nazwa_firmy() { return nazwa_firmy; }
string KontoFirmowe::g_nip() { return nip; }
string KontoFirmowe::g_miejscowosc() { return miejscowosc; }
float KontoFirmowe::g_rachunekVAT() {return rachunekVAT;}
string KontoFirmowe::g_login() { return login; }
string KontoFirmowe::g_haslo() { return haslo; }

string uzytkownik::g_login() { return login; };
string uzytkownik::g_haslo() { return haslo; };

// konstruktory

uzytkownik::uzytkownik(string _login, string _haslo) :
login(_login), haslo(_haslo) {};

admin::admin(string _login, string _haslo) : uzytkownik(_login, _haslo) {};

klient::klient(string _login, string _haslo, float _srodki, long _nr_k) :
	uzytkownik(_login, _haslo), srodki(_srodki), nr_k(_nr_k)
{};

KontoPrywatne::KontoPrywatne(string _login, string _haslo, float _srodki, long _nr_k, long _pesel, string _imie, string _nazwisko, string _miejscowosc) :
	klient(_login, _haslo, _srodki, _nr_k), pesel(_pesel), imie(_imie), nazwisko(_nazwisko), miejscowosc(_miejscowosc)
{};
KontoFirmowe::KontoFirmowe(string _login, string _haslo, float _srodki, long _nr_k, string _nip, string _nazwa_firmy, string _miejscowosc, float _rachunekVAT) :
	klient(_login, _haslo, _srodki, _nr_k), nip(_nip), nazwa_firmy(_nazwa_firmy), miejscowosc(_miejscowosc), rachunekVAT(_rachunekVAT)
{};

// destruktory
uzytkownik::~uzytkownik() { }

admin::~admin() {  }

klient::~klient() { }

KontoPrywatne::~KontoPrywatne() { }

KontoFirmowe::~KontoFirmowe() { }

// metody

void  KontoPrywatne::tworzenieKontaPrywatnego(){
	fstream dane;
	dane.open("dane.txt", ios::out | ios::app);

	cout << " Podaj imie: ";
	while (!(cin >> imie ))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }
	dane << imie << endl;

	cout << " Podaj nazwisko: ";
	while (!(cin >> nazwisko ))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }
	dane << nazwisko << endl;

	cout << " Podaj miejscowosc:";
	while (!(cin >> miejscowosc ))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }
	dane << miejscowosc << endl;

	cout << " Podaj pesel:";
	while (!(cin >> pesel ))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }
	dane << pesel << endl;

	cout << " Podaj login:";
	while (!(cin >> login ))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }
	dane << login << endl;

    cout<<" Podaj haslo:";
    while (!(cin >> haslo ))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }
	dane << haslo << endl;
	dane << srodki << endl;

	srand(time(NULL));
	nr_k = (rand() % 99999999) + 10000001;
	dane << nr_k << endl;
	dane.close();
};

void  KontoFirmowe::tworzenieKontaFirmowego(){
	fstream danef;
	danef.open("danef.txt", ios::out | ios::app);

	cout<<" Podaj nazwe firmy: ";
	while (!(cin >> nazwa_firmy ))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }
	danef<<nazwa_firmy<<endl;

	cout<<" Podaj nip: ";
	while (!(cin >> nip ))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }
	danef<<nip<<endl;

	cout<<" Podaj miejscowosc:";
	while (!(cin >> miejscowosc ))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }
	danef<<miejscowosc << endl;

	cout<<" Podaj login:";
        while (!(cin >> login ))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }
	danef<<login<< endl;

	cout<<" Podaj haslo:";
	while (!(cin >> haslo ))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }

	danef<<haslo<<endl;

	danef<<srodki<<endl;

	danef<<rachunekVAT<<endl;

	srand(time(NULL));
	nr_k=(rand()%99999999)+10000001;
	danef<<nr_k<<endl;
	danef.close();
};


void  admin::raport(vector <KontoPrywatne>& klienciP,vector <KontoFirmowe>& klienciF) {
    cout<<"Konta Prywatne: \n";
	for (int i = 0; i < klienciP.size(); i++)
	{
		cout <<"Imie: "<< klienciP[i].g_imie() << ", ";
		cout <<"Nazwisko: "<< klienciP[i].g_nazwisko() << ", ";
		cout <<"Miejscowosc: "<< klienciP[i].g_miejscowosc() << ", ";
		cout <<"Pesel: "<< klienciP[i].g_pesel() << ", ";
		cout <<"Numer konta: "<< klienciP[i].g_nr_k() << "\n";

	}
    cout<<"\nKonta Firmowe: \n";
	for (int i = 0; i < klienciF.size(); i++)
	{
		cout <<"Nazwa firmy: "<< klienciF[i].g_nazwa_firmy() << ", ";
		cout <<"NIP: "<< klienciF[i].g_nip() << ", ";
		cout <<"Miejscowosc: "<< klienciF[i].g_miejscowosc() << ", ";
		cout <<"Numer konta: "<< klienciF[i].g_nr_k() << "\n";

	}

};


void KontoPrywatne::odczytpliku(KontoPrywatne &klientP, vector<KontoPrywatne> &klienciP){
    fstream dane;
    dane.open("dane.txt");
    while(!dane.eof())
    {
        dane >> klientP.imie ;
        dane >> klientP.nazwisko ;
        dane >> klientP.miejscowosc  ;
        dane >> klientP.pesel ;
        dane >> klientP.login;
        dane >> klientP.haslo;
        dane >> klientP.srodki;
        dane >> klientP.nr_k;
        klienciP.push_back(klientP);

    }
        klienciP.erase(klienciP.end());
        dane.close();
    };


void KontoFirmowe::odczytplikuf(KontoFirmowe &klientF, vector<KontoFirmowe> &klienciF){

    fstream danef;
    danef.open("danef.txt");
    while(!danef.eof())
    {
        danef>>klientF.nazwa_firmy ;
        danef>>klientF.nip ;
        danef>>klientF.miejscowosc  ;
        danef>>klientF.login;
        danef>>klientF.haslo;
        danef>>klientF.srodki;
        danef>>klientF.rachunekVAT;
        danef>>klientF.nr_k;
        klienciF.push_back(klientF);
    }
        klienciF.erase(klienciF.end());
        danef.close();
    };


void klient::wplata(vector <KontoPrywatne> &klienciP, int i) {
system("cls");
cout<<"Podaj kwote do wplaty: ";
float x;
while (!(cin >> x)|| (x<=0))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }
klienciP[i].srodki+=x;
	cout<<"Wplaciles: "<<x<<"zl"<<endl;
	cout<<"Twoje srodki: "<<klienciP[i].srodki<<"zl";
		getch();

		time_t czas;  //zapis do historii
    		time( & czas );
    		char * data = ctime( & czas );
		fstream historia;
		historia.open("historia.txt", ios::out | ios::app);
		historia << klienciP[i].g_nr_k() << " " << klienciP[i].g_imie() << " " << klienciP[i].g_nazwisko() << " Dnia: " << data;
		historia << "Wplacono " << x << "zl" <<endl;
		historia.close();


};


void klient::wplataf(vector <KontoFirmowe> &klienciF, int i) {
cout<<"Podaj kwote do wplaty: ";
float x;
while (!(cin >> x)|| (x<=0))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }
klienciF[i].srodki+=x;
cout<<"Wplaciles: "<<x<<"zl"<<endl;
cout<<"Twoje srodki: "<<klienciF[i].srodki<<"zl";
getch();
		time_t czas; //zapis do historii
		time( & czas );
		char * data = ctime( & czas );
		fstream historia;
		historia.open("historia.txt", ios::out | ios::app);
		historia << klienciF[i].g_nr_k() << " " << klienciF[i].g_nazwa_firmy() << " " << " Dnia: " << data;
		historia << "Wplacono " << x << "zl" <<endl;
		historia.close();
};


void klient::wyplata(vector <KontoPrywatne> &klienciP, int i) {
system("cls");
cout<<"Podaj kwote do wyplaty: ";
float x;

while (!(cin >> x) || x<0 || x>klienciP[i].srodki)
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }

cout<<"Wyplaciles: "<<x<< " zl"<<endl;
klienciP[i].srodki-=x;
cout<<"Na koncie pozostalo: " <<klienciP[i].srodki;

		time_t czas; //zapis do historii
		time( & czas );
		char * data = ctime( & czas );
		fstream historia;
		historia.open("historia.txt", ios::out | ios::app);
		historia << klienciP[i].g_nr_k() << " " << klienciP[i].g_imie() << " " << klienciP[i].g_nazwisko() << " Dnia: " << data;
		historia << "Wyplacono " << x << "zl" <<endl;
		historia.close();
};


void klient::wyplataf(vector <KontoFirmowe> &klienciF, int i) {
system("cls");
cout<<"Podaj kwote do wyplaty: ";
float x;
while (!(cin >> x) || x<0 || x>klienciF[i].srodki)
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }

cout<<"Wyplaciles: "<<x<< " zl"<<endl;
klienciF[i].srodki-=x;
cout<<"Na koncie pozostalo: " <<klienciF[i].srodki<<" zl";

		time_t czas; //zapis do historii
		time( & czas );
		char * data = ctime( & czas );
		fstream historia;
		historia.open("historia.txt", ios::out | ios::app);
		historia << klienciF[i].g_nr_k() << " " << klienciF[i].g_nazwa_firmy() << " " <<  " Dnia: " << data;
		historia << "Wyplacono " << x << "zl" <<endl;
		historia.close();
};


void klient::przelew(vector <KontoPrywatne> &klienciP, int i) {
system("cls");
long y;
float x;
cout<<"Podaj na jaki nr konta chcesz zrobic przelew: ";
while (!(cin >> y ))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }

cout<<"Podaj kwote jaka chcesz przelac: ";
while (!(cin >> x) || x<0 || x>klienciP[i].srodki)
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }

for (int p = 0; p < klienciP.size(); p++)
	{
    		if (klienciP[p].nr_k == y)
       			{
      				 klienciP[p].srodki += x;
       				 klienciP[i].srodki-=x;

       				 time_t czas;
        			 time( & czas );
        			 char * data = ctime( & czas );
        			 fstream historia;
       				 historia.open("historia.txt", ios::out | ios::app);
       				 historia << klienciP[i].g_nr_k() << " " << klienciP[i].g_imie() << " " << klienciP[i].g_nazwisko() << " Dnia: " << data;
        			 historia << "Przelano " << x << "zl na konto " << klienciP[p].g_nr_k() << " " << klienciP[p].g_imie() << " " << klienciP[p].g_nazwisko() << endl;
        			 historia << klienciP[p].g_nr_k() << " " << klienciP[p].g_imie() << " " << klienciP[p].g_nazwisko() << " Dnia: " << data;
        			 historia << "Przelano na twoje konto " << x << "zl od " << klienciP[i].g_nr_k() << " " << klienciP[i].g_imie() << " " << klienciP[i].g_nazwisko() << endl;
       				 historia.close();

       			}
cout<<"\nPrzelales: "<<x<<"zl na "<<"nr konta"<<y;
getch();

}
};


void klient::przelewf(vector <KontoPrywatne> &klienciP, vector<KontoFirmowe> &klienciF, int i) {
system("cls");
long y;
float x;
cout<<"Podaj na jaki nr konta chcesz zrobic przelew:  \n";
while (!(cin >> y ))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            };

cout<<"Podaj kwote jaka chcesz przelac: \n";
while (!(cin >> x) || x<0 || x>klienciF[i].srodki)
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }

    for (int p = 0; p < klienciP.size(); p++){
    if (klienciP[p].nr_k == y)
       {
       klienciP[p].srodki += x;
       klienciF[i].srodki-=x;
       		time_t czas;
       	        time( & czas );
                char * data = ctime( & czas );
                fstream historia;
        	historia.open("historia.txt", ios::out | ios::app);
        	historia << klienciF[i].g_nr_k() << " " << klienciF[i].g_nazwa_firmy() << " "<< " Dnia: " << data;
        	historia << "Przelano " << x << "zl na konto " << klienciP[p].g_nr_k() << " " << klienciP[p].g_imie() << " " << klienciP[p].g_nazwisko() << endl;
        	historia << klienciP[p].g_nr_k() << " " << klienciP[p].g_imie() << " " << klienciP[p].g_nazwisko() << " Dnia: " << data;
        	historia << "Przelano na twoje konto " << x << "zl od " << klienciF[i].g_nr_k() << " " << klienciF[i].g_nazwa_firmy() << " " <<endl;
       	        historia.close();
       }
       cout<<"Przelales: "<<x<<"zl "<<"na konto: "<<y;
    }


};


void KontoFirmowe::przelewff(vector<KontoFirmowe> &klienciF, int i){//przelew z firmowego na firmowe
system("cls");
long y;
float x;
cout<<"Podaj na jaki nr konta chcesz zrobic przelew:  \n";
while (!(cin >> y ))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            };

cout<<"Podaj kwote jaka chcesz przelac: \n";
while (!(cin >> x) || x<0 || x>klienciF[i].srodki)
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }

for (int p = 0; p < klienciF.size(); p++){
    if (klienciF[p].g_nr_k() == y)
       {
       klienciF[p].rachunekVAT+= ((0.23)*x);
       klienciF[p].srodki = klienciF[p].srodki + (0.77*x);
       klienciF[i].srodki-=x;
       cout<<"Przelales: "<<x<<"zl "<<"na konto: "<<y<<endl;
       cout<<"Na rachunek VAT przelano: "<<0.23*x<<"zl";
       time_t czas;
        time( & czas );
        char * data = ctime( & czas );
        fstream historia;
        historia.open("historia.txt", ios::out | ios::app);
        historia << klienciF[i].g_nr_k() << " " << klienciF[i].g_nazwa_firmy() << " "<< " Dnia: " << data;
        historia << "Przelano " << x << "zl na konto " << klienciF[p].g_nr_k() << " " << klienciF[p].g_nazwa_firmy() << " "<< endl;
        historia << klienciF[p].g_nr_k() << " " << klienciF[p].g_nazwa_firmy() << " " <<" Dnia: " << data;
        historia << "Przelano na twoje konto " << x << "zl od " << klienciF[i].g_nr_k() << " " << klienciF[i].g_nazwa_firmy() << " " <<endl;
        historia.close();
       }
       cout<<"Przelales: "<<x<<"zl "<<"na konto: "<<y;
       }
    }


void klient::sprawdz_saldo(vector <KontoPrywatne> &klienciP, int i){
                    system("cls");
                    cout<<"Twoje saldo: "<<klienciP[i].srodki;
                           }


void klient::sprawdz_saldof(vector <KontoFirmowe> &klienciF, int i){
                    system("cls");
                    cout<<"Twoje saldo: "<<klienciF[i].srodki;
}


void KontoPrywatne::zmianahaslaP(vector <KontoPrywatne>& KlienciP,int  i){
    system("cls");
cout<<"podaj stare haslo: ";
string w;

 while (!(cin >> w ))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }
if (w!= KlienciP[i].g_haslo() )
    {
        cout<<"Podales zle haslo. Podaj jescze raz\n";
        getch();

        zmianahaslaP(KlienciP,i);
    }
string h;
for (int p = 0; p < KlienciP.size(); p++)
{
if(w==KlienciP[i].g_haslo())
{

  cout<<"podaj nowe haslo: ";
   while (!(cin >> h ))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }
  KlienciP[i].haslo=h;
}

}
}



void KontoFirmowe::zmianahaslaF(vector <KontoFirmowe>& KlienciF,int  i){
    system("cls");
cout<<"podaj stare haslo: ";
string w;

 while (!(cin >> w ))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }
if (w!= KlienciF[i].g_haslo() )
    {
        cout<<"Podales zle haslo. Podaj jescze raz\n";
        getch();

        zmianahaslaF(KlienciF,i);
    }
string h;
for (int p = 0; p < KlienciF.size(); p++)
{
if(w==KlienciF[i].g_haslo())
{

  cout<<"podaj nowe haslo: ";
   while (!(cin >> h ))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }
  KlienciF[i].haslo=h;
}

}
}


void uzytkownik::logowanie(vector <KontoPrywatne>& klienciP) {
	int g = 1;
	system("cls");
	cout << "Podaj login: ";
	while (!(cin >> login))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }
	string pass ="";
   char ch;
   cout << "Podaj haslo: ";
   ch = _getch();
   while(ch != 13){
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   haslo=pass;

	for (int i = 0; i < klienciP.size(); i++)
	{

		if (login == klienciP[i].g_login() && haslo == klienciP[i].g_haslo()) {
        int licznik=i;
			while (g != 0)
			{
			    system ("cls");
				cout << "Co chcesz zrobic?\n1. Wyplac pieniadze \n2 Wplac pieniadze \n3 Zrob przelew \n4 Sprawdz saldo \n5.Historia\n6.Zmien haslo\n0.Wyjscie\nWybor: ";
cin >>g;
				switch (g){

            case 1:
                {
                system("cls");
                klient::wyplata(klienciP,i);
                getch();
                break;
                }
			case 2:
			    {
                system("cls");
                klient::wplata(klienciP,i);
			    break;
			    }
            case 3:
                {
                system("cls");
                klient::przelew(klienciP,i);
                break;
                }
            case 4:
                {
                system("cls");
                klient::sprawdz_saldo(klienciP,i);
                getch();
                break;
                }
            case 5:
                {
                system("cls");
               admin::historia(klienciP,i);
                getch();
                break;
                }
            case 6:
                {
                    KontoPrywatne::zmianahaslaP(klienciP,i);
                    break;
                }


		}
			}
		}
		else if (!(login == klienciP[i].g_login() && haslo == klienciP[i].g_haslo()))
        {
        cout<<"\nPodales zly login lub haslo. Podaj jescze raz\n";
        Sleep(1000);
        logowanie(klienciP);
        }
         //if (login == klienciP[i].g_login() && haslo == klienciP[i].g_haslo()) break;
        }

};


void admin::wyswietl(){
    system("cls");
    cout << "Historia dzialan klientow: " << endl;
    fstream historia;
    historia.open("historia.txt", ios::in);
    string linia;
    int nr;
    if(historia.good())
    {
        while(getline(historia, linia))
       {
         cout << linia << endl;
         nr++;
       }
    }
    getch();
}


void admin::historia(vector <KontoPrywatne>& klienciP, int i){
    system("cls");
    cout << "Historia twoich dzialan: " << endl;
    fstream historia;
    historia.open("historia.txt", ios::in);
    string linia;
    string skonto;
    long ikonto;
    int nr;
    if(historia.good())
    {
        while(getline(historia, linia))
       {
           for(int j=0; j<8; j++)
           skonto[j]=linia[j];
            ikonto=atol(skonto.c_str());
            if(ikonto==klienciP[i].g_nr_k())
           {
               cout << linia << endl;
               getline(historia, linia);
               cout << linia << endl;
           }
            nr++;
       }
    }
}


void admin::historiaf(vector <KontoFirmowe>& klienciF, int i){
    system("cls");
    cout << "Historia twoich dzialan: " << endl;
    fstream historia;
    historia.open("historia.txt", ios::in);
    string linia;
    string skonto;
    long ikonto;
    int nr;
    if(historia.good())
    {
        while(getline(historia, linia))
       {
           for(int j=0; j<8; j++)
           skonto[j]=linia[j];
            ikonto=atol(skonto.c_str());
            if(ikonto==klienciF[i].g_nr_k())
           {
               cout << linia << endl;
               getline(historia, linia);
               cout << linia << endl;
           }
            nr++;
       }
    }
}


void  KontoPrywatne::usunP(vector <KontoPrywatne>& klienciP){
long w=0;
int x=0;
bool z=0;
cout<<"nr usuwanego konta:";
cin>>w;
for (int i = 0; i < klienciP.size(); i++)
{


    x++;
    if (klienciP[i].g_nr_k()==w)
    {
    klienciP.erase(klienciP.begin()+x);
    z=1;
    }
}
}


void  KontoFirmowe::usunF(vector <KontoFirmowe>& klienciF){
long w=0;
int x=0;
bool z=0;
cout<<"nr usuwanego konta:";
cin>>w;
for (int i = 0; i < klienciF.size(); i++)
{


    x++;
    if (klienciF[i].g_nr_k()==w)
    {
    klienciF.erase(klienciF.begin()+x);
    z=1;
    }
}
}


void uzytkownik::logowanief(vector <KontoFirmowe>& klienciF, vector <KontoPrywatne>& klienciP) {
	int g = 1;
	char ch;
	string pass;
	system("cls");
	cout << "Podaj login: ";
	while (!(cin >> login))
            {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear();
                cin.sync();
            }
            cout<<"Podaj haslo: ";
	ch = _getch();
   while(ch != 13){
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   haslo=pass;
	for (int i = 0; i < klienciF.size(); i++)
	{
		if (login == klienciF[i].g_login() && haslo == klienciF[i].g_haslo()) {
        int licznik=i;
			while (g != 0)
			{
			    system ("cls");
				cout << "Co chcesz zrobic?\n1. Wyplac pieniadze \n2 Wplac pieniadze \n3 Zrob przelew \n4 Sprawdz saldo \n5. Historia\n6.Zmien haslo\n0.Koniec\nWybor:";
				cin >> g;
				switch (g){

            case 1:
                {
                system("cls");
                klient::wyplataf(klienciF,i);
                getch();
                break;
                }
			case 2:
			    {
                system("cls");
                klient::wplataf(klienciF,i);
			    break;
			    }
            case 3:
                {
                system("cls");
                cout<<"1. Przelew na konto prywatne\n2. Przelew na konto firmowe";
                int w;
                cin>>w;
                switch(w){
            case 1:
                { system("cls");
                  klient::przelewf(klienciP,klienciF,i);
                  break;
                }

            case 2:
                {system("cls");
                 KontoFirmowe::przelewff(klienciF,i);
                 break;
                }
                }

                break;
                }
            case 4:
                {
                system("cls");
                klient::sprawdz_saldof(klienciF,i);
                getch();
                break;
                }
            case 5:
                {
                system("cls");
                admin::historiaf(klienciF,i); //  dziala
                getch();
                break;
                }
            case 6:
                {

                KontoFirmowe::zmianahaslaF(klienciF,i);

                }
            case 0:
                {

                break;
                }

		}

			}
        if (login == klienciF[i].g_login() && haslo == klienciF[i].g_haslo()) break;
		}
		else if (!(login == klienciF[i].g_login() && haslo == klienciF[i].g_haslo()))
        {
        cout<<"Podales zly login lub haslo. Podaj jescze raz\n";
        Sleep(1000);
        logowanief(klienciF,klienciP);
        }
         if (login == klienciF[i].g_login() && haslo == klienciF[i].g_haslo()) break;
	}
};
