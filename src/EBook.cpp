#include "EBook.h"
#include <iostream>

using namespace std;

EBook::EBook(const string &title, const string &isbn,
             double fileSize, const string &format)
    : Publication(title, isbn), DigitalPublication(title, isbn, fileSize, format) {}

EBook::EBook(const EBook &other) : Publication(other), DigitalPublication(other) {}

EBook &EBook::operator=(const EBook &other)
{
    if (this != &other)
        DigitalPublication::operator=(other);
    return *this;
}

string EBook::getTitle() const { return title; }
string EBook::getISBN() const { return isbn; }

void EBook::printInfo() const
{
    cout << "Электронная книга: " << title << "\nISBN: "
         << isbn << "\nРазмер файла: " << fileSize
         << " MB\nФормат: " << format << "\n";
}
