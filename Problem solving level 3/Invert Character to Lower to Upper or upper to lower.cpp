#include<iostream>
#include<string>
#include<cctype>
using  namespace std;
char ReadFromUser(string message) {
	cout << message << endl;
	char charFromUser;
	cin >> charFromUser;
	return charFromUser;
}
bool IsLowerLetter(char readChar) {
	return islower(readChar);
}

char InvertCharacter(char charFromUser) {
	return IsLowerLetter(charFromUser) ? toupper(charFromUser) : tolower(charFromUser);

}
void PrintResult(char charFromUser) {
	cout << "Invert character is : " << charFromUser << endl;
}
int main() {
	char fromUser = ReadFromUser("Please Enter Your Character?");
	PrintResult(InvertCharacter(fromUser));
}

/*
output :

Please Enter Your Character?
L
Invert character is : l
Please Enter Your Character?
a
Invert character is : A
*/