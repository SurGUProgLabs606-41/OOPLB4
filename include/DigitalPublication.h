#ifndef DIGITALPUBLICATION_H
#define DIGITALPUBLICATION_H

#include "Publication.h"

class DigitalPublication : virtual public Publication {
protected:
    double fileSize;
    std::string format;

public:
    DigitalPublication(const std::string& title, const std::string& isbn,
                       double fileSize, const std::string& format);
    DigitalPublication(const DigitalPublication& other);
    DigitalPublication& operator=(const DigitalPublication& other);
    ~DigitalPublication() override;

    double getFileSize() const;
    std::string getFormat() const;
    bool isDigital() const override;
    void printInfo() const override;
};

#endif
