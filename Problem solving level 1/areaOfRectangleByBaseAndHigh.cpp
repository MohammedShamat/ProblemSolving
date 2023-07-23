#include <iostream>

#include <cmath>

using namespace std;


void readNumbersFromUsers(float& base, float& height) {

	cout << "Please Enter a base ...\n";
	cin >> base;
	while (cin.fail() || base <= 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> base;
	}
	cout << "Please Enter high ...\n";
	cin >> height;
	while (cin.fail() || height <= 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> height;
	}

}
float areaOfRectangleByBaseAndHigh(float base, float height) {

	float area = (base * height) / 2;
	return area;
}
void printArea(float area) {
	cout << "The area is " << area << endl;
}


int main()
{
	float base, height;
	readNumbersFromUsers(base, height);
	printArea(areaOfRectangleByBaseAndHigh(base, height));

	return 0;

}/*
 Please Enter a base ...
aa
Invalid Number, Enter a valid one
-3
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
12
Please Enter high ...
15
The area is 90

 */