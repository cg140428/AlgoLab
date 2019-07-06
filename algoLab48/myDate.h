#ifndef __MYDATE_H__
#define __MYDATE_H__

#include <iostream>
using namespace std;

class myDate
{
private:
	int y, m, d;
	bool LeapYear(int year) const;
	int dayOfWeek(int year, int month, int day) const;
	int DayOfYear(int year, int month, int day) const;
	int numHolodays(int year) const;
	int numSummerTimeDays(int year) const;
	void CalendarOfMonth(int year, int month) const;
	int daySum(int year, int month, int day) const;
	myDate sumToDate(int num) const;

	friend ostream &operator <<(ostream &outStream, const myDate& date);
	friend istream &operator >>(istream &inStream, myDate& date);
	friend myDate operator +(int num, const myDate& date);
public:
	myDate(int year = 1582, int month = 1, int day = 1);
	//myDate(const myDate& date);

	int getDayOfMonth() const;
	int getMonth() const;
	int getYear() const;

	void setDayOfMonth(int day);
	void setMonth(int month);
	void setYear(int year);
	void setDate(int year, int month, int day);

	int operator -(const myDate& date) const;
	myDate operator +(int num) const;
	myDate operator -(int num) const;

	myDate& operator ++();
	myDate& operator --();
	myDate operator ++(int);
	myDate operator --(int);

	myDate& operator =(const myDate& date);
	myDate& operator +=(int num);
	myDate& operator -=(int num);

	bool operator >(const myDate& date) const;
	bool operator >=(const myDate& date) const;
	bool operator <(const myDate& date) const;
	bool operator <=(const myDate& date) const;
	bool operator ==(const myDate& date) const;
	bool operator !=(const myDate& date) const;

	bool isLeapYear() const;
	int getDayOfWeek() const;
	int getDayOfYear() const;
	int getNumHolidays() const;
	int getNumSummerTimeDays() const;
	void printCalendarOfMonth() const;
};

#endif