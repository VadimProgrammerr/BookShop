#include "class.h"
#include <iostream>

Book::Book() {

}

Book::~Book() {

}


vector<Book> availableBooks;
//vector<Book> soldBooks;

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
