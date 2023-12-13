#ifndef CLASS
#define CLASS

#include <string>
#include <vector>

using namespace std;

class Book {
public:
    Book();
    ~Book();
private:
    void interface();
    string title;
    string author;
    double buyprice;
    double sellprice;
    int quantity;
    void addBook();
    void saleBook();
    void bookList();
    void saleList();
    void profit();
};


extern vector<Book> availableBooks;
extern vector<Book> soldBooks;

#endif // CLASS

