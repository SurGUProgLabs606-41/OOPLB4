#include "EBook.h"
#include <iostream>

EBook::EBook(const std::string& title, const std::string& isbn,
             double fileSize, const std::string& format)
    : Publication(title, isbn), DigitalPublication(title, isbn, fileSize, format) {}

EBook::EBook(const EBook& other)
    : Publication(other), DigitalPublication(other) {}

EBook& EBook::operator=(const EBook& other) {
    if (this != &other) DigitalPublication::operator=(other);
    return *this;
}

std::string EBook::getTitle() const { return title; }
std::string EBook::getISBN() const { return isbn; }

void EBook::printInfo() const {
    std::cout << "Электронная книга: " << title << "\nISBN: " << isbn
              << "\nРазмер файла: " << fileSize << " MB\nФормат: " << format << "\n";
}
