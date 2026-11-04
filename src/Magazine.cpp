#include "Magazine.h"
#include <iostream>

Magazine::Magazine(const std::string& title, const std::string& isbn, int pages,
                   const std::string& publisher, int issueNumber)
    : Publication(title, isbn), PrintedPublication(title, isbn, pages, publisher),
      issueNumber(issueNumber) {}

Magazine::Magazine(const Magazine& other)
    : Publication(other), PrintedPublication(other), issueNumber(other.issueNumber) {}

Magazine& Magazine::operator=(const Magazine& other) {
    if (this != &other) {
        PrintedPublication::operator=(other);
        issueNumber = other.issueNumber;
    }
    return *this;
}

std::string Magazine::getTitle() const { return title; }
std::string Magazine::getISBN() const { return isbn; }

void Magazine::printInfo() const {
    std::cout << "Журнал: " << title << "\nISBN: " << isbn << "\nНомер выпуска: "
              << issueNumber << "\nСтраниц: " << pages << "\nИздательство: " << publisher << "\n";
}
