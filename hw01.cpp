/*
	hw01.
	We are given a file of text that has been encrypted. 
	This program will read an encrypted file and decrypt it.

	Pedro Vasconcelos de Almeida Reis
	CS1124
	Polytechnic University
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void checkIfs(ifstream& ifs);

void displayMessage(vector<string>& correctedMessage, vector<string>& message);

char decryptCharacter(char encryptedLetter, int counter);

void decryptLine(vector<string>& encryptedMessage, int counter);

void createMessage(ifstream& ifs, string encryptedWord, vector<string>& message);

void invertMessage(vector<string>& message, vector<string>& correctedMessage);

int main(){
	int encryptionNumber;
	string encryptedWord;

	ifstream ifs("encrypted.txt");
	checkIfs(ifs);

	vector <string> message;
	vector <string> correctedMessage;

	ifs >> encryptionNumber;
	getline(ifs, encryptedWord);

	createMessage(ifs, encryptedWord, message);
	invertMessage(message, correctedMessage);
	decryptLine(correctedMessage, encryptionNumber);
	displayMessage(correctedMessage, message);

	ifs.close();
}

void checkIfs (ifstream& ifs){ //checks if there is a file opened
	if (!ifs) {
		cerr << "File not found";
		exit(1);
	}
}

void displayMessage(vector<string>& correctedMessage, vector<string>& message){
	cout << "----------------------\n\tEncrypted Message:\n" << endl;
	for (string& line : message)
	{
		cout << line << endl;
	}	
	cout << endl <<"----------------------\n\tDecrypted Message:" << endl;
	for (string& newLine : correctedMessage)
	{
		cout << newLine << endl;
	}
}

char decryptCharacter(char encryptedLetter, int counter){ // Rotates through the alphabet to decrypt the message, letter by letter
	if (encryptedLetter < 123 && encryptedLetter > 96) // Makes sure the character is an alphabet letter
	{
		char decryptedLetter = encryptedLetter - counter; 
		if (decryptedLetter < 96) // Wraps back around the alphabet if the number of steps makes it go over 'z'
		{
			decryptedLetter += (123 - 97); 
		}
		return decryptedLetter;
	}
	return encryptedLetter;
}

void decryptLine(vector<string>& encryptedMessage, int counter){
	char decryptedChar;
	for (size_t i = 0; i < encryptedMessage.size(); ++i) //line by line
	{
		for (size_t j = 0; j< encryptedMessage[i].size(); ++j) // letter by letter
		{
			decryptedChar = decryptCharacter(encryptedMessage[i][j], counter);
			encryptedMessage[i][j] = decryptedChar;
		}
	}
}

void createMessage(ifstream& ifs, string encryptedWord, vector<string>& message){
	while (!ifs.eof()) 
	{
		getline(ifs, encryptedWord); // Reads each line from the file and transforms that into a string
		message.push_back(encryptedWord); // The string is now pushed into a vector of strings
	}
}

void invertMessage(vector<string>& message, vector<string>& correctedMessage){
	for (int i = message.size() - 1; i >= 0; i--)
	{
		correctedMessage.push_back(message[i]); // Inverts the order of the lines in the text
	}
}