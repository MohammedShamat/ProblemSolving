#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using  namespace std;
struct ClientData {
	string accNumber = "";
	string pinCode = "";
	string nameClient = "";
	string phoneNumber = "";
	double accBalance = 0.0;
};
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

string SetDataOfClient() {

	string clientDataInLine = "A150#//#12345#//#Moahmmed Shamat#//#05693485565#//#" + to_string(58963);
	return clientDataInLine;
}
ClientData SetDataToRecord() {
	ClientData clientData;
	vector<string> vClientData = Split(SetDataOfClient(), "#//#");
	clientData.accNumber = vClientData[0];
	clientData.pinCode = vClientData[1];
	clientData.nameClient = vClientData[2];
	clientData.phoneNumber = vClientData[3];
	clientData.accBalance = stod(vClientData[4]);

	return clientData;
}
void PrintData(ClientData dataFromClient) {
	cout << "\n\nThe following is the extracted client record :\n\n";
	cout << "Acc Number  : " << dataFromClient.accNumber << endl;
	cout << "Pin Code    : " << dataFromClient.pinCode << endl;
	cout << "Name        : " << dataFromClient.nameClient << endl;
	cout << "Phone       : " << dataFromClient.phoneNumber << endl;
	cout << "Acc Balance : " << to_string(dataFromClient.accBalance) << endl;
}
int main() {
	cout << "Line Record is : \n" << SetDataOfClient() << endl;
	PrintData(SetDataToRecord());


}

/*
output :

Line Record is :
A150#//#12345#//#Moahmmed Shamat#//#05693485565#//#58963


The following is the extracted client record :

Acc Number  : A150
Pin Code    : 12345
Name        : Moahmmed Shamat
Phone       : 05693485565
Acc Balance : 58963.000000

*/