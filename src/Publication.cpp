
#include "Publication.h"
#include <iostream>

using namespace std;

int Publication::totalCount = 0;
int Publication::digitalCount = 0;

Publication* Publication::registry[100] = {};
int Publication::registryCount = 0;

Publication::Publication(const string& title, const string& isbn)
    : title(title), isbn(isbn)
{
    ++totalCount;

    if (registryCount < 100)
        registry[registryCount++] = this;
}

Publication::Publication(const Publication& other)
    : title(other.title), isbn(other.isbn)
{
    ++totalCount;

    if (registryCount < 100)
        registry[registryCount++] = this;
}

Publication& Publication::operator=(const Publication& other)
{
    if (this != &other)
    {
        title = other.title;
        isbn = other.isbn;
    }

    return *this;
}

Publication::~Publication()
{
    for (int i = 0; i < registryCount; ++i)
    {
        if (registry[i] == this)
        {
            for (int j = i; j < registryCount - 1; ++j)
                registry[j] = registry[j + 1];

            registry[--registryCount] = nullptr;
            break;
        }
    }

    --totalCount;
}

bool Publication::isDigital() const
{
    return false;
}

int Publication::getTotalCount()
{
    return totalCount;
}

int Publication::getDigitalCount()
{
    return digitalCount;
}

Publication* Publication::findByISBN(const string& value)
{
    for (int i = 0; i < registryCount; ++i)
    {
        Publication* item = registry[i];

        if (item && item->getISBN() == value)
            return item;
    }

    return nullptr;
}

void printPublication(const Publication& publication)
{
    publication.printInfo();
}
