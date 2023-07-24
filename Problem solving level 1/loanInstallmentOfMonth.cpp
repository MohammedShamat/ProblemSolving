#include <iostream>
#include <string>
using namespace std;
float readNumberFromUser(string message) {

	float number;
	 
		cout << message + "\n";
		cin >> number;
		while (cin.fail() || number <= 0) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid Number, Enter a valid one\n";
			cin >> number;
		}
	
	return number;

}
float calculateOfPay(float loanAmount, float monthlyPayment) {
	float manyOfMonth = loanAmount / monthlyPayment;
	return manyOfMonth;
}
void printResult(float calculateOfPay) {
	cout << "You have To Pay " << calculateOfPay << " in Month\n";
}

int main()
{
	printResult(calculateOfPay(readNumberFromUser("Count Of Loan amount"), readNumberFromUser("Monthly Payment")));
}/*
 Monthly Payment
500
Count Of Loan amount
5000
You have To Pay 10 in Month*/