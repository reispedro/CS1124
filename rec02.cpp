/*
	rec02.cpp

	Pedro Vasconcelos de Almeida Reis
	CS1124
	NYU Tandon School of Engineering
*/
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct Hydrocarbon{
	vector <string> names;
	int carbons, hydrogens;
};

void checkIfs(ifstream& ifs);

void createMolecules(ifstream& ifs, vector<Hydrocarbon>& molecules);

int checkForDuplicates(vector<Hydrocarbon>& molecules, int carbons, int hydrogens);

void displayMolecules(vector<Hydrocarbon>& molecules);

int main() {
	vector<Hydrocarbon> molecules;

	ifstream ifs("hydrocarbons.txt");
	checkIfs(ifs);

	createMolecules(ifs, molecules);
	displayMolecules(molecules);

}
   
void checkIfs (ifstream& ifs){ //checks if there is a file opened
	if (!ifs){
		cerr << "File not found!";
		exit(1);
	}
}

void createMolecules(ifstream& ifs, vector<Hydrocarbon>& molecules){
	string name;
	int carbons, hydrogens;
	char discarted; // we need this because of the 'C's and 'H's in the file that represent carbons and hydrogens
	while (ifs >> name >> discarted >> carbons >> discarted >> hydrogens){
		size_t i = checkForDuplicates(molecules, carbons, hydrogens);
		if (i == molecules.size()){ // This is were the duplicate check matters. If there is no molecules with same number of carbons and hydrogens the code runs this if
			Hydrocarbon newHydrocarbon;
			newHydrocarbon.names.push_back(name);
			newHydrocarbon.carbons = carbons;
			newHydrocarbon.hydrogens = hydrogens;
			molecules.push_back(newHydrocarbon);
		}
		else{ // if there is molecules with same number of carbons and hydrogens the code runs this else
			molecules[i].names.push_back(name);
		}
	}
}

int checkForDuplicates(vector<Hydrocarbon>& molecules, int carbons, int hydrogens){
	int sized = molecules.size();
	for (int i = 0; i < sized; i++){ // This is the function that checks if two molecules have the same number of carbons and hydrogens
		int testCarbons = molecules[i].carbons;
		int testHydrogens = molecules[i].hydrogens;
		if (testHydrogens == hydrogens && testCarbons == carbons){
			return i;
		}

	}
	return sized;
}

void displayMolecules(vector<Hydrocarbon>& molecules){
	int max = molecules[0].carbons;
	for (size_t i = 0; i < molecules.size(); i++){ // "Sorts" the molecules by number of carbon atoms.
		if (molecules[i].carbons > max){
			max = molecules[i].carbons;
		}
	}
	for (int x = 1; x <= max; x++){
		for (size_t y = 0; y < molecules.size(); y++){
			if (x == molecules[y].carbons){
				cout << endl << 'C' << molecules[y].carbons << 'H' << molecules[y].hydrogens << ':'<< endl;
				for (size_t n = 0; n < molecules[y].names.size(); n++){ // displays the vector of names
					cout << '\t' << n+1 << ". " << molecules[y].names[n] << endl;
				}
			}
		}
	}
}