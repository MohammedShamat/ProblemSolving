#include <iostream>

#include <cmath>

using namespace std;


void readSideAndBaseAndHypotenuse(float& side, float& base, float& Hypotenuse) {

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
    cout << "Please Enter a Hypotenuse ...\n";
    cin >> Hypotenuse;
    while (cin.fail() || Hypotenuse <= 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid Number, Enter a valid one\n";
        cin >> Hypotenuse;
    }

}
float areaOfCircleDescribedAroundAnArbitraryTriangle(float side, float base, float Hypotenuse) {
    const float PI = 3.141592653589793238;
    float T = (side + base + Hypotenuse) / 2;
    float ex = (side * base * Hypotenuse) / (4 * sqrt(T * (T - side) * (T - base) * (T - Hypotenuse)));
    float area = PI * (pow(ex, 2));
    return area;
}
void printArea(float area) {
    cout << "The area is " << area << endl;
}


int main()
{
    float side, base, Hypotenuse;
    readSideAndBaseAndHypotenuse(side, base, Hypotenuse);
    printArea(areaOfCircleDescribedAroundAnArbitraryTriangle(side, base, Hypotenuse));

    return 0;

}/*
 Please Enter a side ...
ewe
Invalid Number, Enter a valid one
-99
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
15
Please Enter a base ...
15
Please Enter a Hypotenuse ...
15
The area is 235.619

 */