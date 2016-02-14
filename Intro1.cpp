#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int var; //DON'T DO THIS!!!!!!!!!

//Single line Comment
/*	Multi
	Line
	Comment
*/
void sayHello();  //Prototype

void sayHello(){
	cout << "Hello world!" << endl;
}

int getNumber(){
	int input;
	cout << "Gimme a number: ";
	cin >> input;
	return input;
}
int getNumberInRange(int start, int end){
	int number;
	do{
		number = getNumber();
	} while (number<start || number>end);
	return number;
}

struct Date{
	int day;
	int month;
	int year;
};
struct Student{
	string name;
	string id;
	vector<double> exams;
	vector<double> homework;
};
struct Course{
	string name;
	string number;
	int credits;
	string room;
	vector<Student> students;
};

void printDate(Date d){
	cout << d.month << "/" << d.day << "/" << d.year;
}
double printCourseAverage2(Course c){
	double sum = 0;
	int quantity = 0;
	for (Student s : c.students){
		for (double d : s.exams){
			quantity++;
			sum += d;
		}
	}
	cout << "The average for course " << c.name << " is "
		<< sum / quantity << endl;
}
double printCourseAverage(Course c){
	double sum = 0;
	int quantity=0;
	for (int i = 0; i < c.students.size(); i++){
		Student s = c.students[i];
		for (int j = 0; j < s.exams.size(); j++){
			quantity++;
			sum += s.exams[j];
		}
	}
	cout << "The average for course " << c.name << " is "
		<< sum / quantity << endl;
}

int main() {
	Course cs1124;
	cs1124.name = "Object Oriented Programming";
	cs1124.number = "1124";
	cs1124.credits = 4;
	cs1124.room = "RH707";

	Student tempStudent;
	tempStudent.name = "John Doe";
	tempStudent.id = "42";
	tempStudent.exams.push_back(100);
	tempStudent.exams.push_back(50);
	cs1124.students.push_back(tempStudent);

	tempStudent.exams.clear();
	tempStudent.name = "Jane Doe";
	tempStudent.id = "43";
	tempStudent.exams.push_back(100);
	tempStudent.exams.push_back(99);
	cs1124.students.push_back(tempStudent);


	Date bday;
	bday.day = 1;
	bday.month = 2;
	bday.year = 2016;
	printDate(bday);
	sayHello();
	Date copyofBday = bday;

	ifstream inFile;
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
	/*
	//How to read in, element by element
	int input;
	while (inFile >> input){
		cout << "Got this integer from the file: " << input << endl;
	}
	*/
	//How to read in, line by line
	string line;
	while (getline(inFile, line)){
		cout << "Got this line from the file: " << line << endl;
	}

	const double TAX_RATE = 0.08875;
	cout << "Hello world!" << endl;
	int x;
	int camelCaseVariable;
	x = 5.5;
	cout << "The value of x is: " << x << endl;
	double d;
	d = 5 / 2;
	cout << "The value of d is: " << d << endl;

	if (x == 0){
		cout << "It's equal to zero" << endl;
	}
	else if (x > 0){
		cout << "It's positive!" << endl;
	}
	else{
		cout << "It's negative!" << endl;
	}
	if (x > 100)
		if (x > 1000)
			cout << "A" << endl;
		else
			cout << "B" << endl;
	cout << "****************" << endl;
	int oneMore;

	x = 5;
	cout << "X = 5, doing x++ ************************" << endl;
	oneMore = x++;
	cout << "x=" << x << "\toneMore=" << oneMore << endl;

	x = 5;
	cout << "X = 5, doing ++x ************************" << endl;
	oneMore = ++x;
	cout << "x=" << x << "\toneMore=" << oneMore << endl;

	vector<int> v;
	v.push_back(100); //adds 100 to the list
	cout << "size=" << v.size() << endl; //prints 1
	cout << v[0] << endl; //prints 100
	v.pop_back();
	v.clear();

	cout << "*******************" << endl;
	for (int i = 0; i < 100; i++)
		v.push_back(i);
	for (int i = v.size() - 1; v.size() > 0; i--){
		cout << v[i] << endl;
		v.pop_back();
	}

	int donuts;
	double gallons;
	cout << "How many donuts? ";
	cin >> donuts;
	cout << "How many gallons of milk? ";
	cin >> gallons;
	cout << "Donuts=" << donuts << "\tGallons=" << gallons << endl;
	if (gallons > donuts)
		cout << "Your milk to donut ratio is bad." << endl;
	else if (donuts < 12)
		cout << "Come on, you REALLY want a dozen, right?"<<endl;
	else
		cout << "OK." << endl;

	
}













