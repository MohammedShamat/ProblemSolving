#include <iostream>
#include <string>
using namespace std;

struct personInfo {
    short age = 0;
    string firstName;
    string lastName;
};

personInfo readInfo() {
    personInfo info;
    cout << "Please Enter Your Age\n";
    cin >> info.age;
    while (cin.fail() || info.age <= 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter a valid value for your age..\n";
        cin >> info.age;
    }
    cout << "Please Enter Your First name\n";
    cin >> info.firstName;
    cout << "Please Enter Your last Name\n";
    cin >> info.lastName;
    return info;

}
string getInfoPerson(personInfo infoPerson) {
    const string space = " ";
    string infoOfPerson = "";
    infoOfPerson = infoPerson.firstName + space + infoPerson.lastName + " your age is " + to_string(infoPerson.age);
    return infoOfPerson;

}
void printFullName(string printInfo) {

    cout << "***********\n";
    cout << printInfo;
    cout << "\n***********";

}


int main()
{

    printFullName(getInfoPerson(readInfo()));

    return 0;

}/*
 Please Enter Your Age
28
Please Enter Your First name
muhammed
Please Enter Your last Name
shamat
***********
muhammed shamat your age is 28
***********
*/