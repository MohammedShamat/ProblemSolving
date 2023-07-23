#include <iostream>

#include <cmath>

using namespace std;


float readCircumference() {
	float Circumference;
	cout << "Please Enter a Circumference ...\n";
	cin >> Circumference;
	while (cin.fail() || Circumference <= 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> Circumference;
	}
	return Circumference;


}
float areaOfCircleAlongTheCircumference(float Circumference) {
	const float PI = 3.141592653589793238;
	float area = (pow(Circumference, 2)) / (4 * PI);
	return area;
}
void printArea(float area) {
	cout << "The area is " << area << endl;
}


int main()
{

	printArea(areaOfCircleAlongTheCircumference(readCircumference()));



	return 0;


}/*
 Please Enter a Circumference ...
asw
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
-12
Invalid Number, Enter a valid one
15
The area is 17.9049

 */