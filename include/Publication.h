#ifndef PUBLICATION_H
#define PUBLICATION_H

#include <string>
#include <vector>

class Publication {
protected:
    std::string title;
    std::string isbn;

    static int totalCount;
    static int digitalCount;
    static std::vector<Publication*> registry;

public:
    Publication(const std::string& title, const std::string& isbn);
    Publication(const Publication& other);
    Publication& operator=(const Publication& other);
    virtual ~Publication();

    virtual std::string getTitle() const = 0;
    virtual std::string getISBN() const = 0;
    virtual void printInfo() const = 0;

    virtual bool isDigital() const;
    static int getTotalCount();
    static int getDigitalCount();
    static Publication* findByISBN(const std::string& isbn);

    friend void printPublication(const Publication& publication);
};

#endif
