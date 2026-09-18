#include <iostream>
#include <string>

using namespace std;

const int MAX_BOOKS = 50;
const int MAX_USERS = 50;
const int MAX_TX = 100;

class User {
protected:
    string name;
    string userID;

public:
    User() : name(""), userID("") {}
    User(string n, string id) : name(n), userID(id) {}
    virtual ~User() {}

    string getUserID() const { return userID; }
    string getName() const { return name; }
    
    virtual void displayRole() const = 0; 
};

class Student : public User {
private:
    string rollNumber;

public:
    Student() : User(), rollNumber("") {}
    Student(string n, string id, string roll) : User(n, id), rollNumber(roll) {}

    void displayRole() const override {
        cout << "Student | ID: " << userID << " | Name: " << name << " | Roll No: " << rollNumber << endl;
    }
};

class Book {
private:
    string bookID;
    string title;
    string author;
    bool isAvailable;

public:
    Book() : bookID(""), title(""), author(""), isAvailable(true) {}
    Book(string id, string t, string a) : bookID(id), title(t), author(a), isAvailable(true) {}

    string getBookID() const { return bookID; }
    string getTitle() const { return title; }
    bool checkAvailability() const { return isAvailable; }

    void setAvailability(bool status) { isAvailable = status; }

    void displayBookDetails() const {
        cout << "[ID: " << bookID << "] \"" << title << "\" by " << author 
             << " | Status: " << (isAvailable ? "Available" : "Borrowed") << endl;
    }
};

class Transaction {
private:
    string transactionID;
    string userID;
    string bookID;
    string issueDate;
    bool isCompleted;

public:
    Transaction() : transactionID(""), userID(""), bookID(""), issueDate(""), isCompleted(false) {}
    Transaction(string tID, string uID, string bID, string date) 
        : transactionID(tID), userID(uID), bookID(bID), issueDate(date), isCompleted(false) {}

    string getBookID() const { return bookID; }
    string getUserID() const { return userID; }
    bool getStatus() const { return isCompleted; }
    
    void completeTransaction() { isCompleted = true; }

    void displayTransaction() const {
        cout << "TxID: " << transactionID << " | User: " << userID 
             << " | Book: " << bookID << " | Date: " << issueDate 
             << " | Status: " << (isCompleted ? "Returned" : "Active") << endl;
    }
};

class Library {
private:
    Book books[MAX_BOOKS];
    User* users[MAX_USERS]; 
    Transaction transactions[MAX_TX];
    
    int bookCount;
    int userCount;
    int txCount;
    int txCounterId; 

public:
    Library() : bookCount(0), userCount(0), txCount(0), txCounterId(1000) {
        for (int i = 0; i < MAX_USERS; i++) {
            users[i] = nullptr;
        }
    }

    ~Library() {
        for (int i = 0; i < userCount; i++) {
            delete users[i];
        }
    }

    void addBook(string id, string title, string author) {
        if (bookCount >= MAX_BOOKS) {
            cout << "Error: Library catalog is full!\n";
            return;
        }
        books[bookCount] = Book(id, title, author);
        bookCount++;
        cout << "Success: Book added successfully.\n";
    }

    void registerStudent(string name, string id, string roll) {
        if (userCount >= MAX_USERS) {
            cout << "Error: User database is full!\n";
            return;
        }
        users[userCount] = new Student(name, id, roll);
        userCount++;
        cout << "Success: Student registered successfully.\n";
    }

    void viewBooks() const {
        cout << "\n--- Library Catalog ---\n";
        if (bookCount == 0) cout << "No books available.\n";
        for (int i = 0; i < bookCount; i++) {
            books[i].displayBookDetails();
        }
    }

    void viewUsers() const {
        cout << "\n--- Registered Users ---\n";
        if (userCount == 0) cout << "No users registered.\n";
        for (int i = 0; i < userCount; i++) {
            if (users[i] != nullptr) {
                users[i]->displayRole();
            }
        }
    }

