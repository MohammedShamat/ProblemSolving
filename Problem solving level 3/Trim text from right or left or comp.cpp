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
string TrimLeftText(string fromUser) {
	for (short index = 0; index < fromUser.length(); index++) {
		if (fromUser[index] != ' ') {
			return fromUser.substr(index, fromUser.length() - index);
		}
	}
	return "";
}
string TrimRightText(string fromUser) {
	for (short index = fromUser.length(); index > 0; index--) {
		if (fromUser[index] != ' ') {
			return fromUser.substr(0, index + 1);
		}
	}
	return "";
}
string TrimText(string fromUser) {

	return TrimLeftText(TrimRightText(fromUser));
}
int main() {
	string fromUserChar = ReadFromUser("Please Enter your text?");
	cout << "Text : \n" << fromUserChar << endl;
	cout << "\nTrim Left = " << TrimLeftText(fromUserChar) << endl;
	cout << "\nTrim Right = " << TrimRightText(fromUserChar) << endl;
	cout << "\nTrim = " << TrimText(fromUserChar) << endl;

}
/*
output :

Please Enter your text?
					Press any key to close this window
Text :
					Press any key to close this window

Trim Left = Press any key to close this window

Trim Right =                     Press any key to close this window

Trim = Press any key to close this window

*/