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
string ReverseString(string fromUser) {
	string tempWord = "";
	char space = ' ';
	for (short index = fromUser.length(); index > 0; index--) {
		if (fromUser[index] == space) {
			tempWord = tempWord + fromUser.substr(index + 1, fromUser.length()) + space;
			fromUser = fromUser.erase(index, fromUser.length());

		}
	}
	if (fromUser != "") {
		tempWord = tempWord + fromUser;
	}
	return tempWord;

}

int main() {
	string fromUserChar = ReadFromUser("Please Enter your text?");
	cout << "After Reverse Text\n" << ReverseString(fromUserChar);

}

/*
output :

Please Enter your text?
automatically close the console when debugging stops

stops debugging when console the close automatically

or

Please Enter your text?
yyyyy uuuuu iiiii ooooo aaaaa sssss ddddd vvvvv nnnnn mmmmm kkkkk

kkkkk mmmmm nnnnn vvvvv ddddd sssss aaaaa ooooo iiiii uuuuu yyyyy

*/