#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void countLines(ifstream& ifs,int numberLines,string line){
	while (getline(ifs,line)){
		numberLines++;
		cout << line << endl;
	}
	cout << "___________________________________________" << endl;
	cout << "The number of Lines is: "<< numberLines << endl;
}

void countWords(ifstream& ifs,int numberWords,string words){
	while (ifs >> words){
		numberWords++;
	}
	cout << "The number of Words is: "<< numberWords << endl;
}

void countChar (ifstream& ifs,int numberChars, char chars){
	while (ifs >> chars){
		numberChars++;
	}
	cout << "The number of Characters is: "<< numberChars << endl;
}

int main (){
	string line;
	string words;
	char chars;
	int numberLines = 0;
	int numberWords = 0;
	int numberChars = 0;

	ifstream ifs("jabberwocky.txt");
	if (!ifs) {
		cerr << "File could not be opened!";
		exit(1);
	}	

	countLines(ifs,numberLines,line);
	ifs.close();
	ifs.open("jabberwocky.txt");
	countWords(ifs,numberWords,words);
	ifs.close();
	ifs.open("jabberwocky.txt");
	ifs >> noskipws;	
	countChar(ifs,numberChars,chars);
}