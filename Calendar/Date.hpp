#ifndef DATE_HPP_
#define DATE_HPP_

#include <iostream>
#include <array>

using std::cout;
using std::endl;

class Date{
private:

	int day;
	int month;
	int year;

    int dateToDays() const;
    Date daysToDate(int days);

public:

    Date(int _day = 1, int _month = 1, int _year = 1970);
    Date(const Date & date);

    int getDay();
    int getMonth();
    int getYear();

    Date operator+(int days);
    Date operator-(int days);
    int operator-(const Date &date) const;
    bool operator==(const Date  &date) const;
    bool operator!=(const Date &date) const;
    Date operator+=(int days);
    Date operator-=(int days);
    friend std::ostream &operator<<(std::ostream &out, const Date &date);

};


const std::array<const int, 12> daysInMonths = {
    31, // Jan
    28, // Feb
    31, // Mar
    30, // Apr
    31, // May
    30, // Jun
    31, // Jul
    31, // Aug
    30, // Sep
    31, // Oct
    30, // Nov
    31  // Dec

};

#endif /* DATA_HPP_ */


