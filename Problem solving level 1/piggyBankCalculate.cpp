#include <iostream>
using namespace std;

struct piggyBankContenet {
	float penny, nickel, dime, quarter, dollar;
};

piggyBankContenet readTotalOfPiggyBank(piggyBankContenet& TotalOfPiggy) {

	cout << "Please Enter pennies" << endl;
	cin >> TotalOfPiggy.penny;
	while (cin.fail() || TotalOfPiggy.penny < 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> TotalOfPiggy.penny;
	}
	cout << "Please Enter nickels" << endl;
	cin >> TotalOfPiggy.nickel;
	while (cin.fail() || TotalOfPiggy.nickel <= 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> TotalOfPiggy.nickel;
	}

	cout << "Please Enter dimes" << endl;
	cin >> TotalOfPiggy.dime;
	while (cin.fail() || TotalOfPiggy.dime <= 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> TotalOfPiggy.dime;
	}
	cout << "Please Enter quarter" << endl;
	cin >> TotalOfPiggy.quarter;
	while (cin.fail() || TotalOfPiggy.quarter <= 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> TotalOfPiggy.quarter;
	}
	cout << "Please Enter dollar" << endl;
	cin >> TotalOfPiggy.dollar;
	while (cin.fail() || TotalOfPiggy.dollar <= 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> TotalOfPiggy.dollar;
	}
	return TotalOfPiggy;

}
float CalculateOfPennies(piggyBankContenet TotalOfPiggy) {
	float totalOfPennies;
	totalOfPennies = (1 * TotalOfPiggy.penny) + (TotalOfPiggy.nickel * 5) + (TotalOfPiggy.dime * 10) + (TotalOfPiggy.quarter * 25) + (TotalOfPiggy.dollar * 100);
	return totalOfPennies;
}
float CalculateByDollar(piggyBankContenet TotalOfPiggy) {

	return  CalculateOfPennies(TotalOfPiggy) / 100;
}



int main()
{

	piggyBankContenet TotalOfPiggy;


	cout << "Total Of Pennies is " << CalculateOfPennies(readTotalOfPiggyBank(TotalOfPiggy)) << " Pennies\n";
	cout << "Total Of Dollar is " << CalculateByDollar(TotalOfPiggy) << " Dollars\n";
}/*
Please Enter pennies
fdx
Invalid Number, Enter a valid one
-99
Invalid Number, Enter a valid one
100
Please Enter nickels
100
Please Enter dimes
100
Please Enter quarter
100
Please Enter dollar
100
Total Of Pennies is 14100 Pennies
Total Of Dollar is 141 Dollars

 */