#ifndef BOOK_H
#define BOOK_H

#include "PrintedPublication.h"

class Book : public PrintedPublication {
protected:
    std::string author;

public:
    Book(const std::string& title, const std::string& isbn, int pages,
         const std::string& publisher, const std::string& author);
    Book(const Book& other);
    Book& operator=(const Book& other);
    ~Book() override = default;

    std::string getAuthor() const;
    std::string getTitle() const override;
    std::string getISBN() const override;
    void printInfo() const override;
};

#endif
