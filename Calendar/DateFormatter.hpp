#ifndef DATEFORMATTER_HPP_
#define DATEFORMATTER_HPP_

#include "Date.hpp"
#include <iomanip> // std::setfill, std::setw
#include <sstream> // std::ostringstream

class DateFormatter{
    private:

    public:
	DateFormatter() {};
    virtual ~DateFormatter() {};
    virtual std::string Format(Date& date) = 0;
};

class ComputerDateFormatter : public DateFormatter{
    private:

    public:
	ComputerDateFormatter() {};
	virtual std::string Format(Date & date) override;

};

class GermanDateFormatter : public DateFormatter{
    private:

    public:
	GermanDateFormatter() {};
    virtual std::string Format(Date & date) override;
};


#endif /* DATEFORMATTER_HPP_ */

