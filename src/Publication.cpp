#include "Publication.h"
#include <iostream>
#include <algorithm>

int Publication::totalCount = 0;
int Publication::digitalCount = 0;
std::vector<Publication*> Publication::registry;

Publication::Publication(const std::string& title, const std::string& isbn)
    : title(title), isbn(isbn) {
    ++totalCount;
    registry.push_back(this);
}

Publication::Publication(const Publication& other)
    : title(other.title), isbn(other.isbn) {
    ++totalCount;
    registry.push_back(this);
}

Publication& Publication::operator=(const Publication& other) {
    if (this != &other) {
        title = other.title;
        isbn = other.isbn;
    }
    return *this;
}

Publication::~Publication() {
    registry.erase(std::remove(registry.begin(), registry.end(), this), registry.end());
    --totalCount;
}

bool Publication::isDigital() const { return false; }
int Publication::getTotalCount() { return totalCount; }
int Publication::getDigitalCount() { return digitalCount; }

Publication* Publication::findByISBN(const std::string& value) {
    for (Publication* item : registry) {
        if (item && item->getISBN() == value) return item;
    }
    return nullptr;
}

void printPublication(const Publication& publication) {
    publication.printInfo();
}
