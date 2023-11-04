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
short CountEachWordsInString(string fromUser) {
	string delim = " ";
	short counter = 0;
	cout << "Your string words are :\n";
	short pos = 0;
	string tempWord;
	while ((pos = fromUser.find(delim)) != std::string::npos) {
		tempWord = fromUser.substr(0, pos);
		if (tempWord != "") {
			counter++;
		}
		fromUser.erase(0, pos + delim.length());
	}
	if (fromUser != "") {
		counter++;
	}
	return counter;
}


int main() {
	string fromUserChar = ReadFromUser("Please Enter your text?");
	cout << CountEachWordsInString(fromUserChar);

}

/*
output :

Please Enter your text?
automatically close the console when debugging stops
Your string words are :
7
*/