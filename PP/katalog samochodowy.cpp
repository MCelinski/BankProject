#include <iostream>
#include<fstream>
using namespace std;


//class samochody

main()
{
cout<<"katalog Samochodowy"<<endl;
cout<<"1-Otwórz liste samochodow"<<endl;
cout<<"2-dodaj nowy samochod"<<endl;

	
		
int x;	
cin>>x;	
switch (x)
{
	case 1:
		ifstream plo;
		plo.open("auta.txt");
		while (!plo.eof())
  		{
   	  	  cout<<plo;
        }
break;
        plo.close();
	
}
}