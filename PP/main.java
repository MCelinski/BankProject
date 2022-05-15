import java.util.*;

//====================================================================================================
//The Free Edition of C++ to Java Converter limits conversion output to 100 lines per file.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-cplus-to-java.html
//====================================================================================================

public class GlobalMembers
{
	public static int n = 1;
	public static fstream dane = new fstream();
	public static Auta samochod = new Auta();
	public static ArrayList<Auta> samochody = new ArrayList<Auta>();

	public static void plik()
	{ //ODCZYT Z PLIKU
		fstream dane = new fstream();
		dane.open("dane.txt",ios.in);
		while (!dane.eof())
		{
//C++ TO JAVA CONVERTER WARNING: The right shift operator was not replaced by Java's logical right shift operator since the left operand was not confirmed to be of an unsigned type, but you should review whether the logical right shift operator (>>>) is more appropriate:
			dane >> samochod.marka;
//C++ TO JAVA CONVERTER WARNING: The right shift operator was not replaced by Java's logical right shift operator since the left operand was not confirmed to be of an unsigned type, but you should review whether the logical right shift operator (>>>) is more appropriate:
			dane >> samochod.model;
//C++ TO JAVA CONVERTER WARNING: The right shift operator was not replaced by Java's logical right shift operator since the left operand was not confirmed to be of an unsigned type, but you should review whether the logical right shift operator (>>>) is more appropriate:
			dane >> samochod.poj;
//C++ TO JAVA CONVERTER WARNING: The right shift operator was not replaced by Java's logical right shift operator since the left operand was not confirmed to be of an unsigned type, but you should review whether the logical right shift operator (>>>) is more appropriate:
			dane >> samochod.przebieg;
//C++ TO JAVA CONVERTER WARNING: The right shift operator was not replaced by Java's logical right shift operator since the left operand was not confirmed to be of an unsigned type, but you should review whether the logical right shift operator (>>>) is more appropriate:
			dane >> samochod.rocznik;
//C++ TO JAVA CONVERTER WARNING: The right shift operator was not replaced by Java's logical right shift operator since the left operand was not confirmed to be of an unsigned type, but you should review whether the logical right shift operator (>>>) is more appropriate:
			dane >> samochod.skrzynia;
			samochody.add(samochod);

		}
//C++ TO JAVA CONVERTER TODO TASK: There is no direct equivalent to the STL vector 'erase' method in Java:
			samochody.erase(samochody.end());
		dane.close();
	}

	public static void odczyt()
	{ //ODCZYT Z WEKTORA
			system("cls");
			dane.open("dane.txt", ios.out);
			System.out.print("Marka Model Poj Przebieg rocznik typ skrzyni \n");
			for (int i = 0;i < samochody.size();i++)
			{
						System.out.print("\n");
						System.out.print(samochody.get(i).marka);
						System.out.print(" ");
						System.out.print(samochody.get(i).model);
						System.out.print(" ");
						System.out.print(samochody.get(i).poj);
						System.out.print(" ");
						System.out.print(samochody.get(i).przebieg);
						System.out.print(" ");
						System.out.print(samochody.get(i).rocznik);
						System.out.print(" ");
						System.out.print(samochody.get(i).skrzynia);
						System.out.print(" ");
			}
			dane.close();
			getch();
			system("cls");
			return;
	}

	public static void odczytw()
	{ //ODCZYT WARUNKOWY Z WEKTORA
			int x;
			float z;
			system("cls");
			System.out.print("Filtruj wedlug\n1.Pojemnosci\n2.Przebiegu\n");
			x = Integer.parseInt(ConsoleInput.readToWhiteSpace(true));
			switch (x)
			{
				case 1:
					System.out.print("Wyswietl \n1.Wieksze od x \n2.Mniejsze od x\n");
					x = Integer.parseInt(ConsoleInput.readToWhiteSpace(true));
					 if (x == 1)
					 {
					 System.out.print("Podaj x ");
					 z = Float.parseFloat(ConsoleInput.readToWhiteSpace(true));
					 for (int i = 0;i < samochody.size();i++)
					 {
						if (samochody.get(i).poj > z)
						{
						System.out.print("\n");
						System.out.print(samochody.get(i).marka);
						System.out.print(" ");
						System.out.print(samochody.get(i).model);
						System.out.print(" ");
						System.out.print(samochody.get(i).poj);
						System.out.print(" ");
						System.out.print(samochody.get(i).przebieg);
						System.out.print(" ");
						System.out.print(samochody.get(i).rocznik);
						System.out.print(" ");
						System.out.print(samochody.get(i).skrzynia);
						System.out.print(" ");
						}
					 }
					 }

					 else
					 {

					 System.out.print("Podaj x ");
					 z = Float.parseFloat(ConsoleInput.readToWhiteSpace(true));
					 for (int i = 0;i < samochody.size();i++)
					 {
						if (samochody.get(i).poj < z)
						{
						System.out.print("\n");
						System.out.print(samochody.get(i).marka);
						System.out.print(" ");
						System.out.print(samochody.get(i).model);
						System.out.print(" ");
						System.out.print(samochody.get(i).poj);
						System.out.print(" ");
						System.out.print(samochody.get(i).przebieg);
						System.out.print(" ");
						System.out.print(samochody.get(i).rocznik);
						System.out.print(" ");
						System.out.print(samochody.get(i).skrzynia);
						System.out.print(" ");
						}
					 }
					 }
					break;
				case 2:
					System.out.print("Wyswietl \n1.Wieksze od x \n2.Mniejsze od x\n");
					x = Integer.parseInt(ConsoleInput.readToWhiteSpace(true));
					 if (x == 1)
					 {
					 System.out.print("Podaj x ");
					 x = Integer.parseInt(ConsoleInput.readToWhiteSpace(true));
					 for (int i = 0;i < samochody.size();i++)
					 {
						if (samochody.get(i).przebieg > x)
						{
						System.out.print("\n");
						System.out.print(samochody.get(i).marka);

//====================================================================================================
//End of the allowed output for the Free Edition of C++ to Java Converter.

//To purchase the Premium Edition, visit our website:
//https://www.tangiblesoftwaresolutions.com/order/order-cplus-to-java.html
//====================================================================================================
