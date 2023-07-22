#include <iostream>
#include <string>
using namespace std;

struct personInfo {
	short age;
	bool hasDrivingLicense;
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
	cout << "Do you have a driving license ( 0 for No ) or ( 1 for Yes )\n";
	cin >> info.hasDrivingLicense;
	while (cin.fail() || (info.hasDrivingLicense > 1 && info.hasDrivingLicense < 0)) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Please enter 0 or 1\n";
		cin >> info.hasDrivingLicense;
	}
	return info;
}
bool isAccepted(personInfo info) {
	return(info.age >= 18 && info.hasDrivingLicense);
}

void printResult(bool isAccepted) {
	if (isAccepted)
		cout << "\nHired";
	else
		cout << "\nRejected";



}

int main()
{

	printResult(isAccepted(readInfo()));

	return 0;

}/*
 output
 Please Enter Your Age
asds
Please enter a valid value for your age..
-6
Please enter a valid value for your age..
0
Please enter a valid value for your age..
19
Do you have a driving license ( 0 for No ) or ( 1 for Yes )
2
Please enter 0 or 1
3
Please enter 0 or 1
-9
Please enter 0 or 1
sss
Please enter 0 or 1
1

Hired
 
 */