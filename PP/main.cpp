#include <iostream>
#include <string>
#include<conio.h>
#include<stdio.h>
#include <cstdlib>
#include <iomanip>  
using namespace std;
int i=0;
int tab[100];
int j;
int t=0;
int mini;
int maks;

void dec_to_bin(int liczba)
{
	int i=0;
	tab[31];

	while(liczba)
	{
		tab[i++]=liczba%2;
		liczba/=2;
	}

	for(int j=i-1;j>=0;j--)
		cout << tab[j];

}

void dec_to_oct(int liczba)
{
    int i=0,tab[31];

    while(liczba)
    {
        tab[i++]=liczba%8;
        liczba/=8;
    }

    for(int j=i-1; j>=0; j--)
        cout << tab[j];

}
string dec2hex (int liczba)
{
    char heksadecymalna[255];
    itoa(liczba, heksadecymalna, 16);

    return (string)heksadecymalna;
}
int main()
{
	
do 
{
	system("cls");
	cout<<"****************************** Michal Celinski *********************************";


    
     cout<<"Podaj minimum: ";
 while (!(cin >> mini) || (mini<=0))
          {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear(); 
                cin.sync(); 
		  }
    cout<<"Podaj maksimum: ";
    while (!(cin >> maks) || (maks<=mini))
          {
                cout << " " << "Zla wartosc podaj jeszcze raz " << endl;
                cin.clear(); 
                cin.sync(); 
		  }
    
   
cout<<"---------------------------------------"<<endl;
cout<<"|DEC| | BIN  |  | OCT |  |HDEC|  |CHAR|"<<endl;
cout<<"---------------------------------------"<<endl;
    for(int i=mini;i<maks+1;i++)
    {
    
      cout<<"|"<<dec<<i<<" |";
      cout<<" |";
      dec_to_bin(i);
      cout<<"| ";
      cout<<" | ";
      dec_to_oct(i);
       cout<<"  | ";
      cout << " | "<<hex<<uppercase<<i<<" |";

      cout<<"  | "<<""<<(char)i<<"  |";
      cout<<endl;

    }
getch();
system("cls");


cout<<" Dziekuje za skorzystanie z programu. Jesli chcesz powtorzyc kliknij enter"<<endl;



//return 0;
}
while (getch()!=0);
}
