/*
Q2. Publication Class — Constructor, Destructor, Update

Task:
Create a class Publication to represent a simple publication record.

Specifications:
Data Members => (string title, string author, int year)
Constructors => Parameterized constructor to initialize all data members
Destructor => Prints a message when a Publication object is destroyed

Member Functions:
void display() → Shows all publication details
void updateYear(int newYear) → Updates publication year

Main Requirements:
In main(), create two Publication objects
Display both
Update the year of one publication
Show updated data
Observe destructor messages
*/

#include <iostream>
using namespace std;

class Publication {
private:
    string title;
    string author;
    int year;

public:
    // Parameterized constructor
    Publication(string t, string a, int y) {
        title = t;
        author = a;
        year = y;
    }

    // Destructor
    ~Publication() {
        cout << "Publication \"" << title << "\" is being deleted.\n";
    }

    // Display publication
    void display() {
        cout << "Title: " << title 
             << "\nAuthor: " << author 
             << "\nYear: " << year << "\n\n";
    }

    void updateYear(int newYear) {
        year = newYear;
    }
};

int main() {
    Publication p1("OOP in C++", "Ali Ahmed", 2022);
    Publication p2("AI Basics", "Sara Khan", 2023);

    p1.display();
    p2.display();

    p2.updateYear(2024);
    cout << "After Updating Year:\n";
    p2.display();

    return 0;
}