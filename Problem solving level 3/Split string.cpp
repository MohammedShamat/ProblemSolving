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
vector<string> Split(string fromUser, string delimit) {
	vector <string> textFromUser;
	short position = 0;
	string tempWord = "";
	while ((position = fromUser.find(delimit)) != std::string::npos) {
		tempWord = fromUser.substr(0, position);
		if (tempWord != "") {
			textFromUser.push_back(tempWord);
		}
		fromUser.erase(0, position + delimit.length());
	}
	if (fromUser != "") {
		textFromUser.push_back(fromUser);
	}
	return textFromUser;
}

void PrintVector(vector <string>& textFromUser) {
	for (string& copy : textFromUser) {
		cout << copy << endl;
	}
}

int main() {
	string fromUserChar = ReadFromUser("Please Enter your text?");
	string delimit = " ";
	vector <string> textFromUser = Split(fromUserChar, delimit);
	cout << "Tokens = " << textFromUser.size() << endl;
	PrintVector(textFromUser);

}

/*
output :

Please Enter your text?
automatically close the console when debugging stops

automatically

close

the

console

when

debugging

stops

*/