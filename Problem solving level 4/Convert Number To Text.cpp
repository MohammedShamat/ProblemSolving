#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

using  namespace std;

int ReadNumber(string message) {
	int number = 0;
	cout << message << endl;
	cin >> number;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> number;
	}
	return number;
}

string ConvertNumberToText(int number) {

	if (number == 0) {
		return "Zero";
	}
	if (number >= 1 && number <= 19) {
		string arrOneToTwenty[] = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
		"Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen " };
		return arrOneToTwenty[number] + " ";
	}

	if (number >= 20 && number <= 99) {
		string arrTwentyToNinety[] = { "","","Twenty ","Thirty ","Fourty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety " };
		return arrTwentyToNinety[(number / 10)] + "" + ConvertNumberToText(number % 10);
	}

	if (number >= 100 && number <= 199) {

		return "One Hundred " + ConvertNumberToText(number % 100);
	}
	if (number >= 200 && number <= 999) {

		return ConvertNumberToText(number / 100) + "Hundreds " + ConvertNumberToText(number % 100);
	}

	if (number >= 1000 && number <= 1999) {
		return"One Thousand " + ConvertNumberToText(number % 1000);
	}

	if (number >= 2000 && number <= 999999) {
		return   ConvertNumberToText(number / 1000) + "Thousands " + ConvertNumberToText(number % 1000);
	}

	if (number >= 1000000 && number <= 1999999) {
		return"One Million " + ConvertNumberToText(number % 1000000);
	}

	if (number >= 2000000 && number <= 999999999) {
		return   ConvertNumberToText(number / 1000000) + "Millions " + ConvertNumberToText(number % 1000000);
	}

	if (number >= 1000000000 && number <= 1999999999) {
		return"One Billion " + ConvertNumberToText(number % 1000000000);
	}

	else {

		return   ConvertNumberToText(number / 1000000000) + "Billions " + ConvertNumberToText(number % 1000000000);
	}
}

int main() {
	int numberFromUser = ReadNumber("Enter a number?");
	cout << ConvertNumberToText(numberFromUser);
}
/*
output

Enter a number?
515346
Five Hundreds Fifteen  Thousands Three Hundreds Fourty Six


*/