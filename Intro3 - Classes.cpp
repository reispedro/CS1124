#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


class Computer{
private:
	double procSpeed;
	string os;
	double screenSize;
	double memory;
public:
	Computer(); // Default Constructor
				// Automaticaly called upon instantiation of the object.
	Computer(string newOS);
	string getOS() const; // Guaranteed that the function will not change the object!
	void reformat(string newOS);
	void setMemory(double newMem);
};

class Sauce{
private:
	string name;
public:
	//Sauce(string newName){ name = newName; }
	Sauce(string newName) : name(newName){} // Member initialization list
	string getSauce() const { return name; }
};

class Pizza{
private:
	bool isCircle;
	int size;
	double price;
	vector<string> toppings;
	Sauce sauce;
	int slices;
public:
	Pizza(string  sauceName = "Marinara", bool circle = true) : sauce(sauceName){
		isCircle = circle;
		price = 12;
		toppings.push_back("cheese");
		slices = 1;
	}
	void sellIt(double money);
	void eatIt() const;
	void addToppings(string newTopping){ toppings.push_back(newTopping); }
	void sliceIt(int numOfSlices);
	void display()const;
	void print(ostream& outs = cout)const;
};

void Pizza::print(ostream& outs)const{
	outs << "Is Circle: " << ((isCircle) ? "Yes" : "No") << endl;
	outs << "Size: " << size << endl;
	outs << "Price: " << price << endl;
	outs << "Toppings: ";
	for (string s : toppings)
		outs << s << ",";
	outs << endl;
	outs << "Sauce" << sauce.getSauce() << endl;
	outs << "Slices: " << slices << endl;
}

void Pizza::display() const{
	cout << "Is Circle: " << ((isCircle) ? "Yes" : "No") << endl;
	cout << "Size: " << size << endl;
	cout << "Price: " << price << endl;
	cout << "Toppings: ";
	for (string s : toppings)
		cout << s << ",";
	cout << endl;
	cout << "Sauce: " << sauce.getSauce() << endl;
	cout << "Slices: " << slices << endl;
}

void Pizza::sliceIt(int numOfSlices){
	slices = numOfSlices;
}

void Pizza::eatIt()const{
	cout << "Yumm." << endl;
}

void Pizza::sellIt(double money){
	if(money < (price/slices) && slices > 0){
		cout << "Go away, not enough money for my " << slices << " slice(s) " << sauce.getSauce() << endl;
	}
	else{
		slices--;
		cout << "Sold one slice of " << sauce.getSauce() << " pizza" << endl;
	}
}

Computer::Computer(){
	procSpeed = 2000;
	os = "Windows Something";
	screenSize = 17;
	memory = 4;
}

Computer::Computer(string newOS){
	procSpeed = 2000;
	os = newOS;
	screenSize = 17;
	memory = 4;
}

string Computer::getOS() const{
	return os;
}

void Computer::reformat(string newOS){
	os = newOS;
}

void Computer::setMemory(double newMem){
	memory = newMem;
	procSpeed = memory * 1000;
}

void func(const Computer& c){
	cout << "OS:" << c.getOS() << endl;
}

int main(){
	Computer c; // Default Constructor
	c.reformat("Windows 10");
	func(c);
	Computer m("Mac OS"); // One-argument constructor
	func(m);

	Pizza nyPizza;
	Pizza notAPizza("Alfredo");

	nyPizza.sliceIt(8);
	nyPizza.sellIt(2);
	nyPizza.eatIt();

	notAPizza.display();
	ofstream outfile("outfile.txt");
	nyPizza.print(outfile);
	nyPizza.print();

}