Case Study: Library Management System

Problem Description
A library management system manages resources such as Books, Journals, and DVDs. Each resource has common attributes (e.g., title, ID, and availability) and specific attributes 
(e.g., author for books, volume for journals, and runtime for DVDs).

The system needs:
A base class for shared attributes.
Derived classes for resource-specific details.
A method to display details for all resources.

Class Design

Base Class: LibraryResource

Common attributes: title, resourceID, isAvailable.
Common methods: display() to show details and borrowResource() to change availability.

Derived Classes:
Book: Includes author and genre.
Journal: Includes volume and issue.
DVD: Includes runtime (in minutes) and rating.



Case Study Code:
#include <iostream>
using namespace std;

// -------------------- Base Class --------------------
class LibraryResource {
protected:
    string title;
    int resourceID;
    bool isAvailable;

public:
    LibraryResource(string t, int id) {
        title = t;
        resourceID = id;
        isAvailable = true;
    }

    void borrowResource() {
        if(isAvailable) {
            isAvailable = false;
            cout << title << " has been borrowed.\n";
        } else {
            cout << title << " is not available.\n";
        }
    }

    void display() {
        cout << "Title: " << title << endl;
        cout << "Resource ID: " << resourceID << endl;
        cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << endl;
    }
};

// -------------------- Single Inheritance --------------------
class Book : public LibraryResource {
protected:
    string author, genre;
public:
    Book(string t, int id, string a, string g)
        : LibraryResource(t, id), author(a), genre(g) {}

    void display() {
        LibraryResource::display();
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl << endl;
    }
};

class Journal : public LibraryResource {
private:
    int volume, issue;
public:
    Journal(string t, int id, int v, int i)
        : LibraryResource(t, id), volume(v), issue(i) {}

    void display() {
        LibraryResource::display();
        cout << "Volume: " << volume << endl;
        cout << "Issue: " << issue << endl << endl;
    }
};

class DVD : public LibraryResource {
private:
    int runtime;
    string rating;
public:
    DVD(string t, int id, int r, string rate)
        : LibraryResource(t, id), runtime(r), rating(rate) {}

    void display() {
        LibraryResource::display();
        cout << "Runtime: " << runtime << " minutes" << endl;
        cout << "Rating: " << rating << endl << endl;
    }
};

// -------------------- Multilevel Inheritance --------------------
class EBook : public Book {
private:
    double fileSize; // in MB
public:
    EBook(string t, int id, string a, string g, double fs)
        : Book(t, id, a, g), fileSize(fs) {}

    void display() {
        Book::display();
        cout << "File Size: " << fileSize << " MB\n\n";
    }
};

// -------------------- Multiple Inheritance --------------------
class AudioFeatures {
protected:
    int duration; // in minutes
public:
    AudioFeatures(int d) : duration(d) {}
};

class AudioBook : public LibraryResource, public AudioFeatures {
private:
    string narrator;
public:
    AudioBook(string t, int id, int d, string n)
        : LibraryResource(t,id), AudioFeatures(d), narrator(n) {}

    void display() {
        LibraryResource::display();
        cout << "Narrator: " << narrator << endl;
        cout << "Duration: " << duration << " minutes\n\n";
    }
};

// -------------------- Main --------------------
int main() {
    Book b1("OOP Concepts", 101, "Ali Raza", "Computer Science");
    Journal j1("Tech Journal", 202, 5, 3);
    DVD d1("Inception Movie", 303, 148, "PG-13");
    EBook e1("AI Revolution", 404, "John Doe", "Tech", 12.5);
    AudioBook a1("Mindset", 505, 480, "Dr. Carol");

    b1.display();
    j1.display();
    d1.display();
    e1.display();
    a1.display();

    b1.borrowResource();
    b1.borrowResource(); // try borrowing again

    return 0;
}