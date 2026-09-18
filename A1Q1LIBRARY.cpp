#include <iostream>
#include <string>
using namespace std;

class LibraryBook {
private:
    string title;
    string author;
    bool issued;

public:
    LibraryBook(string t, string a) {
        title = t;
        author = a;
        issued = false;
    }

    void issueBook() {
        if (!issued) {
            issued = true;
            cout << "Book issued successfully." << endl;
        } else {
            cout << "Book is already issued." << endl;
        }
    }

    void returnBook() {
        if (issued) {
            issued = false;
            cout << "Book returned successfully." << endl;
        } else {
            cout << "Book was not issued." << endl;
        }
    }

    void display() {
        cout << "\n----- Book Details -----" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Status: "
             << (issued ? "Issued" : "Available") << endl;
    }
};

int main() {
    LibraryBook book("C++ Programming", "Bjarne Stroustrup");

    book.display();
    book.issueBook();
    book.display();
    book.returnBook();
    book.display();

    return 0;
}