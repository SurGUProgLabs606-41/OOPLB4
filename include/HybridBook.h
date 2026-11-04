#ifndef HYBRIDBOOK_H
#define HYBRIDBOOK_H

#include "Book.h"
#include "DigitalPublication.h"

class HybridBook : public Book, public DigitalPublication {
public:
    HybridBook(const std::string& title, const std::string& isbn, int pages,
               const std::string& publisher, const std::string& author,
               double fileSize, const std::string& format);
    HybridBook(const HybridBook& other);
    HybridBook& operator=(const HybridBook& other);
    ~HybridBook() override = default;

    std::string getTitle() const override;
    std::string getISBN() const override;
    bool isDigital() const override;
    void printInfo() const override;
};

#endif
