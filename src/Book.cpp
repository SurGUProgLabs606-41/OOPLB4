#include "Book.h"
#include <iostream>

using namespace std;

Book::Book(const string& title, const string& isbn, int pages,
           const string& publisher, const string& author)
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

string Book::getAuthor() const { return author; }
string Book::getTitle() const { return title; }
string Book::getISBN() const { return isbn; }

void Book::printInfo() const {
    cout << "Книга: " << title << "\nISBN: " << isbn << "\nАвтор: " << author << "\nСтраниц: " << pages << "\nИздательство: " << publisher << "\n";
}
