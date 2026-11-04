#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "PrintedPublication.h"

using namespace std;

class Magazine : public PrintedPublication
{
private:
    int issueNumber;

public:
    Magazine(const string &title, const string &isbn, int pages,
             const string &publisher, int issueNumber);
    Magazine(const Magazine &other);
    Magazine &operator=(const Magazine &other);
    ~Magazine() override = default;

    string getTitle() const override;
    string getISBN() const override;
    void printInfo() const override;
};

#endif
