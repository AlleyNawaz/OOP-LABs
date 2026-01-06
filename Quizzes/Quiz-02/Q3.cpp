/* 
Q3. Library Class — Constructors, Destructor, Book Issuing

Task:
Design a Library class to model a small library’s information and issued books.

Specifications:
Data Members => (string libraryName, int totalBooks, int issuedBooks)

Constructors:
Default constructor → sets default values
Parameterized constructor → initialize all values

Destructor:
Display a message when the Library object is deleted

Member Functions:
void issueBook(int n)
Issues n books if available, otherwise show message
void displayStatus()
Show:
Library name
Total books
Issued books
Remaining books

Additional Theory Question:
If a Library object is created inside a function:

Explain the order of constructor & destructor execution when:
1. The function is called
2. The function ends
3. Why improper initialization or destruction can cause logical errors
*/

#include <iostream>
using namespace std;

class Library {
private:
    string libraryName;
    int totalBooks;
    int issuedBooks;

public:
    // Default constructor
    Library() {
        libraryName = "Unknown Library";
        totalBooks = 0;
        issuedBooks = 0;
    }

    // Parameterized constructor
    Library(string name, int total, int issued) {
        libraryName = name;
        totalBooks = total;
        issuedBooks = issued;
    }

    // Destructor
    ~Library() {
        cout << "Library record \"" << libraryName << "\" is being deleted.\n";
    }

    void issueBook(int n) {
        if (issuedBooks + n <= totalBooks) {
            issuedBooks += n;
            cout << n << " book(s) issued successfully.\n";
        } else {
            cout << "Not enough books available!\n";
        }
    }

    void displayStatus() {
        cout << "\nLibrary Name: " << libraryName;
        cout << "\nTotal Books: " << totalBooks;
        cout << "\nIssued Books: " << issuedBooks;
        cout << "\nAvailable Books: " << totalBooks - issuedBooks;
        cout << "\n";
    }
};

// Function to test constructor/destructor behavior
void testLibrary() {
    Library lib("City Library", 100, 10);
    lib.displayStatus();
    lib.issueBook(5);
    lib.displayStatus();
}

int main() {
    testLibrary();
    return 0;
}