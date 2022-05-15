public class Auta
{ //KLASA SAMOCHODU

	public String marka;
	public String model;
	public int rocznik;
	public String skrzynia;
	public float poj;
	public int przebieg;


	public final void zapis()
	{ // ZAPIS DO WEKTORA
		system("cls");
		fstream dane = new fstream();
		dane.open("dane.txt",ios.ate | ios.in);

		System.out.print(" Podaj marke: ");
		marka = ConsoleInput.readToWhiteSpace(true);
		dane << marka << "\n";

		System.out.print(" Podaj model: ");
		model = ConsoleInput.readToWhiteSpace(true);
		dane << model << "\n";

		System.out.print(" Podaj pojemnosc:");
		poj = Float.parseFloat(ConsoleInput.readToWhiteSpace(true));
		dane << poj << "\n";

		System.out.print(" Podaj przebieg:");
		przebieg = Integer.parseInt(ConsoleInput.readToWhiteSpace(true));
		dane << przebieg << "\n";


		System.out.print(" Podaj rocznik:");
		rocznik = Integer.parseInt(ConsoleInput.readToWhiteSpace(true));
		dane << rocznik << "\n";

		System.out.print(" Podaj rodzaj skrzyni biegow:");
		skrzynia = ConsoleInput.readToWhiteSpace(true);
		dane << skrzynia << "\n";

	dane.close();
	}
}