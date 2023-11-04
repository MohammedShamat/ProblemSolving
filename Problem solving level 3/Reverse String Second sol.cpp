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

string ReverseWordInText(string fromUser) {
	vector<string> VectorString = Split(fromUser, " ");
	string tempText = "";
	vector<string>::iterator StringIter = VectorString.end();
	while (StringIter != VectorString.begin()) {
		--StringIter;
		tempText += *StringIter + " ";

	}
	tempText = tempText.substr(0, tempText.length() - 1);
	return tempText;
}
int main() {
	string fromUserChar = ReadFromUser("Please Enter your text?");
	cout << "After Reverse Text :\n" << ReverseWordInText(fromUserChar);

}

/*
output :
Please Enter your text?
automatically close the console when debugging stops
After Reverse Text :
stops debugging when console the close automatically

*/