#include <iostream>
#include <string>
using namespace std;

//A restaurant charges 10% services fee and 16% sales Tax

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

float salesTax(float totalBillWithServiceFee) {
	float totalBillWithServiceFeeAndTax = 0.0;
	totalBillWithServiceFeeAndTax = totalBillWithServiceFee * 1.16;
	return totalBillWithServiceFeeAndTax;
}

float servicesFee(float totalBill) {

	float totalBillWithServiceFee = 0.0;
	totalBillWithServiceFee = totalBill * 1.10;
	salesTax(totalBillWithServiceFee);
	return salesTax(totalBillWithServiceFee);
}

void printPaidBack(float paidBack) {

	cout << "total Bill With Service Fee and sales tax :" << paidBack;
}



int main()
{

	float totalBillWithServiceFee = readNumberFromUser("Please Enter a TotalBill ?");
	
	printPaidBack(servicesFee(totalBillWithServiceFee));

	
}/*
 
 Please Enter a TotalBill ?
ddd
Invalid Number, Enter a valid one
-9
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
110
total Bill With Service Fee and sales tax :140.36*/