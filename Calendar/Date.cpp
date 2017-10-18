#include "Date.hpp"

using namespace std;

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
