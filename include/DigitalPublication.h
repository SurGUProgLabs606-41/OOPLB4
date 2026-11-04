#ifndef DIGITALPUBLICATION_H
#define DIGITALPUBLICATION_H

#include "Publication.h"

using namespace std;

class DigitalPublication : virtual public Publication
{
protected:
    double fileSize;
    string format;

public:
    DigitalPublication(const string &title, const string &isbn,
                       double fileSize, const string &format);
    DigitalPublication(const DigitalPublication &other);
    DigitalPublication &operator=(const DigitalPublication &other);
    ~DigitalPublication() override;

    double getFileSize() const;
    string getFormat() const;
    bool isDigital() const override;
    void printInfo() const override;
};

#endif
