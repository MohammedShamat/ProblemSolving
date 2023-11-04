#include<iostream>
#include<string>
#include<vector>
using  namespace std;

string JoinString(vector <string> vOfString, string delimit) {
	string joinText = "";
	for (string& tempText : vOfString) {
		joinText = joinText + tempText + delimit;
	}
	return joinText.substr(0, joinText.length() - delimit.length());
}
string JoinString(string arrOfString[5], short arrLength, string delimit) {
	string joinText = "";
	for (short index = 0; index < arrLength; index++) {
		if (index != 0 && index != arrLength) {
			joinText.append(delimit);
		}
		joinText.append(arrOfString[index]);
	}
	return joinText;
}
int main() {
	vector <string> vOfString = { "First","Second","Third","Four","Five" };
	string arrOFString[] = { "First", "Second", "Third", "Four", "Five" };
	cout << "After Join Vector : \n" << JoinString(vOfString, "###") << endl;
	cout << "\nAfter Join Array Of String : \n" << JoinString(arrOFString, 5, "###") << endl;
}

/*
output :

After Join Vector :
First###Second###Third###Four###Five

After Join Array Of String :
First###Second###Third###Four###Five
*/