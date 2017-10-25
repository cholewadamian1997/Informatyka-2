#include "data.hpp"

using namespace std;

Date::Date(const Date &date)
{
	day = date.day;
	month = date.month;
	year = date.year;
}

Date Date::operator+(int days)
{
	Date newDate(*this);


	newDate.day = day + days;
    while(newDate.day > newDate.daysInMonths[month-1])
    {
        newDate.month++;
        newDate.day -= newDate.daysInMonths[month-1];

        while(newDate.month > 12)
        {
            newDate.year++;
            newDate.month -= 12;
        }
    }
    return newDate;
}

Date Date::operator-(int days)
{
	Date newDate(*this);

	newDate.day = day - days;
    while(newDate.day < 1)
    {
        newDate.month--;
        newDate.day += newDate.daysInMonths[month-1];

        while(newDate.month < 1)
        {
            newDate.year--;
            newDate.month += 12;
        }
    }
    return newDate;
}

Date Date::operator+=(int days)
{
    day += days;
    while(day > daysInMonths[month-1])
    {
        month++;
        day -= daysInMonths[month-1];

        while(month > 12)
        {
            year++;
            month -= 12;
        }
    }
    return *this;
}

Date Date::operator-=(int days)
{
    day -= days;
    while(day < 1)
    {
        month--;
        day += daysInMonths[month-1];

        while(month < 1)
        {
            year--;
            month += 12;
        }
    }
    return *this;
}


Date Date::operator-(const Date &date)
{
    year - date.year;
    month - date.month;
    *this - date.day;

    return *this;
}

bool Date::operator==(const Date &date)
{
	if (day != date.day)
		return false;
	if (month != date.month)
		return false;
	if (year != date.year)
		return false;

	return true;

}

bool Date::operator!=(const Date &date)
{
	if (*this == date)
		return false;
	return true;

}

std::ostream &operator<<(std::ostream &out, const Date &date)
{
	out << "date: " << date.day << "-" << date.month << "-" << date.year << endl;

	return out;

}




