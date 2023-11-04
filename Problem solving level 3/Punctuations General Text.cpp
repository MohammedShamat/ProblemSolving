#include<iostream>
#include<string>
#include<vector>
using  namespace std;
string ReadFromUser(string message) {
	cout << message << endl;
	string TextFromUser = "";
	getline(cin, TextFromUser);
	return TextFromUser;
}
string PunctuationsText(string fromUser, char delimiter) {
	for (short index = 0; index < fromUser.length(); index++) {
		if (fromUser[index] == delimiter) {
			fromUser[index] = 00;
		}
	}
	return fromUser;
}
string PunctuationsGeneralText(string fromUser) {
	string tempText = "";
	for (short index = 0; index < fromUser.length(); index++) {
		if (!ispunct(fromUser[index])) {
			tempText += fromUser[index];
		}
	}
	return tempText;
}

int main() {
	string textForTest = "Welcome, to ,Syria, Syria is, a nice country,and Syria ,is so awesome ,Country ";
	cout << "Before edit :\n" << textForTest << endl;
	cout << "\nPunctuations Text:\n" << PunctuationsText(textForTest, ',') << endl;
	cout << "\nGeneral fun:\n" << PunctuationsGeneralText(textForTest);

}

/*
output :

Before edit :
Welcome, to ,Syria, Syria is, a nice country,and Syria ,is so awesome ,Country

Punctuations Text:
Welcome to Syria Syria is a nice countryand Syria is so awesome Country

General fun:
Welcome to Syria Syria is a nice countryand Syria is so awesome Country


*/