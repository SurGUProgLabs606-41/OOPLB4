#ifndef EBOOK_H
#define EBOOK_H

#include "DigitalPublication.h"

class EBook : public DigitalPublication {
public:
    EBook(const std::string& title, const std::string& isbn,
          double fileSize, const std::string& format);
    EBook(const EBook& other);
    EBook& operator=(const EBook& other);
    ~EBook() override = default;

    std::string getTitle() const override;
    std::string getISBN() const override;
    void printInfo() const override;
};

#endif
