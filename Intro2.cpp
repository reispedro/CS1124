#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void openInputStream(ifstream& inFile){
	string filename;
	cout << "What file name? ";
	cin >> filename;
	inFile.open(filename);
	while (!inFile){
		cout << "Bad Filename" << endl;
		cout << "What file name? ";
		cin >> filename;
		inFile.clear(); //if you don't clear, than a successful open cannot be detected!
		inFile.open(filename);

	}
}

double calcAverage(vector<int> v){
	double sum = 0;
	for (int i : v)
		sum += i;
	return (sum / v.size());
}

int main(){
	vector<int> v;
	ifstream inFile;
	openInputStream(inFile);
	int temp;
	while (inFile >> temp)
		v.push_back(temp);
	double average = calcAverage(v);
	for (int i = 0; i<v.size(); i++)
		if (v[i] > average)
			cout << "Found value " << v[i] << " at position "<< (i+1)
			<<" which is greater than " << average << endl;
}