#include <iostream>
#include <vector>
using namespace std;
class KontoPrywatne;
class KontoFirmowe;

class uzytkownik
{
protected:
	string login;
	string haslo;


public:
	string g_login();
	string g_haslo();
	uzytkownik(string="login", string="haslo");
	~uzytkownik();
	void logowanie(vector <KontoPrywatne>& vec);
	void logowanief(vector <KontoFirmowe>& vec, vector <KontoPrywatne> &x);
};


class klient : public uzytkownik
{
protected:
	float srodki;
	long nr_k;
public:
	klient(string = "--", string = "--", float = 0, long = 0);
	~klient();
	 static void wplata(vector <KontoPrywatne> &x, int i );
	static void wyplata(vector <KontoPrywatne> &x, int i);
	static void przelew(vector <KontoPrywatne> &x, int i);
	static void sprawdz_saldo(vector <KontoPrywatne> &x, int i);
	static void wplataf(vector <KontoFirmowe> &x, int i );
	static void wyplataf(vector <KontoFirmowe> &x, int i);
	static void przelewf(vector <KontoPrywatne> &vec, vector <KontoFirmowe> &x, int i);
	static void sprawdz_saldof(vector <KontoFirmowe> &x, int i);

};

class KontoPrywatne : public klient {
protected:
	long  pesel;
	string imie;
	string nazwisko;
	string miejscowosc;
public:
	KontoPrywatne(string = "--", string = "--", float=0, long=0, long = 0, string = "--", string = "--", string = "--");
	~KontoPrywatne();
	void  tworzenieKontaPrywatnego();
	void odczytpliku(KontoPrywatne& x, vector<KontoPrywatne>& vec);
	string g_imie();
	string g_nazwisko();
	string g_miejscowosc();
	long g_pesel();
	long g_nr_k();
	float g_srodki();
	string g_login();
	string g_haslo();
	friend void zapisp(vector <KontoPrywatne> &klienciP, KontoPrywatne &klientP);
       static void zmianahaslaP(vector <KontoPrywatne>& vec, int i);
       static void usunP (vector <KontoPrywatne>& vec);
};


class KontoFirmowe : public klient
{
protected:
	string nip;
	string nazwa_firmy;
	string miejscowosc;
	float rachunekVAT;
public:
	KontoFirmowe(string = "--", string = "--", float = 0, long = 0, string = "--", string = "--", string = "--", float = 0);
	~KontoFirmowe();
	void  tworzenieKontaFirmowego();
	void odczytplikuf(KontoFirmowe& x, vector<KontoFirmowe>& vec);
	string g_nazwa_firmy();
	string g_miejscowosc();
	string g_nip();
	long g_nr_k();
	float g_srodki();
	float g_rachunekVAT();
	string g_login();
	string g_haslo();
    static void przelewf(vector <KontoPrywatne> &vec, vector <KontoFirmowe> &x, int i);
    static void przelewff(vector <KontoFirmowe> &x, int i);
	friend void zapisf(vector <KontoFirmowe> &klienciF, KontoFirmowe &klientF);
    static void zmianahaslaF(vector <KontoFirmowe>& vec, int i);
    static void usunF (vector <KontoFirmowe>& vec);
};

class admin : public uzytkownik
{
public:
	admin(string = "admin", string = "admin");
	~admin();
	void wyswietl();
	static void historia(vector <KontoPrywatne>& vec, int x);
	void raport(vector <KontoPrywatne>& vec, vector <KontoFirmowe>& x);
	static void historiaf(vector <KontoFirmowe>& vec, int x);

};
