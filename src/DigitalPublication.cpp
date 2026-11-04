#include "DigitalPublication.h"
#include <iostream>

using namespace std;

DigitalPublication::DigitalPublication(const string &title, const string &isbn,
                                       double fileSize, const string &format)
    : Publication(title, isbn), fileSize(fileSize), format(format)
{
    ++digitalCount;
}

DigitalPublication::DigitalPublication(const DigitalPublication &other)
    : Publication(other), fileSize(other.fileSize), format(other.format)
{
    ++digitalCount;
}

DigitalPublication &DigitalPublication::operator=(const DigitalPublication &other)
{
    if (this != &other)
    {
        Publication::operator=(other);
        fileSize = other.fileSize;
        format = other.format;
    }
    return *this;
}

DigitalPublication::~DigitalPublication() { --digitalCount; }

double DigitalPublication::getFileSize() const { return fileSize; }
string DigitalPublication::getFormat() const { return format; }
bool DigitalPublication::isDigital() const { return true; }

void DigitalPublication::printInfo() const
{
    cout << "Электронное издание: " << title << "\nISBN: "
         << isbn << "\nРазмер файла: " << fileSize
         << " MB\nФормат: " << format << "\n";
}
