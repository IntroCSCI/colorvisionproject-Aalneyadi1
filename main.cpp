//Author:  Aalneyadi1
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//Here as we know class is a Blue Print of things here 
//We define a color class which has constructor destructor and some other methods.
class Colours {

//Declaration of private members of the class
private:
	string str;
//Declaration of public members of the class
public:
	//Declare some characters 
	char red, green, blue;
	//Define constructor of the classS
	Colours(string clrStr) {
		this->str = clrStr;
		//takes some validations if parameters has some values less then 6 lengths
		if (this->str.length() < 6) {
			string clrs;
			clrs += this->str[0];
			clrs += this->str[0];
			clrs += this->str[1];
			clrs += this->str[1];
			clrs += this->str[2];
			clrs += this->str[2];
			this->str = clrs;
		}
		//basically stoi method is used for conversion here wo use stoi method to convert string into character
		this->red = (char)stoi(this->str.substr(0, 2), nullptr, 16);
		this->green = (char)stoi(this->str.substr(2, 2), nullptr, 16);
		this->blue = (char)stoi(this->str.substr(4, 2), nullptr, 16);

		this->str = this->str.substr(0, 6);
	}

	//this is a destructor
	~Colours() {}

	//  this method is used to return string only every thing is converted into string through this mehtod
	string toString() {

		return this->str;
	}

	//Definition of assignment operator
	bool operator == (const Colours& color) {

		return this->red == color.red
			&& this->green == color.green &&
			this->blue == color.blue;
	}


};
//Declare prototype of Unique method
bool appendUnique(Colours* c,vector<Colours>& tbl);


//Main method
int main() {
	//Declaration to some variables or objects

	string fileName;
	ifstream file;
	string color;
	vector<Colours> colorTable;
	char ch;
	string keyTable;
	Colours* c;

	//Declare some color names
	const char* clrName[] = {
	"AliceBlue",
	"AntiqueWhite",
	"Aqua",
	"Aquamarine",
	"Azure",
	"Beige",
	"Bisque",
	"fuchsia",
	"Black",
	"BlanchedAlmond",
	"Blue",
	"BlueViolet",
	"Brown",
	};


	//Also declare some color values
	const char* clrValue[] = {
		"F0F8FF",
		"FAEBD7",
		"00FFFF",
		"7FFFD4",
		"F0FFFF",
		"F5F5DC",
		"FFE4C4",
		"0000FF",
		"000000",
		"FFEBCD",
		"8A2BE2",
		"A52A2A",
		"DEB887",
		"5F9EA0",
		"7FFF00",
		"FF7F50",
		"6495ED",
		"FFF8DC",
		"DC143C",
		"00FFFF",
		"006400",
		"D2691E"
	};
	//This is loop to open files 
	while (true)
	{
		//this condition is being true while file is not open
		if (!file.is_open())
		{
			cout << "Please enter file name to analyze: ";
			getline(cin, fileName);

			file.open(fileName, ifstream::in);
		}
		else
		{
			break;
		}
	}

	//Print how many clrs in the palettee
	cout << endl << "The number of colors in the palete are " << endl;
	//This is for read and some validations to file
	while ((ch = file.get()) != EOF) {

		if (ch == ' ' || ch == '\n') {
			if (keyTable.length() > 0) {

				if (keyTable[0] == '*') {

					c = new Colours(keyTable.substr(1));
					if (!appendUnique(c,colorTable)) {
						delete c;
					}
					else
						cout << c->toString() << endl;
				}
				else {

					for (int i = 0; i < 16; i++) {
						if (keyTable == clrName[i]) {
							c = new Colours(clrValue[i]);
							if (!appendUnique(c,colorTable)) {
								delete c;
							}
							else
								cout << c->toString() << endl;
							break;
						}
					}
				}

				keyTable = "";
			}
		}
		else {
			keyTable += ch;
		}
	}
	//FInal results are
	cout<<"Here is the final result from file."<<endl
	 << "There are " << colorTable.size() << " unique colors in the selected file." << endl;

	return 0;
}

//this method is define for add unique clrs in vector
bool appendUnique(Colours* c,vector<Colours>& tbl) {
	int counter = 0;

	for (size_t i = 0; i < tbl.size(); i++) {

		if (*c == tbl[i]) {
			counter++;
			break;
		}
	}
	if (!counter) {

		tbl.push_back(*c);
		return true;

	}
	else {

		return false;
	}
}
