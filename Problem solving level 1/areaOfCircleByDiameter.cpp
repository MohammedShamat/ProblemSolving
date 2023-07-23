#include <iostream>

#include <cmath>

using namespace std;


float readDiameter() {
    float diameter;
    cout << "Please Enter a diameter ...\n";
    cin >> diameter;
    while (cin.fail() || diameter <= 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid Number, Enter a valid one\n";
        cin >> diameter;
    }
    return diameter;


}
float areaOfCircleByDiameter(float diameter) {
    const float PI = 3.141592653589793238;
    float area = (PI * pow(diameter, 2)) / 4;
    return area;
}
void printArea(float area) {
    cout << "The area is " << area << endl;
}


int main()
{

    printArea(areaOfCircleByDiameter(readDiameter()));



    return 0;

}/*
 
 Please Enter a diameter ...
aqe3
Invalid Number, Enter a valid one
-3
Invalid Number, Enter a valid one
0
Invalid Number, Enter a valid one
15
The area is 176.715


*/