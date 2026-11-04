#include "DigitalPublication.h"
#include <iostream>

DigitalPublication::DigitalPublication(const std::string& title, const std::string& isbn,
                                       double fileSize, const std::string& format)
    : Publication(title, isbn), fileSize(fileSize), format(format) {
    ++digitalCount;
}

DigitalPublication::DigitalPublication(const DigitalPublication& other)
    : Publication(other), fileSize(other.fileSize), format(other.format) {
    ++digitalCount;
}

DigitalPublication& DigitalPublication::operator=(const DigitalPublication& other) {
    if (this != &other) {
        Publication::operator=(other);
        fileSize = other.fileSize;
        format = other.format;
    }
    return *this;
}

DigitalPublication::~DigitalPublication() { --digitalCount; }

double DigitalPublication::getFileSize() const { return fileSize; }
std::string DigitalPublication::getFormat() const { return format; }
bool DigitalPublication::isDigital() const { return true; }

void DigitalPublication::printInfo() const {
    std::cout << "Электронное издание: " << title << "\nISBN: " << isbn
              << "\nРазмер файла: " << fileSize << " MB\nФормат: " << format << "\n";
}
