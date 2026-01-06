/*
Create a C++ program that models a Library Management System, where you manage information about books such as Title, Author, ISBN, and Availability.

Instructions:
1. Create a class Book with the following private members:
string title
string author
string ISBN
bool isAvailable
2. Implement public getter and setter methods for each private member:
Keep all data members private.
Make all getter and setter methods public.
3. In main():
Create an object of the Book class.
Set the values of the attributes using setter methods.
Display the values of the attributes using getter methods.
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
        ISBN = i;
    }

    void setAvailability(bool av) {
        isAvailable = av;
    }

    // Getter methods
    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    string getISBN() {
        return ISBN;
    }

    bool getAvailability() {
        return isAvailable;
    }
};

int main() {
    Book b;

    // Setting using setters
    b.setTitle("Object Oriented Programming");
    b.setAuthor("Ali Khan");
    b.setISBN("978-12345");
    b.setAvailability(true);

    // Display using getters
    cout << "Book Title: " << b.getTitle() << endl;
    cout << "Author: " << b.getAuthor() << endl;
    cout << "ISBN: " << b.getISBN() << endl;
    cout << "Availability: " 
         << (b.getAvailability() ? "Available" : "Not Available") << endl;

    return 0;
}