    void issueBook(string userID, string bookID, string date) {
        User* activeUser = nullptr;
        Book* activeBook = nullptr;

        for (int i = 0; i < userCount; i++) {
            if (users[i]->getUserID() == userID) {
                activeUser = users[i];
                break;
            }
        }

        for (int i = 0; i < bookCount; i++) {
            if (books[i].getBookID() == bookID) {
                activeBook = &books[i];
                break;
            }
        }

        if (!activeUser) {
            cout << "Error: User ID not found.\n";
            return;
        }
        if (!activeBook) {
            cout << "Error: Book ID not found.\n";
            return;
        }
        if (!activeBook->checkAvailability()) {
            cout << "Error: Book is already borrowed.\n";
            return;
        }
        if (txCount >= MAX_TX) {
            cout << "Error: Transaction log is full!\n";
            return;
        }

        activeBook->setAvailability(false);
        txCounterId++;
        
        string txID = "TX" + string(1, '0' + (txCounterId/1000)%10) 
                           + string(1, '0' + (txCounterId/100)%10)
                           + string(1, '0' + (txCounterId/10)%10)
                           + string(1, '0' + txCounterId%10);

        transactions[txCount] = Transaction(txID, userID, bookID, date);
        txCount++;
        cout << "Success: Book issued! Transaction ID: " << txID << "\n";
    }

    void returnBook(string userID, string bookID) {
        for (int i = 0; i < txCount; i++) {
            if (transactions[i].getUserID() == userID && transactions[i].getBookID() == bookID && !transactions[i].getStatus()) {
                transactions[i].completeTransaction();
                
                for (int j = 0; j < bookCount; j++) {
                    if (books[j].getBookID() == bookID) {
                        books[j].setAvailability(true);
                        break;
                    }
                }
                cout << "Success: Book returned successfully.\n";
                return;
            }
        }
        cout << "Error: No active tracking entry found for this matching User and Book.\n";
    }

    void viewTransactions() const {
        cout << "\n--- Transaction History ---\n";
        if (txCount == 0) cout << "No history found.\n";
        for (int i = 0; i < txCount; i++) {
            transactions[i].displayTransaction();
        }
    }
};

int main() {
    Library centralLibrary;
    int choice;

    centralLibrary.addBook("B01", "The C++ Programming", "Bjarne S.");
    centralLibrary.addBook("B02", "Effective Modern C++", "Scott M.");
    centralLibrary.registerStudent("Alice", "U101", "R-21");
    centralLibrary.registerStudent("Bob", "U102", "R-45");

    do {
        cout << "\n===============================\n";
        cout << "   LIBRARY MANAGEMENT SYSTEM   \n";
        cout << "===============================\n";
        cout << "1. Add a New Book\n";
        cout << "2. Register a New Student\n";
        cout << "3. Display All Books\n";
        cout << "4. Display All Users\n";
        cout << "5. Issue a Book\n";
        cout << "6. Return a Book\n";
        cout << "7. View Transaction History\n";
        cout << "8. Exit Menu\n";
        cout << "Enter your selection (1-8): ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid dynamic input type! Try again.\n";
            continue;
        }

        cin.ignore(10000, '\n'); 

        switch (choice) {
            case 1: {
                string id, title, author;
                cout << "Enter Book ID: "; getline(cin, id);
                cout << "Enter Title: "; getline(cin, title);
                cout << "Enter Author: "; getline(cin, author);
                centralLibrary.addBook(id, title, author);
                break;
            }
            case 2: {
                string name, id, roll;
                cout << "Enter Student Name: "; getline(cin, name);
                cout << "Enter User ID: "; getline(cin, id);
                cout << "Enter Roll Number: "; getline(cin, roll);
                centralLibrary.registerStudent(name, id, roll);
                break;
            }
            case 3:
                centralLibrary.viewBooks();
                break;
            case 4:
                centralLibrary.viewUsers();
                break;
            case 5: {
                string uID, bID, date;
                cout << "Enter User ID: "; getline(cin, uID);
                cout << "Enter Book ID: "; getline(cin, bID);
                cout << "Enter Date (DD-MM-YYYY): "; getline(cin, date);
                centralLibrary.issueBook(uID, bID, date);
                break;
            }
            case 6: {
                string uID, bID;
                cout << "Enter User ID: "; getline(cin, uID);
                cout << "Enter Book ID: "; getline(cin, bID);
                centralLibrary.returnBook(uID, bID);
                break;
            }
            case 7:
                centralLibrary.viewTransactions();
                break;
            case 8:
                cout << "Exiting system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please select an option between 1 and 8.\n";
        }
    } while (choice != 8);

    return 0;
}