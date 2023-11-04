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
int main() {
	vector <string> vOfString = { "First","Second","Third","Four","Five" };
	cout << "After Join : \n" << JoinString(vOfString, "###") << endl;
}

/*
output :

After Join :
First,Second,Third,Four,Five
or
After Join :
First###Second###Third###Four###Five
*/