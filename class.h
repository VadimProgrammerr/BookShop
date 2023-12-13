#ifndef CLASS
#define CLASS

#include <string>
#include <vector>

using namespace std;

class Book {
public:
    Book();
    ~Book();
    void interface();
    string title;
    string author;
    double price;
    int quantity;
    void addBook();
    void saleBook();
    void bookList();
    void saleList();
private:

};


extern vector<Book> availableBooks;

#endif // CLASS

