#include <iostream>
#include <string>
#include <conio.h>
#include<stdio.h>
#include <cstdlib>
#include <iomanip>  
using namespace std;




struct studenci
{
	string nazwisko;
	string imie;
	string nrindeksu;
	string kierunek;
	int rok;
	string liczbaIQ;
	int waga;
};
main ()

{
cout<<"****************************** Michal Celinski *********************************";	
int n =1;
int waga;		
studenci student[n];
cout << "Wprowadz dane.\n";
	
	 for( int licz = 0; licz < n; licz++ ) 
	 {
        cout << "Podaj nazwisko: ";
        cin >> student[ licz ].nazwisko;
        cout << "Podaj imie: ";
        cin >> student[ licz ].imie;
        cout << "Podaj nr inedksu: ";
        cin >> student[ licz ].nrindeksu;
        cout << "Podaj kierunek: ";
        cin >> student[ licz ].kierunek; 
		cout << "Podaj rok: ";
        cin >> student[ licz ].rok;
        cout << "Podaj liczbe IQ: ";
        cin >> student[ licz ].liczbaIQ;
	   cout << "Podaj  wage: ";
	   
	   cin >> student[ licz ].waga;
	  
	 }
system("cls");	
	for( int licz = 0; licz < n; licz++ ) 
	{
        cout << "student: " << licz + 1<<endl
        << "nazwisko: " << student[ licz ].nazwisko<<endl
        << "imie: " << student[ licz ].imie<<endl
         << "nrindeksu: " << student[ licz ].nrindeksu<<endl
          << "kierunek: " << student[ licz ].kierunek<<endl
           << "rok: " << student[ licz ].rok<<endl 
		   << "IQ: " << student[ licz ].liczbaIQ <<endl;
		   if(student[ licz ].waga>70) cout<<"grubas";
		   else
		   cout<< "waga: " << student[ licz ].waga << endl;
    }
}