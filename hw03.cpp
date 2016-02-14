/*
	hw03.

	Pedro Vasconcelos de Almeida Reis
	CS1124
	Polytechnic University
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Warrior{
private:
	string warriorName;
	string warriorWeapon;
	int warriorStrenght;
public:
	Warrior(int strenght = 0, string name = "name", string weapon = "weapon");

	void setName(string name) { warriorName = name; }

	void setWeapon(string weapon) {warriorWeapon = weapon; }

	void setStrenght(int strenght) { warriorStrenght = strenght; }

	string getName() const { return warriorName; }

	string getWeapon() const { return warriorWeapon; }

	int getStr() const { return warriorStrenght; }

	void displayWarrior() const;
};

void checkIfs(ifstream& ifs);

void fileReader(ifstream& ifs, vector <Warrior>& warriors);

void createWarrior (ifstream& ifs, vector <Warrior>& warriors);

void fight(vector <Warrior>& warriors, ifstream& ifs);

Warrior::Warrior(int strenght, string name, string weapon){
	warriorName = name;
	warriorStrenght = strenght;
	warriorWeapon = weapon;
}

void Warrior::displayWarrior() const{
	cout << "Warrior: " << warriorName << ", weapon: " << warriorWeapon << ", " << warriorStrenght << endl;
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
			for (size_t i = 0; i < warriors.size(); ++i) {
				warriors[i].displayWarrior();
			}
			cout << "--------------------\n";
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
	string warriorName;
	string warriorWeapon;
	int warriorStrenght;

	ifs >> warriorName >> warriorWeapon >> warriorStrenght;

	Warrior newWarrior(warriorStrenght,warriorName,warriorWeapon) ;

	warriors.push_back(newWarrior);
}


void fight(vector <Warrior>& warriors, ifstream& ifs){
	string warrior1;
	string warrior2;
	ifs >> warrior1 >> warrior2;
	Warrior fighter1;
	Warrior fighter2;

	for (size_t i = 0; i < warriors.size(); ++i) {
		if (warrior1 == warriors[i].getName()){
			fighter1 = warriors[i];
		}

		else if (warrior2 == warriors[i].getName()){
			fighter2 = warriors[i];
		}
	}

	cout << fighter1.getName() << " battles " << fighter2.getName() << "!\n";

	if (fighter1.getStr() > fighter2.getStr()){
		if (fighter2.getStr() == 0){	
			cout << "He's dead, " << fighter1.getName() << "!\n"; 
			cout << "--------------------\n";
		}
		else{
			fighter1.setStrenght(fighter1.getStr() - fighter2.getStr());
			fighter2.setStrenght(0);
			cout << fighter1.getName() << " defeats " << fighter2.getName() << endl;
			cout << "--------------------\n";
		}
	}

	else if (fighter2.getStr() > fighter1.getStr()){
		fighter2.setStrenght(fighter2.getStr() - fighter1.getStr());
		fighter1.setStrenght(0);
	}

	else if (fighter1.getStr() == fighter2.getStr()){
		if (fighter1.getStr() == 0 && fighter2.getStr() == 0)	{ 
			cout << "Oh, NO! They're both dead! Yuck!\n"; 
			cout << "================================\n";
		}
		else{
			fighter1.setStrenght(0);
			fighter2.setStrenght(0);
			cout << "Mutual Annihalation: " << fighter1.getName() << " and " << fighter2.getName() << " die at each other's hands!\n";
			cout << "--------------------\n";
		}
	}

	for (size_t j = 0; j < warriors.size(); ++j){
		if (fighter1.getName() == warriors[j].getName()){
			warriors[j].setStrenght(fighter1.getStr());
		}

		else if (fighter2.getName() == warriors[j].getName()){
			warriors[j].setStrenght(fighter2.getStr());
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