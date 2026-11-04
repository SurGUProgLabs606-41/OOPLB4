#ifndef EBOOK_H
#define EBOOK_H

#include "DigitalPublication.h"

using namespace std;

class EBook : public DigitalPublication
{
public:
    EBook(const string &title, const string &isbn,
          double fileSize, const string &format);
    EBook(const EBook &other);
    EBook &operator=(const EBook &other);
    ~EBook() override = default;

    string getTitle() const override;
    string getISBN() const override;
    void printInfo() const override;
};

#endif
