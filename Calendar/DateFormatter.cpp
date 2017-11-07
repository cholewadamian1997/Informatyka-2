#include "DateFormatter.hpp"

std::string ComputerDateFormatter::Format(Date& date)
{
    std::ostringstream tmp;

    tmp << date.getYear()
        << "-" << std::setw(2) << std::setfill('0') << date.getMonth()
        << "-" << std::setw(2) << std::setfill('0') << date.getDay() << std::endl;

    std::string str = tmp.str();
    return str;

}

std::string GermanDateFormatter::Format(Date & date)
{
	std::ostringstream tmp;

	tmp << std::setw(2) << std::setfill('0') << date.getDay() << "."
        << std::setw(2) << std::setfill('0') << date.getMonth() << "."
        << date.getYear() << endl;

	std::string str = tmp.str();
	return str;
}
