#ifndef DATA_HPP_
#define DATA_HPP_

#include <ostream>
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

	Date(int _day = 1, int _month = 1, int _year = 1970);
	Date (const Date & date); //Szymon
	showDate(); //Szymon
    	Date operator+(int days); //Asia
    	Date operator-(int days); //Asia
    	Date operator-(const Date &date); //Asia
    	bool operator==(const Date &date); //Damian
    	bool operator!=(const Date &date); //Damian
    	Date operator+=(const Date &date);
    	Date operator-=(const Date &date);
    	friend std::ostream &operator<<(ostream &out, const Date &date); //Damian

};
#endif /* DATA_HPP_ */
