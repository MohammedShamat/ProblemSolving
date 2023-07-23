#include <iostream>

#include <cmath>

using namespace std;


void readSideAndBase(float& side, float& base) {

    cout << "Please Enter a side ...\n";
    cin >> side;
    while (cin.fail() || side <= 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid Number, Enter a valid one\n";
        cin >> side;
    }
    cout << "Please Enter a base ...\n";
    cin >> base;
    while (cin.fail() || base <= 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid Number, Enter a valid one\n";
        cin >> base;
    }

}
float areaOfCircleInscribedInAnIsoscelesTriangle(float side, float base) {
    const float PI = 3.141592653589793238;
    float T = (2 * side - base) / (2 * side + base);
    float area = (PI * pow(base, 2) * T) / 4;
    return area;
}
void printArea(float area) {
    cout << "The area is " << area << endl;
}


int main()
{
    float side, base;
    readSideAndBase(side, base);
    printArea(areaOfCircleInscribedInAnIsoscelesTriangle(side, base));

    return 0;

}/*
 Please Enter a side ...
sw
Invalid Number, Enter a valid one
-22
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
15
Please Enter a base ...
15
The area is 58.9049
 */