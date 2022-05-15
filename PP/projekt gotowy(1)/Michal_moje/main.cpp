#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <conio.h>


using namespace std;
class Auta{     //KLASA SAMOCHODU
    public:

    string marka;
    string model;
    int rocznik;
    string skrzynia;
    float poj;
    int przebieg;


public:
    void zapis(){    // ZAPIS DO WEKTORA
        system( "cls" );
        fstream dane;
        dane.open("dane.txt",ios::ate | ios::in);

        cout << " Podaj marke: ";
        cin >> marka;
        dane  << marka << endl;

        cout << " Podaj model: ";
        cin >> model;
        dane  << model << endl;

        cout << " Podaj pojemnosc:";
        cin >> poj;
        dane  << poj << endl ;

        cout << " Podaj przebieg:";
        cin >> przebieg;
        dane  << przebieg << endl;


        cout<<" Podaj rocznik:";
        cin>>rocznik;
        dane<<rocznik<<endl;

        cout << " Podaj rodzaj skrzyni biegow:";
        cin >> skrzynia;
        dane  << skrzynia << endl;

    dane.close();
    }
};
int n=1;
fstream dane;
Auta samochod;
vector<Auta> samochody;

void plik(){ //ODCZYT Z PLIKU
    fstream dane;
    dane.open("dane.txt",ios::in);
    while(!dane.eof())
    {
        dane >> samochod.marka ;
        dane >> samochod.model ;
        dane >> samochod.poj  ;
        dane >> samochod.przebieg ;
        dane >> samochod.rocznik;
        dane >> samochod.skrzynia;
        samochody.push_back(samochod);

    }
        samochody.erase(samochody.end());
    dane.close();
    }

void odczyt(){  //ODCZYT Z WEKTORA
        system( "cls" );
        dane.open("dane.txt", ios::out);
        cout<<"Marka Model Poj Przebieg rocznik typ skrzyni \n";
        for(int i=0;i<samochody.size();i++)
        {
                    cout << endl;
                    cout << samochody[i].marka << " ";
                    cout << samochody[i].model << " ";
                    cout << samochody[i].poj << " ";
                    cout << samochody[i].przebieg << " ";
                    cout << samochody[i].rocznik << " ";
                    cout << samochody[i].skrzynia << " ";
        }
        dane.close();
        getch();
        system( "cls" );
        return;
        }

void odczytw(){  //ODCZYT WARUNKOWY Z WEKTORA
        int x;
        float z;
        system( "cls" );
        cout << "Filtruj wedlug\n1.Pojemnosci\n2.Przebiegu\n";
        cin >>x;
        switch(x){
            case 1:
                cout << "Wyswietl \n1.Wieksze od x \n2.Mniejsze od x\n";
                cin >>x;
                 if(x==1)
                 {
                 cout << "Podaj x ";
                 cin >> z;
                 for(int i=0;i<samochody.size();i++)
                 {
                    if(samochody[i].poj > z)
                    {
                    cout << endl;
                    cout << samochody[i].marka << " ";
                    cout << samochody[i].model << " ";
                    cout << samochody[i].poj << " ";
                    cout << samochody[i].przebieg << " ";
                    cout << samochody[i].rocznik << " ";
                    cout << samochody[i].skrzynia << " ";
                    }
                 }
                 }

                 else
                 {

                 cout << "Podaj x ";
                 cin >> z;
                 for(int i=0;i<samochody.size();i++)
                 {
                    if(samochody[i].poj < z)
                    {
                    cout << endl;
                    cout << samochody[i].marka << " ";
                    cout << samochody[i].model << " ";
                    cout << samochody[i].poj << " ";
                    cout << samochody[i].przebieg << " ";
                    cout << samochody[i].rocznik << " ";
                    cout << samochody[i].skrzynia << " ";
                    }
                 }
                 }
                break;
            case 2:
                cout << "Wyswietl \n1.Wieksze od x \n2.Mniejsze od x\n";
                cin >>x;
                 if(x==1)
                 {
                 cout << "Podaj x ";
                 cin >> x;
                 for(int i=0;i<samochody.size();i++)
                 {
                    if(samochody[i].przebieg > x)
                    {
                    cout << endl;
                    cout << samochody[i].marka << " ";
                    cout << samochody[i].model << " ";
                    cout << samochody[i].poj << " ";
                    cout << samochody[i].przebieg << " ";
                    cout << samochody[i].rocznik << " ";
                    cout << samochody[i].skrzynia << " ";

                    }
                 }
                 }

                 else
                 {
                 cout << "Podaj x ";
                 cin >> x;
                 for(int i=0;i<samochody.size();i++)
                 {
                    if(samochody[i].przebieg < x)
                    {
                    cout << samochody[i].marka << " ";
                    cout << samochody[i].model << endl;
                    cout << samochody[i].poj << endl;
                    cout << samochody[i].przebieg << endl;
                    cout << samochody[i].rocznik << " ";
                    cout << samochody[i].skrzynia << " ";
                    }
                 }
                 }

                break;
        }

        dane.close();
        getch();
        system( "cls" );
        return;
        }

