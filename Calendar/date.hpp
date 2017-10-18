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
	Date (const Date & date); //Szymon
	showDate(); //Szymon
    	Date operator+(int days); //Asia
    	Date operator-(int days); //Asia
    	Date operator-(const Date &date); //Asia
    	bool operator==(const Date &date); //Damian
    	bool operator!=(const Date &date); //Damian
    	friend std::ostream &operator<<(ostream &out, const Date &date); //Damian

};
#endif /* DATA_HPP_ */
