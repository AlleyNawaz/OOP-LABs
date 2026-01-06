#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string title;
    string author;
    float price;

public:
    void SetData(string t, string a, float p)
    {
        title = t;
        author = a;
        price = p;
    }

    void ApplyDiscount(float percentage)
    {
        float discountAmount = (price * percentage) / 100;
        cout << "Discount Applied: " << discountAmount << " saved!" << endl;
        price -= discountAmount;
    }

    void ShowDetails()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
        cout << "---------------------" << endl;
    }
};

int main()
{
    Book b1, b2;

    b1.SetData("C++ Programming", "Bjarne Stroustrup", 1000);
    b2.SetData("Clean Code", "Robert C. Martin", 1500);

    cout << "Before Discount:" << endl;
    b1.ShowDetails();
    b2.ShowDetails();

    cout << "Applying Discounts..." << endl;
    b1.ApplyDiscount(10);
    b2.ApplyDiscount(20);

    cout << "After Discount:" << endl;
    b1.ShowDetails();
    b2.ShowDetails();

    return 0;
}