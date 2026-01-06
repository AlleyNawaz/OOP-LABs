/*
a) Modify the Book class to prevent ISBN from being set as an empty string.
If the user tries to set an empty ISBN, assign a default value like "UNKNOWN".

b) Add a method => void borrowBook();
Changes isAvailable to false if the book is available
Prints "Book borrowed successfully" if available
Else prints "Book is already borrowed."

c) Add a method => void returnBook();
Changes isAvailable to true
Prints "Book returned successfully"

d) Add a method => void printBookDetails();
Displays all details of the book in a formatted way

e) Allow multiple objects of the Book class to represent multiple books in the library system and demonstrate borrowing and returning functionalities.
*/
#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    bool isAvailable;

public:
    // Setter methods
    void setTitle(string t) {
        title = t;
    }

    void setAuthor(string a) {
        author = a;
    }

    void setISBN(string i) {
        if(i == "") {
            ISBN = "UNKNOWN";
        } else {
            ISBN = i;
        }
    }

    void setAvailability(bool av) {
        isAvailable = av;
    }

    // Getter methods
    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getISBN() { return ISBN; }
    bool getAvailability() { return isAvailable; }

    // Borrow Book
    void borrowBook() {
        if(isAvailable) {
            isAvailable = false;
            cout << "Book borrowed successfully!" << endl;
        } else {
            cout << "Book is already borrowed." << endl;
        }
    }

    // Return Book
    void returnBook() {
        isAvailable = true;
        cout << "Book returned successfully!" << endl;
    }

    // Print Book Details
    void printBookDetails() {
        cout << "\n----- Book Details -----" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Availability: " 
             << (isAvailable ? "Available" : "Not Available") << endl;
        cout << "------------------------\n";
    }
};

int main() {
    Book b1, b2;

    b1.setTitle("OOP in C++");
    b1.setAuthor("Ali Ahmed");
    b1.setISBN("12345");
    b1.setAvailability(true);

    b2.setTitle("Data Structures");
    b2.setAuthor("Sara Ahmed");
    b2.setISBN(""); // empty → set to UNKNOWN
    b2.setAvailability(true);

    b1.printBookDetails();
    b2.printBookDetails();

    cout << endl << "--- Borrowing Book 1 ---" << endl;
    b1.borrowBook();
    b1.printBookDetails();

    cout << endl << "--- Borrowing Book 1 Again ---" << endl;
    b1.borrowBook();

    cout << endl << "--- Returning Book 1 ---" << endl;
    b1.returnBook();
    b1.printBookDetails();

    return 0;
}