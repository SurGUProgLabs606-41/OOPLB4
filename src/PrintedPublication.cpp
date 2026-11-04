#include "PrintedPublication.h"
#include <iostream>

PrintedPublication::PrintedPublication(const std::string& title, const std::string& isbn,
                                       int pages, const std::string& publisher)
    : Publication(title, isbn), pages(pages), publisher(publisher) {}

PrintedPublication::PrintedPublication(const PrintedPublication& other)
    : Publication(other), pages(other.pages), publisher(other.publisher) {}

PrintedPublication& PrintedPublication::operator=(const PrintedPublication& other) {
    if (this != &other) {
        Publication::operator=(other);
        pages = other.pages;
        publisher = other.publisher;
    }
    return *this;
}

int PrintedPublication::getPages() const { return pages; }
std::string PrintedPublication::getPublisher() const { return publisher; }

void PrintedPublication::printInfo() const {
    std::cout << "Печатное издание: " << title << "\nISBN: " << isbn
              << "\nСтраниц: " << pages << "\nИздательство: " << publisher << "\n";
}
