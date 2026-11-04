#include "Magazine.h"
#include <iostream>

using namespace std;

Magazine::Magazine(const string &title, const string &isbn, int pages,
                   const string &publisher, int issueNumber)
    : Publication(title, isbn), PrintedPublication(title, isbn, pages, publisher),
      issueNumber(issueNumber) {}

Magazine::Magazine(const Magazine &other)
    : Publication(other), PrintedPublication(other), issueNumber(other.issueNumber) {}

Magazine &Magazine::operator=(const Magazine &other)
{
    if (this != &other)
    {
        PrintedPublication::operator=(other);
        issueNumber = other.issueNumber;
    }
    return *this;
}

string Magazine::getTitle() const { return title; }
string Magazine::getISBN() const { return isbn; }

void Magazine::printInfo() const
{
    cout << "Журнал: " << title << "\nISBN: " << isbn << "\nНомер выпуска: "
         << issueNumber << "\nСтраниц: " << pages << "\nИздательство: " << publisher << "\n";
}
