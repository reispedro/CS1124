#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Sandwich{
private:
	const int bread;
	int cheese;
	double mayo;
	int tomato;
	double mustard;
public:
	Sandwich( int cheeseSlices = 1, double mayoAmmount = 1, int tomatoSlices = 2, double mustardAmmount = 0.5);

	void displaySandwich() const;

	int getBread() const {return bread;}
	int getCheese() const {return cheese;}
	double getMayo() const {return mayo;}
	int getTomato() const {return tomato;}
	double getMustard() const {return mustard;}

	void setCheese(int newCheese) {cheese = newCheese;}
	void setMayo(double newMayo) {mayo = newMayo;}
	void setTomato(int newTomato) {tomato = newTomato;}
	void setMustard(double newMustard) {mustard = newMustard;}
};

class Truck{
private:
	vector <Sandwich> sandwichTruck;
public:
	void insertSandwich(const Sandwich& aSandwich) {sandwichTruck.push_back(aSandwich);}
	void checkBeforeLeaving() const;
	double getMustard(int i) const {return sandwichTruck[i].getMustard();}
};

Sandwich::Sandwich(int cheeseSlices, double mayoAmmount, int tomatoSlices, double mustardAmmount):bread(2){
	cheese = cheeseSlices;
	mayo = mayoAmmount;
	tomato = tomatoSlices;
	mustard = mustardAmmount;
}

void Sandwich::displaySandwich() const{
	cout << "Your Sandwich contains: \n";
	cout << "\tBread: " << bread << " slices of bread\n";
	cout << "\tCheese: " << cheese << " slices of cheese\n";
	cout << "\tMayo: " << mayo << " ounces of mayo\n";
	cout << "\tTomato: " << tomato << " tomato slices\n";
	cout << "\tMustard: " << mustard << " ounces of mustard\n";
}

void Truck::checkBeforeLeaving() const {
	for (const Sandwich& aSandwich : sandwichTruck) {
		aSandwich.displaySandwich();
	}
}	

int main(){
	Truck sandwichTruck;
	Sandwich customer1Sandwich;
	Sandwich customer2Sandwich;
	customer2Sandwich.setMustard(0);
	Sandwich customer3Sandwich;
	customer3Sandwich.setCheese(2);
	Sandwich customer4Sandwich;
	sandwichTruck.insertSandwich(customer1Sandwich);
	sandwichTruck.insertSandwich(customer2Sandwich);
	sandwichTruck.insertSandwich(customer3Sandwich);
	sandwichTruck.insertSandwich(customer4Sandwich);
	sandwichTruck.checkBeforeLeaving();
	cout << "Mustard Ammount: " << sandwichTruck.getMustard(1)<< endl;
}