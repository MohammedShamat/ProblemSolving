#include <iostream>

#include <cmath>

using namespace std;


float readSideOfSquare() {
	float side;
	cout << "Please Enter a side of square ...\n";
	cin >> side;
	while (cin.fail() || side <= 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> side;
	}
	return side;


}
float areaOfCircleInscribedInASquare(float side) {
	const float PI = 3.141592653589793238;
	float area = (PI * pow(side, 2)) / 4;
	return area;
}
void printArea(float area) {
	cout << "The area is " << area << endl;
}


int main()
{

	printArea(areaOfCircleInscribedInASquare(readSideOfSquare()));



	return 0;

}/*
 
 Please Enter a side of square ...
ss-
Invalid Number, Enter a valid one
-9
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
15
The area is 176.715

*/