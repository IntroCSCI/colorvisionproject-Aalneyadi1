//Author:  Aalneyadi1

#include <iostream>
#include <fstream>
#include <algorithm>
#include <array>
#include <random>
#include <chrono>
#include <string>
using namespace std;

const string BB = u8"\033[2J\033[1;1H";


//This function is used to save total number of colors from palette to the text file
//This functions recieve pass-by-value and pass-by-reference params
void saveNumber(string name, int &totalNumber, array<string,5> clrpalt)
{
    fstream reader;

    //To save total number of colour from palette to the text file
    reader.open(name, ios::out);
    if (reader.is_open()) {
        cout << "File has been created successfully!\n";
        // To save colour from palette and save in the text file.
        if (totalNumber >= 5)
        {
            cout << "Number are Bigger than Here";
        }
        else
        {
            for (int i = 1; i <= totalNumber; i++) {
                reader << clrpalt[i] << endl;
            }
        }
    }
    else {
        cout << "File could not created!";
    }
    reader.close();
}


//This function is used to Output colors in file created.
//This functions recieve pass-by-value and pass-by-reference params
void Display(string name,int &totalNumber,string &color)
{
    fstream reader;

    //Output the colors in the file created
    reader.open(name, ios::in);
    if (reader.is_open()) {
        cout << BB;
        cout << name << " contains  " << totalNumber << " colors \n";
        while (reader.eof() != true) {
            getline(reader, color);
            cout << color << endl;
        }
    }
}

int main()
{
    int totalColor;
    string fName;
    string name;
    string color;
    fstream reader;
    array<string, 5> clrPalt{ "#0000CF","#FFFFFF",  "#E69F00", "#56B4E9", "#009E73" };

    // To shuffle the colour and use random number num with the help of the system clock
    int num = chrono::system_clock::now().time_since_epoch().count();
    shuffle(clrPalt.begin(), clrPalt.end(), default_random_engine(num));

    cout << "Please enter the file name to save color palette: \n";
    std::getline(cin, name);
    fName = name + ".txt"; //Save name as txt file type

    cout << "How many colours do you need?  \n";
    cin >> totalColor;

    saveNumber(fName, totalColor, clrPalt);

    Display(fName, totalColor, color);


    return 0;
}