void odczytk(){     //ODCZYT KONKRETNEGO SAMOCHODU
    int x;
    cout << "Ktory z kolei samochod chcesz wyswietlic?";
    cin >> x;
    x--;
    cout << endl;
    cout << samochody[x].marka << " ";
    cout << samochody[x].model << " ";
    cout << samochody[x].poj << " ";
    cout << samochody[x].przebieg << " ";
    cout << samochody[x].rocznik << " ";
    cout << samochody[x].skrzynia << " ";
    return;
}

void zapis(){   //ZAPIS DO PLIKU (RESET PLIKU)

        fstream dane;
        dane.open("dane.txt",ios::out);
        dane.clear();
        dane.close();
        dane.open("dane.txt",ios::out);
        for(int i=0;i<samochody.size();i++)
        {
        dane  << samochody[i].marka << " ";
        dane  << samochody[i].model << " ";
        dane  << samochody[i].poj << " " ;
        dane  << samochody[i].przebieg << " ";
        dane  << samochody[i].rocznik << " ";
        dane  << samochody[i].skrzynia << " ";
        dane << endl;
        }
    dane.close();
    }


void sortowanie(){
    int y;
        system( "cls" );
        cout << "sortuj wedlug: \n1.Pojemnosci\n2.Przebiegu\n";
        cin >>y;
        switch(y){
            case 1:{
                cout << "Posortowane wedlug pojemnosci ";

    for( int i = 0; i < samochody.size(); i++ )
    {
        for( int j = 0; j < samochody.size() - 1; j++ )
        {
            if( samochody[j].poj > samochody[ j + 1 ].poj )
                 swap(samochody[j],samochody[ j + 1 ] );

        }
    }
                  break;
                  }


            case 2:{
                cout << "Posorotwane wedlug przebiegu";

      for( int i = 0; i < samochody.size(); i++ )
    {
        for( int j = 0; j < samochody.size() - 1; j++ )
        {
            if( samochody[j].przebieg > samochody[ j + 1 ].przebieg )
                 swap(samochody[j],samochody[ j + 1 ]);

        }
    }
            }
            break;
        }
}
int main()
{
    int z;
   cout << "Czy chcesz korzystac z istniejacego pliku?\n1.Tak\n2.Nie (wybranie tej opcji spowoduje usuniecie istniejacej bazy)\n";
    cin >> z;
    if(z==1)
    plik();
    system("cls");
    while (n!=0)
    {
    cout << "Co chcesz zrobic?\n1.Dodaj samochod\n2.Pokaz liste samochodow\n"
    "3.Odczytaj warunkowo\n4.Wyswietl konkretny samochod\n6.Usun konkretny samochod\n7.Posortuj Samochody po parametrze\n0. nic\n";
    cin >> n;
    switch(n){  //MENU G£OWNE
        case 1:
            samochod.zapis();
            samochody.push_back(samochod);
            system( "cls" );
            break;
        case 2:

            odczyt();

            break;
        case 3:
            odczytw();
            system( "cls" );
            break;
        case 4:
            odczytk();
            getch();
            system("cls");
            break;
        case 6:
            system("cls");
            int x;
            cout << "Podaj ktore z kolei auto chcesz usunac";
            cin >> x;
            samochody.erase(samochody.begin()+x);
            zapis();
            break;
        case 7:
            sortowanie();
            break;

            }

    }

    zapis();

    return 0;
}
