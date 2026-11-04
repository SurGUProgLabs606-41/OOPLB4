#include "Book.h"
#include <iostream>

Book::Book(const std::string& title, const std::string& isbn, int pages,
           const std::string& publisher, const std::string& author)
    : Publication(title, isbn), PrintedPublication(title, isbn, pages, publisher), author(author) {}

Book::Book(const Book& other)
    : Publication(other), PrintedPublication(other), author(other.author) {}

Book& Book::operator=(const Book& other) {
    if (this != &other) {
        PrintedPublication::operator=(other);
        author = other.author;
    }
    return *this;
}

std::string Book::getAuthor() const { return author; }
std::string Book::getTitle() const { return title; }
std::string Book::getISBN() const { return isbn; }

void Book::printInfo() const {
    std::cout << "Книга: " << title << "\nISBN: " << isbn << "\nАвтор: " << author
              << "\nСтраниц: " << pages << "\nИздательство: " << publisher << "\n";
}
