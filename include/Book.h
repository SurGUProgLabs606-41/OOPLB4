#ifndef BOOK_H
#define BOOK_H

#include "PrintedPublication.h"

using namespace std;

class Book : public PrintedPublication {
protected:
    string author;

public:
    Book(const string& title, const string& isbn, int pages,
         const string& publisher, const string& author);
    Book(const Book& other);
    Book& operator=(const Book& other);
    ~Book() override = default;

    string getAuthor() const;
    string getTitle() const override;
    string getISBN() const override;
    void printInfo() const override;
};

#endif
