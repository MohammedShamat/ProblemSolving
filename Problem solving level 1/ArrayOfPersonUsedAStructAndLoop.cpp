#include <iostream>
using namespace std;


struct personInfo {
	string FirstName;
	string LastName;
	short age;
	string PhoneNumber;
};

void ReadInfo(personInfo& info) {

	cout <<"**************************" << endl;
	cout << "Please Enter First Name?" << endl;
	cin >> info.FirstName;
	cout << "Please Enter Last Name?" << endl;
	cin >> info.LastName;
	cout << "Please Enter Your Age ?" << endl;
	cin >> info.age;
	cout << "Please Enter Your Phone ?" << endl;
	cin >> info.PhoneNumber;
	cout << "**************************" << endl;

}

void ReadArrayOfPersons(personInfo LastOfPersons [100],short& numberOfPersons) {
	cout << "How many persons?" << endl;
	cin >> numberOfPersons;
	for (short counterOfArray = 0; counterOfArray < numberOfPersons;counterOfArray++) {
		cout << "Please Enter person's" << counterOfArray + 1 <<" info" << endl;
		ReadInfo(LastOfPersons[counterOfArray]);
	}
}
void printInfoPerson(personInfo infoPerson) {
	cout << "**************************" << endl;
	cout<<"Your name is :"<< infoPerson.FirstName << endl;
	cout<<"Your last name is:"<< infoPerson .LastName<< endl;
	cout<<"Your age is"<< infoPerson.age << endl;
	cout<<"Your Phone Number is" << infoPerson.PhoneNumber << endl;
	cout << "**************************" << endl;
}
void printListInfoOfPersons(personInfo persons[100],short numberOfPersons) {
	for (short counterOfArray = 0; counterOfArray < numberOfPersons; counterOfArray++) {
		cout<<"info person's"<<counterOfArray+1<<endl;
		printInfoPerson(persons[counterOfArray]);
	}
	
}
 

int main()
{
	short numberOfPersons;
	personInfo persons[100];
	ReadArrayOfPersons(persons, numberOfPersons);
	printListInfoOfPersons(persons, numberOfPersons);

}