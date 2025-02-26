#include <iostream>
#include <vector>
#include <string>  
using namespace std;

class Book {
    private:
        string title;
        string author;
        string date;
        string genre;

    public:
        // Constructor
        Book(string title, string author, string date, string genre) {
            this->title = title;
            this->author = author;
            this->date = date;
            this->genre = genre;
        }

        ~Book() {} // Destructor

        void display() const {
            cout << "----------------------------" << endl;
            cout << "Book Title: " << title << endl;
            cout << "Book Author: " << author << endl;
            cout << "Book Release Date: " << date << endl;
            cout << "Book Genre: " << genre << endl; 
            cout << "----------------------------" << endl;
        }
};

int main() {
    vector<Book> books;
    int choice;
    string title;
    string author;
    string date;
    string genre;
    char addMore;

    do {
        cout << "\n1 - Add book, 2 - Display all books, 3 - Exit: ";
        cin >> choice;
        cin.ignore();  

        if (choice == 1) {
            do {
                cout << "\nEnter Book Title: ";
                getline(cin, title);

                cout << "Enter Book Author: ";
                getline(cin, author);

                cout << "Enter Book's Release Date: ";
                getline(cin, date);

                cout << "Enter Book's Genre: ";
                getline(cin, genre);

                books.push_back(Book(title, author, date, genre));
                cout << "\nBook is Added Successfully!\n";

                cout << "\nWant to add more books? (y/n): ";
                cin >> addMore;
                cin.ignore(); 

            } while (addMore == 'Y' || addMore == 'y');
        }
        else if (choice == 2) {
            if (books.empty()) {
                cout << "No available books.\n";
            } else {
                cout << "Book list: \n";
                for (const auto& book : books) {
                    book.display();
                }
            }
        }
        else if (choice == 3) {
            cout << "Exiting program.\n";
            break; 
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3); 

    return 0;
}