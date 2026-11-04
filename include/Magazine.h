#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "PrintedPublication.h"

class Magazine : public PrintedPublication {
private:
    int issueNumber;

public:
    Magazine(const std::string& title, const std::string& isbn, int pages,
            const std::string& publisher, int issueNumber);
    Magazine(const Magazine& other);
    Magazine& operator=(const Magazine& other);
    ~Magazine() override = default;

    std::string getTitle() const override;
    std::string getISBN() const override;
    void printInfo() const override;
};

#endif
