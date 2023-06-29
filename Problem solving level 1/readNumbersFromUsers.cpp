#include <iostream>

#include <cmath>

using namespace std;


float readNumbersFromUsers() {
    float diameter;
    cout << "Please Enter a diameter ...\n";
    cin >> diameter;
    return diameter;


}
float areaOfCircleByDiameter(float diameter) {
    const float PI = 3.141592653589793238;
    float area = PI * pow(diameter, 2);
    return area;
}
void printArea(float area) {
    cout << "The area is " << area << endl;
}


int main()
{

    printArea(areaOfCircleByDiameter(readNumbersFromUsers()));



    return 0;

}