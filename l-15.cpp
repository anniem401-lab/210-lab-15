// COMSC-210 | Lab 15 | Annie Morales
// IDE used: Visual Studio Code

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int W15 = 15;

class Movie
{
private:
	string screenwriter;
    int yearReleased;
    string title;

public:
// Getters and Setters
string getScreenwriter()        { return screenwriter; }
void setSW(string sw)           { screenwriter = sw; }

int getYearReleased()           { return yearReleased; }
void setYrReleased(int YrR)     { yearReleased = YrR; }

string getTitle()               { return title; }
void setTitle(string t)         { title = t;}

// Print method
void print()
{
    cout << setw(W15) << "Screenwriter: " << screenwriter << endl;
    cout << setw(W15) << "Year released: " << yearReleased << endl;
    cout << setw(W15) << "Title: " << title << endl;
}
};

void print(Movie);

int main()
{
	// code here
	return 0;
}