#include "class.h"
#include <iostream>

Book::Book() {
    // ���������� ������������ �� ���������
}

Book::~Book() {
    // ���������� �����������
}


vector<Book> availableBooks;
vector<Book> soldBooks;

void Book::addBook() {
    string title, author;
    double price;
    int quantity;

    cout << "Enter title: ";
    cin >> title;
    cout << "Enter author: ";
    cin >> author;
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter quantity: ";
    cin >> quantity;

    Book newBook;
    newBook.title = title;
    newBook.author = author;
    newBook.price = price;
    newBook.quantity = quantity;
    availableBooks.push_back(newBook);

    cout << "Book added successfully." << endl;
}

void Book::interface() {
    int choice;
    do {
        system("CLS");
        cout << "1. Add new book" << endl;
        cout << "2. Record book sale" << endl;
        cout << "3. Display available books" << endl;
        cout << "4. Display sold books" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                saleBook();
                break;
            case 3:
                bookList();
                break;
            case 4:
                saleList();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        system("pause");
    } while (choice != 5);
}

void Book::bookList() {
    cout << "Available Books:" << endl;
    for (int i = 0; i < availableBooks.size(); i++) {
        cout << availableBooks[i].title << " by " << availableBooks[i].author << " - $" << availableBooks[i].price << " (" << availableBooks[i].quantity << " available)" << endl;
    }
}

void Book::saleBook() {
    string title;
    int quantity;

    Book delBook;
    //delBook.title = title;
    //delBook.author = author;
    //delBook.price = price;
    //delBook.quantity = quantity;
    soldBooks.push_back(delBook);

    cout << "Enter title of the book sold: ";
    cin >> title;
    cout << "Enter quantity sold: ";
    cin >> quantity;
    cout << "Sale recorded successfully." << std::endl;

    for (int i = 0; i < availableBooks.size(); i++) {
        if (availableBooks[i].title == title) {
            availableBooks[i].quantity -= quantity;
            //soldBooks.push_back(availableBooks[i]);
            soldBooks[i].title = availableBooks[i].title;
            soldBooks[i].author = availableBooks[i].author;
            soldBooks[i].price = availableBooks[i].price;
            soldBooks[i].quantity += quantity;
            break;
        }
    }
}

void Book::saleList() {
    cout << "Sold Books:" << endl;
    for (int i = 0; i < soldBooks.size(); i++) {
        cout << soldBooks[i].title << " by " << soldBooks[i].author << " - $" << soldBooks[i].price << " (" << soldBooks[i].quantity << " sold)" << endl;
    }
}


