// COMSC-210 | Lab 15 | Annie Morales
// IDE used: Visual Studio Code

#include <fstream> // For file operations
#include <iostream> // For input & output
#include <iomanip>
#include <string> // For string use
#include <vector> // For vector use
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
    vector<string> records; // Vector to store movie info
    
    // Reads movie info from a file
    ifstream fin;
    fin.open("movieinfo.txt");

    // Checks if file opened successfully
    if (!fin.good()) throw "I/O error";
    
    // Reads movie info from the file into the vector
    string tempMovie;
    while (fin >> tempMovie)
    {
        records.push_back(tempMovie);
    }
    
    fin.close(); // Closes the file

    //Displays the movie info
    cout << endl;

    // Reopen the file to read movie info line by line
    fin.open("movieinfo.txt");
    if (!fin.good()) throw "I/O error";

    while (!fin.eof())
    {
        Movie m; // Movie object
        string screenwriter, title;
        int yearReleased;

        // Read screenwriter
        if (!getline(fin, screenwriter)) break;
        m.setSW(screenwriter);

        // Read year released
        string yearStr;
        if (!getline(fin, yearStr)) break;
        yearReleased = stoi(yearStr);
        m.setYrReleased(yearReleased);

        // Read title
        if (!getline(fin, title)) break;
        m.setTitle(title);

        // Print movie info
        m.print();
        cout << endl;
    }

    fin.close();

    cout << endl;
    return 0;
}