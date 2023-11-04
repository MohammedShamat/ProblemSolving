#include<iostream>
#include<string>
#include<cctype>
using  namespace std;
string ReadFromUser(string message) {
	cout << message << endl;
	string TextFromUser = "";
	getline(cin, TextFromUser);
	return TextFromUser;
}
void PrintEachWordInString(string fromUser) {
	string delim = " ";
	cout << "Your string words are :\n";
	short pos = 0;
	string tempWord;
	while ((pos = fromUser.find(delim)) != std::string::npos) {
		tempWord = fromUser.substr(0, pos);
		if (tempWord != "") {
			cout << tempWord << endl;
		}
		fromUser.erase(0, pos + delim.length());
	}
	if (fromUser != "") {
		cout << fromUser << endl;
	}
}


int main() {
	string fromUserChar = ReadFromUser("Please Enter your text?");
	PrintEachWordInString(fromUserChar);

}

/*
output :

Please Enter your text?
automatically close the console when debugging stops
Your string words are :
automatically
close
the
console
when
debugging
stops
*/