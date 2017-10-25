#ifndef DATA_HPP_
#define DATA_HPP_

#include <iostream>
#include <array>

class Date{
	private:

	int day;
	int month;
	int year;
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

	public:

		Date(int _day = 1, int _month = 1, int _year = 1970,array _daysInMonths);
		Date(const Date & date);
    	Date operator+(int days);
    	Date operator-(int days);
    	Date operator-(const Date &date);
    	bool operator==(const Date &date);
    	bool operator!=(const Date &date);
    	Date operator+=(int days);
    	Date operator-=(int days);
    	friend std::ostream &operator<<(std::ostream &out, const Date &date);

};
#endif /* DATA_HPP_ */
