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
string ReplaceWordInText(string fromUser, string word, string replaceWord, bool matchCase = true) {
	short pos = 0;
	if (matchCase) {
		while (((pos = fromUser.find(word)) != std::string::npos)) {
			fromUser.erase(pos, word.length());
			fromUser.insert(pos, replaceWord);
		};
	}
	else {
		word[0] = toupper(word[0]);
		while (((pos = fromUser.find(word)) != std::string::npos)) {
			fromUser.erase(pos, word.length());
			fromUser.insert(pos, replaceWord);
		};
	}


	return fromUser;
}

int main() {
	string fromUserChar = "Welcome to Syria, Syria is a nice country,and Syria is so awesome Country ";
	cout << "Original string :\n" << fromUserChar << endl;
	cout << "\nwith match case replace Word :\n" << ReplaceWordInText(fromUserChar, "syria", "USA") << endl;
	cout << "\nWith don\'t match case replace Word :\n" << ReplaceWordInText(fromUserChar, "syria", "USA", false) << endl;

}

/*
output :

Original string :
Welcome to Syria, Syria is a nice country,and Syria is so awesome Country

with match case replace Word :
Welcome to Syria, Syria is a nice country,and Syria is so awesome Country

With don't match case replace Word :
Welcome to USA, USA is a nice country,and USA is so awesome Country


*/