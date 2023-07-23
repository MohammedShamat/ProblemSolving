#include <iostream>

#include <cmath>

using namespace std;


float readRadious() {
	float Radious;
	cout << "Please Enter a diameter ...\n";
	cin >> Radious;
	while (cin.fail() || Radious <= 0) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number, Enter a valid one\n";
		cin >> Radious;
	}
	return Radious;


}
float areaOfCircleByRaious(float Raious) {
	const float PI = 3.141592653589793238;
	float area = PI * pow(Raious, 2);
	return area;
}
void printArea(float area) {
	cout << "The area is " << area << endl;
}


int main()
{
	printArea(areaOfCircleByRaious(readRadious()));
	return 0;

}/*
 Please Enter a diameter ...
ddw
Invalid Number, Enter a valid one
-9
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
12
The area is 452.389
 */