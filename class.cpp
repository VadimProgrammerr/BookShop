#include "class.h"
#include <iostream>
#include <string>

Book::Book() {
    // реализация конструктора по умолчанию
}

Book::~Book() {
    // реализация деструктора
}


vector<Book> availableBooks;
vector<Book> soldBooks;


void Book::addBook() {
    string title, author;
    double buyprice,sellprice;
    int quantity,g;
    bool f=false;

    cout << "Enter title: ";
    cin >> title;
    cout << "Enter author: ";
    cin >> author;
    for (int i = 0; i < availableBooks.size(); i++) {
        if(title==availableBooks[i].title && author==availableBooks[i].author)
        {
            f=true;
            g=i;
        }
    }
    if(f==true)
    {
        cout << "Enter quantity: ";
        cin >> quantity;
        availableBooks[g].quantity+=quantity;
    }
    else
    {
    cout << "Enter buyprice: ";
    cin >> buyprice;
    cout << "Enter sellprice: ";
    cin >> sellprice;
    cout << "Enter quantity: ";
    cin >> quantity;

    Book newBook;
    newBook.title = title;
    newBook.author = author;
    newBook.buyprice = buyprice;
    newBook.sellprice = sellprice;
    newBook.quantity = quantity;
    availableBooks.push_back(newBook);
    }
    cout << "Book added successfully." << endl;
}

void Book::interface() {
    int choice;
    do {
        system("CLS");
        cout << "1. Add new book(buy)" << endl;
        cout << "2. Record book sale" << endl;
        cout << "3. Display available books" << endl;
        cout << "4. Display sold books" << endl;
        cout << "5. Profit" << endl;
        cout << "6. Exit" << endl;
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
                profit();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        system("pause");
    } while (choice != 6);
}

void Book::bookList() {
    cout << "Available Books:" << endl;
    for (int i = 0; i < availableBooks.size(); i++) {
        cout << availableBooks[i].title << " by " << availableBooks[i].author << " - $" << availableBooks[i].sellprice << " (" << availableBooks[i].quantity << " available)" << endl;
    }
}

int h=0;

void Book::saleBook() {
    string title,author;
    int quantity,g=0;
    bool f=false;

    cout << "Enter title of the book sold: ";
    cin >> title;
    cout << "Enter author: ";
    cin >> author;
    cout << "Enter quantity sold: ";
    cin >> quantity;

    for (int i = 0; i < availableBooks.size(); i++) {
        if (availableBooks[i].title == title && author==availableBooks[i].author) {
            g=i;
            availableBooks[i].quantity -= quantity;
            break;
        }
    }
    for (int i = 0; i < soldBooks.size(); i++) {
        if (soldBooks[i].title == title) {
            f=true;
            h=i;
            break;
        }
    }
    if(f==true){

        soldBooks[h].quantity += quantity;
    }
    else
    {
        Book delBook;
        soldBooks.push_back(delBook);
        soldBooks[h].title = availableBooks[g].title;
        soldBooks[h].author = availableBooks[g].author;
        soldBooks[h].sellprice = availableBooks[g].sellprice;
        soldBooks[h].buyprice = availableBooks[g].buyprice;
        soldBooks[h].quantity = 0;
        soldBooks[h].quantity += quantity;
        h++;
    }
    cout << "Sale recorded successfully." << std::endl;
}

void Book::saleList() {
    cout << "Sold Books:" << endl;
    for (int i = 0; i < soldBooks.size(); i++) {
        cout << soldBooks[i].title << " by " << soldBooks[i].author << " - $" << soldBooks[i].sellprice << " (" << soldBooks[i].quantity << " sold)" << endl;
    }
}

void Book::profit() {
    cout << "Profit for session:" << endl;
    double sum=0,summ=0;
    for (int i = 0; i < availableBooks.size(); i++) {
        sum += availableBooks[i].buyprice*availableBooks[i].quantity;
    }
    for (int i = 0; i < soldBooks.size(); i++) {
        summ += soldBooks[i].sellprice*soldBooks[i].quantity;
    }
    double prof = summ - sum;
    cout << "$" << prof << endl;
}


