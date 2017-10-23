#include "Date.hpp"

using namespace std;

Date Date::operator+(int days)
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

Date Date::operator-(int days)
{
    day -= days;
    while(day < 1)
    {
        month--;
        day += daysInMonths[month-1];

        while(month < 0)
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
    *this - date.days;

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

ostream& operator<<(ostream out, Date &date)
{
	out << "date: " << date.day << "-" << date.month << "-" << date.year << endl;

	return out;

}

Date::showDate()
{
	cout<<"Date: "<<day<<"-"<<month<<"-"<<year<<endl; 
}

Date (const Date &date)
{
	day=date.day;
	month=date.month;
	year=date.year;
}
