#ifndef CLASS
#define CLASS

#include <string>
#include <vector>

using namespace std;

class Book {
public:
    Book();
    ~Book();
    void menu();
    string title;
    string author;
    double price;
    int quantity;
    void addBook();
private:

    void saleBook();
    void bookList();
    void saleList();
};


extern vector<Book> availableBooks;

#endif // CLASS

