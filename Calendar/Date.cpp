#include "Date.hpp"

/*
int Date::getDay()
{
    return day;
}

int Date::getMonth()
{
    return month;
}

int Date::getYear()
{
    return year;
}
*/

int Date::dateToDays()
{
    int days = (year - 1970) * 365;

    for (int i = month-1; i > 0; i--)
    {
        days += daysInMonths[i-1];
    }

    days += day-1;
    return days;
}

Date Date::daysToDate(int days)
{
    month = 1;


    year = int (days/365) + 1970;
    days = days % 365;

    for(int i = 0; days > daysInMonths[i]; i++)
    {
        month++;
        days -= daysInMonths[i];
    }

    day = days+1;

}


Date::Date(int _day, int _month , int _year)
{
    day = _day;
    month = _month;
    year = _year;
}

Date::Date(const Date &date)
{
	day = date.day;
	month = date.month;
	year = date.year;
}

Date Date::operator+(int days)
{
	Date newDate(*this);

    newDate.daysToDate(newDate.dateToDays() + days);
    return newDate;
}

Date Date::operator+=(int days)
{
    (*this).daysToDate(dateToDays()+days);
    return *this;
}

Date Date::operator-(int days)
{
	Date newDate(*this);

    newDate.daysToDate(newDate.dateToDays() - days);
    return newDate;
}

Date Date::operator-=(int days)
{
    (*this).daysToDate(dateToDays()-days);
    return *this;
}


int Date::operator-(Date &date)
{
    int days = dateToDays() - date.dateToDays();
    return days;
}

bool Date::operator==(Date &date)
{
    if (dateToDays() == date.dateToDays())
        return true;
    return false;
}

bool Date::operator!=(Date &date)
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




