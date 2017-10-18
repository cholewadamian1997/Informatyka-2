#ifndef DATA_HPP_
#define DATA_HPP_

#include <ostream> 

class Date{
	private:

	int day;
	int month;
	int year;
	int tab[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}

	public:

	Date(int _day = 1, int _month = 1, int _year = 1970);
	Date (const Date & date);
	showDate();
    	Date operator+(int days);
    	Date operator-(int days);
    	Date operator-(const Date &date);
    	bool operator==(const Date &date);
    	bool operator!=(const Date &date);
    	friend std::ostream &operator<<(ostream &out, const Date &date);

};
#endif /* DATA_HPP_ */
