#include <iostream>
#include <string>
using namespace std;

float readNumberFromUser(string message) {
	float number;

	cout << message + "\n";
	cin >> number;
	while (cin.fail()||number<=0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> number;
	}
	return number;
}
float calculateRemainder(float totalBill, float cashpaid) {
	float paidBack = 0.0;
	paidBack = cashpaid - totalBill;
	return paidBack;//And can use like this "cashpaid-totalBill" ;
}
void printPaidBack(float paidBack) {
	cout << "The Paid Back is :" << paidBack;
}



int main()
{

	float totalBill = readNumberFromUser("Please Enter a TotalBill");
	float cashPaid = readNumberFromUser("Please Enter a Cashpaid");
	printPaidBack(calculateRemainder(totalBill, cashPaid));


}/*
 
 
 Please Enter a TotalBill
rfsf
Invalid Number, Enter a valid one
-9
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
100
Please Enter a Cashpaid
120
The Paid Back is :20
*/