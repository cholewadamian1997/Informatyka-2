#ifndef DATEFORMATTER_HPP_
#define DATEFORMATTER_HPP_

#include "Date.hpp"
#include <iomanip> // std::setfill, std::setw
#include <sstream> // std::ostringstream

class DateFormatter{
    private:

    public:
	//DateFormatter();
	//~DateFormatter();
    std::string Format(Date& d);
};

class ComputerDateFormatter : public DateFormatter{
    private:

    public:
	//ComputerDateFormatter();
	//~ComputerDateFormatter();
	std::string Format(Date & D1);

};

class GermanDateFormatter : public DateFormatter{
    private:

    public:
	//GermanDateFormatter();
	//~GermanDateFormatter();
    std::string Format(Date & D1);
};


#endif /* DATEFORMATTER_HPP_ */

