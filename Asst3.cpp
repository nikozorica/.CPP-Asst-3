#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
/*
Nikola Zorica
This project will allow a user to list houses for sale.
it will then print all of the contents to a file for reference
*/
int main()
{
	//housekeeping
	const int SIZE = 50;
	int length, ctr, lowPrice = 0;
	double avgHomePrice, totalHomePrice = 0, lowestPrice, homePrice[SIZE];
	string homeAddress[SIZE];
	ofstream fout("homes.fil");
	if (!fout.is_open())
	{
		cout << "your file did not open";
		system("pause");
		exit(666);
	}
	fout << setprecision(2) << fixed;
	//processing
	for (length = 0; length < SIZE; length++)
	{
		cout << "Enter the address: (or ^Z to end) ";
		getline(cin, homeAddress[length]);
		
		if (cin.eof())
			break;

		cout << "Enter asking price: ";
		cin >> homePrice[length];
		
		while (homePrice[length] < 0.0 || homePrice[length] > 1000000.0 || cin.fail())
		{
			cin.clear();
			cin.ignore(80, '\n');
			cout << "The Price Must Be Between 0 and 1000000";
			cin >> homePrice[length];
		}
		totalHomePrice += homePrice[length];
		if (length == 0)
			lowestPrice = homePrice[length];
		if (homePrice[length] < lowestPrice)
		{
			lowPrice = length;
			lowestPrice = homePrice[length];
		}
		cin.clear();
		cin.ignore(80, '\n');
	}
	//output
	if (length > 0)
	{
		fout << setw(20) << right << "Kingston Realty" << endl;
		fout << left << setw(20) << "Address" << setw(15) << "Price" << endl;
		avgHomePrice = totalHomePrice / length;
		for (ctr = 0; ctr < length; ctr++)
		{
			fout << left << setw(20) << homeAddress[ctr] << right << setw(15) << homePrice[ctr];
			if (homePrice[ctr] < avgHomePrice)
			{
				fout << right << setw(30) << "*****Below Average*****";
			}
			fout << endl << endl;
		}
		fout << "total number of houses listed = " << length << endl;
		fout << left << setw(20) << "Average price" << right << setw(15) << avgHomePrice << endl;
		fout << "Lowest Price is at " << homeAddress[lowPrice] << endl;
	}
	else
	{
		fout << "File was ended by user" << endl;
	}
	system("type homes.fil");
	system("pause");
	/*
	Enter the address: 1500 King
	Enter asking price: 30000
	Enter the address: 300 Princess
	Enter asking price: 39990
	Enter the address: 400 Portsmouth
	Enter asking price: 28888
	Enter the address: 500 Pine
	Enter asking price: 48880
	Enter the address: ^Z
		 Kingston Realty
	Address             Price
	1500 King                  30000.00       *****Below Average*****

	300 Princess               39990.00

	400 Portsmouth             28888.00       *****Below Average*****

	500 Pine                   48880.00

	total number of houses listed = 4
	Average price              36939.50
	Lowest Price is at 400 Portsmouth
	Press any key to continue . . .
	*/
}
