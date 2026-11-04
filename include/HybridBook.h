#ifndef HYBRIDBOOK_H
#define HYBRIDBOOK_H

#include "Book.h"
#include "DigitalPublication.h"

using namespace std;

class HybridBook : public Book, public DigitalPublication
{
public:
    HybridBook(const string &title, const string &isbn, int pages,
               const string &publisher, const string &author,
               double fileSize, const string &format);
    HybridBook(const HybridBook &other);
    HybridBook &operator=(const HybridBook &other);
    ~HybridBook() override = default;

    string getTitle() const override;
    string getISBN() const override;
    bool isDigital() const override;
    void printInfo() const override;
};

#endif
