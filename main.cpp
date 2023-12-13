#include <iostream>
#include <vector>
#include "class.h"
#include <string>

using namespace std;

int main()
{
    Book book;
    book.addBook();
    int i=0;

    cout << availableBooks[i].title << " by " << availableBooks[i].author << " - $" << availableBooks[i].price << " (" << availableBooks[i].quantity << " available)" << std::endl;
    return 0;
}

