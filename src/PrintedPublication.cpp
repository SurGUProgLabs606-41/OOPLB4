#include "PrintedPublication.h"
#include <iostream>

using namespace std;

PrintedPublication::PrintedPublication(const string &title, const string &isbn,
                                       int pages, const string &publisher)
    : Publication(title, isbn), pages(pages), publisher(publisher) {}

PrintedPublication::PrintedPublication(const PrintedPublication &other)
    : Publication(other), pages(other.pages), publisher(other.publisher) {}

PrintedPublication &PrintedPublication::operator=(const PrintedPublication &other)
{
    if (this != &other)
    {
        Publication::operator=(other);
        pages = other.pages;
        publisher = other.publisher;
    }
    return *this;
}

int PrintedPublication::getPages() const { return pages; }
string PrintedPublication::getPublisher() const { return publisher; }

void PrintedPublication::printInfo() const
{
    cout << "Печатное издание: " << title << "\nISBN: " << isbn
         << "\nСтраниц: " << pages << "\nИздательство: " << publisher << "\n";
}
