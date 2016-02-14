/*
	hw02.

	Pedro Vasconcelos de Almeida Reis
	CS1124
	Polytechnic University
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Warrior{
	string warriorName;
	int warriorStrenght;
};

void displayWarriors(vector<Warrior>& warriors);

void checkIfs(ifstream& ifs);

void fileReader(ifstream& ifs, vector <Warrior>& warriors);

void createWarrior (ifstream& ifs, vector <Warrior>& warriors);

void fight(vector <Warrior>& warriors, ifstream& ifs);



void displayWarriors(vector<Warrior>& warriors){
	for (size_t i = 0; i < warriors.size(); ++i) {
		cout << "Warrior: " << warriors[i].warriorName << ", strenght: " << warriors[i].warriorStrenght << endl;
	}
}

void checkIfs (ifstream& ifs){ //checks if there is a file opened
	if (!ifs) {
		cerr << "File not found";
		exit(1);
	}
}

void fileReader(ifstream& ifs, vector <Warrior>& warriors)
{
	string fWord;
	while (ifs >> fWord) {
		if (fWord == "Warrior") {
			createWarrior (ifs, warriors);
		}

		if (fWord == "Status") {
			cout << "There are: " << warriors.size() << " warriors" << endl;
			displayWarriors(warriors);
		}

		if (fWord == "Battle") {
			if (warriors.size() < 1) {//checks we have enough warriors to battle.
				cerr << "No warriors entered!\n";
				exit(1);
			}

			fight(warriors, ifs);
		}
	}
}

void createWarrior (ifstream& ifs, vector <Warrior>& warriors){
	Warrior newWarrior;

	ifs >> newWarrior.warriorName >> newWarrior.warriorStrenght;

	warriors.push_back(newWarrior);
}


void fight(vector <Warrior>& warriors, ifstream& ifs){
	string warrior1;
	string warrior2;
	ifs >> warrior1 >> warrior2;
	Warrior fighter1;
	Warrior fighter2;

	for (size_t i = 0; i < warriors.size(); ++i) {
		if (warrior1 == warriors[i].warriorName){
			fighter1 = warriors[i];
		}

		else if (warrior2 == warriors[i].warriorName){
			fighter2 = warriors[i];
		}
	}

	cout << fighter1.warriorName << " battles " << fighter2.warriorName << "!\n";

	if (fighter1.warriorStrenght > fighter2.warriorStrenght){
		if (fighter2.warriorStrenght == 0){	
			cout << "He's dead, " << fighter1.warriorName << "!\n"; 
			cout << "--------------------\n";
		}
		else{
			fighter1.warriorStrenght = (fighter1.warriorStrenght - fighter2.warriorStrenght);
			fighter2.warriorStrenght = 0;
			cout << fighter1.warriorName << " defeats " << fighter2.warriorName << endl;
			cout << "--------------------\n";
		}
	}

	else if (fighter2.warriorStrenght > fighter1.warriorStrenght){
		fighter2.warriorStrenght = fighter2.warriorStrenght - fighter1.warriorStrenght;
		fighter1.warriorStrenght = 0;
	}

	else if (fighter1.warriorStrenght == fighter2.warriorStrenght){
		if (fighter1.warriorStrenght == 0 && fighter2.warriorStrenght == 0)	{ 
			cout << "Oh, NO! They're both dead! Yuck!\n"; 
			cout << "================================\n";
		}
		else{
			fighter1.warriorStrenght = 0;
			fighter2.warriorStrenght = 0;
			cout << "Mutual Annihalation: " << fighter1.warriorName << " and " << fighter2.warriorName << " die at each other's hands!\n";
			cout << "--------------------\n";
		}
	}

	for (size_t j = 0; j < warriors.size(); ++j){
		if (fighter1.warriorName == warriors[j].warriorName){
			warriors[j].warriorStrenght = fighter1.warriorStrenght;
		}

		else if (fighter2.warriorName == warriors[j].warriorName){
			warriors[j].warriorStrenght = fighter2.warriorStrenght;
		}
	}
}

int main()
{
	vector <Warrior> warriors;

	ifstream ifs("warriors.txt");
	checkIfs(ifs);

	fileReader(ifs, warriors);
}