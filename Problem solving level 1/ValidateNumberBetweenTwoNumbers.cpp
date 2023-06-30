#include <iostream>
using namespace std;

double rangeNumberBetweenTwoNumbers(double from, double to) {
    double number;
    do {

        cout << "Please Enter A number between ?"<<from<<" and "<<to<<"\n";
        cin >> number;

    } while (number < from || number > to);
    
    return number;
}

int main()
{
    cout<<rangeNumberBetweenTwoNumbers(18,44);
	}