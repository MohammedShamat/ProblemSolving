#include <iostream>
using namespace std;

float readTotalSales() {
	float totalSales;
	cout << "Please Enter Total Sales?" << endl;
	cin >> totalSales;
	while (cin.fail() || totalSales < 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> totalSales;
	}
	return totalSales;
}
float getComissionPercentage(float totalSales) {
	if (totalSales >= 1000000)
		return 0.01;
	else if (totalSales >= 500000)
		return 0.02;
	else if (totalSales >= 100000)
		return 0.03;
	else if (totalSales >= 50000)
		return 0.05;
	else
		return 0.0;
}
float calculateTotalComission(float totalSales) {
	return getComissionPercentage(totalSales) * totalSales;
}
int main()
{
	cout << "Comission Percentage is " << calculateTotalComission(readTotalSales());
}/*
 
 Please Enter Total Sales?
fds
Invalid Number, Enter a valid one
-999
Invalid Number, Enter a valid one
125000
Comission Percentage is 3750
*/