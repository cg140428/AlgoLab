#include "myDate.h"

//생성자
myDate::myDate(int year, int month, int day)
	:year(year), month(month), day(day) {

}

// Accessor functions (접근자)
int myDate::getDayOfMonth() const {
	return day;
}
int myDate::getMonth() const {
	return month;
}
int myDate::getYear() const {
	return year;
}

// Mutator functions (변경자)
void myDate::setDayOfMonth(int day) {
	this->day = day;
}
void myDate::setMonth(int month) {
	this->month = month;
}
void myDate::setYear(int year) {
	this->year = year;
}
void myDate::setDate(int year, int month, int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}

// utility functions 
//총 일 수
int myDate::getTotalDays() const {
	int totalDays;
	int cntMoon = 0;
	for (int i = 1582; i < year; i++) {
		if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
			cntMoon++;
	}

	totalDays = (year - 1582) * 365 + cntMoon;

	int months[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	for (int i = 1; i < month; i++) {
		totalDays += months[i - 1];
		if (i == 2) {
			if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
				totalDays++;
		}
	}

	totalDays += day;

	return totalDays;
}
//윤년
bool myDate::isLeapYear() const {
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return true;
	else
		return false;
}
//0=Sunday, 1=Monday, ..., 6=Saturday
int myDate::getDayOfWeek() const {
	int totalDays;
	totalDays = getTotalDays();

	int whatDate;

	switch (totalDays % 7)
	{
	case 0: whatDate = 4; break; //목
	case 1: whatDate = 5; break; //금
	case 2: whatDate = 6; break; //토
	case 3: whatDate = 0; break; //일
	case 4: whatDate = 1; break; //월
	case 5: whatDate = 2; break; //화
	case 6: whatDate = 3;		 //수
	}

	return whatDate;
}
//1=Jan.1, 2=Jan.2, ..., 366=Dec.31 (in a leap year)
int myDate::getDayOfYear() const {
	int totalDays = 0;
	int months[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	for (int i = 1; i < month; i++) {
		totalDays += months[i - 1];
		if (i == 2) {
			if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
				totalDays++;
		}
	}

	totalDays += day;

	return totalDays;
}
//휴일수 계산
int myDate::getNumHolidays() const {
	int totalHolidays = 0;
	myDate start(this->year, 1, 1);
	myDate end(this->year, 12, 31);
	myDate holidays[15]{
		myDate(this->year, 1, 1),//
		myDate(this->year, 3, 1),
		myDate(this->year, 5, 5),
		myDate(this->year, 6, 6),
		myDate(this->year, 7, 17),
		myDate(this->year, 8, 15),
		myDate(this->year, 10, 3),
		myDate(this->year, 12, 25),
		myDate(this->year, 2, 1),
		myDate(this->year, 2, 2),
		myDate(this->year, 2, 3),
		myDate(this->year, 5, 15),
		myDate(this->year, 9, 15),
		myDate(this->year, 9, 16),
		myDate(this->year, 9, 17)
	};

	int totalYearDays;
	totalYearDays = isLeapYear() ? 366 + 1 : 365 + 1;
	int sat, sun;
	switch (start.getDayOfWeek()) {
	case 0: sat = 0; sun = 1; break;//일
	case 1: sat = 6; sun = 0; break;//월
	case 2: sat = 5; sun = 6; break;//화
	case 3: sat = 4; sun = 5; break;
	case 4: sat = 3; sun = 4; break;
	case 5: sat = 2; sun = 3; break;
	case 6: sat = 1; sun = 2; break;
	}

	for (int i = 1; i < end.getDayOfYear() + 1; i++) {
		if (i % 7 == sat || i % 7 == sun)
			totalHolidays++;
	}

	for (int i = 0; i < 15; i++) {
		if (holidays[i].getDayOfWeek() == 6 || holidays[i].getDayOfWeek() == 0)
			continue;
		else
			totalHolidays++;
	}

	return totalHolidays;

}
//int getNumSummerTimeDays()const; //써머타임 날짜수
//void printCalendarOfMonth() const; // 달력출력하기