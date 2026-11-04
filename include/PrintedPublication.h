#ifndef PRINTEDPUBLICATION_H
#define PRINTEDPUBLICATION_H

#include "Publication.h"

using namespace std;

class PrintedPublication : virtual public Publication
{
protected:
    int pages;
    string publisher;

public:
    PrintedPublication(const string &title, const string &isbn,
                       int pages, const string &publisher);
    PrintedPublication(const PrintedPublication &other);
    PrintedPublication &operator=(const PrintedPublication &other);
    ~PrintedPublication() override = default;

    int getPages() const;
    string getPublisher() const;
    void printInfo() const override;
};

#endif
