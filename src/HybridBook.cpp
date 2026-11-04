#include "HybridBook.h"
#include <iostream>

using namespace std;

HybridBook::HybridBook(const string &title, const string &isbn, int pages,
                       const string &publisher, const string &author,
                       double fileSize, const string &format)
    : Publication(title, isbn),
      Book(title, isbn, pages, publisher, author),
      DigitalPublication(title, isbn, fileSize, format) {}

HybridBook::HybridBook(const HybridBook &other)
    : Publication(other), Book(other), DigitalPublication(other) {}

HybridBook &HybridBook::operator=(const HybridBook &other)
{
    if (this != &other)
    {
        Book::operator=(other);
        DigitalPublication::operator=(other);
    }
    return *this;
}

string HybridBook::getTitle() const { return title; }
string HybridBook::getISBN() const { return isbn; }
bool HybridBook::isDigital() const { return true; }

void HybridBook::printInfo() const
{
    cout << "Гибридная книга: " << title << "\nISBN: " << isbn
         << "\nАвтор: " << author << "\nСтраниц: " << pages
         << "\nИздательство: " << publisher << "\nРазмер файла: " << fileSize
         << " MB\nФормат: " << format << "\n";
}
