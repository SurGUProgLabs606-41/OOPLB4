#ifndef PRINTEDPUBLICATION_H
#define PRINTEDPUBLICATION_H

#include "Publication.h"

class PrintedPublication : virtual public Publication {
protected:
    int pages;
    std::string publisher;

public:
    PrintedPublication(const std::string& title, const std::string& isbn,
                       int pages, const std::string& publisher);
    PrintedPublication(const PrintedPublication& other);
    PrintedPublication& operator=(const PrintedPublication& other);
    ~PrintedPublication() override = default;

    int getPages() const;
    std::string getPublisher() const;
    void printInfo() const override;
};

#endif
