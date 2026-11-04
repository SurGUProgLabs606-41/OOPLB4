
#ifndef PUBLICATION_H
#define PUBLICATION_H

#include <string>

using namespace std;

class Publication
{
protected:
    string title;
    string isbn;

    static int totalCount;
    static int digitalCount;

    static Publication *registry[100];
    static int registryCount;

public:
    Publication(const string &title, const string &isbn);
    Publication(const Publication &other);
    Publication &operator=(const Publication &other);
    virtual ~Publication();

    virtual string getTitle() const = 0;
    virtual string getISBN() const = 0;
    virtual void printInfo() const = 0;

    virtual bool isDigital() const;
    static int getTotalCount();
    static int getDigitalCount();
    static Publication *findByISBN(const string &isbn);

    friend void printPublication(const Publication &publication);
};

#endif
