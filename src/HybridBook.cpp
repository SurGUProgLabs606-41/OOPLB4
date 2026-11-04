#include "HybridBook.h"
#include <iostream>

HybridBook::HybridBook(const std::string& title, const std::string& isbn, int pages,
                       const std::string& publisher, const std::string& author,
                       double fileSize, const std::string& format)
    : Publication(title, isbn),
      Book(title, isbn, pages, publisher, author),
      DigitalPublication(title, isbn, fileSize, format) {}

HybridBook::HybridBook(const HybridBook& other)
    : Publication(other), Book(other), DigitalPublication(other) {}

HybridBook& HybridBook::operator=(const HybridBook& other) {
    if (this != &other) {
        Book::operator=(other);
        DigitalPublication::operator=(other);
    }
    return *this;
}

std::string HybridBook::getTitle() const { return title; }
std::string HybridBook::getISBN() const { return isbn; }
bool HybridBook::isDigital() const { return true; }

void HybridBook::printInfo() const {
    std::cout << "Гибридная книга: " << title << "\nISBN: " << isbn
              << "\nАвтор: " << author << "\nСтраниц: " << pages
              << "\nИздательство: " << publisher << "\nРазмер файла: " << fileSize
              << " MB\nФормат: " << format << "\n";
}
