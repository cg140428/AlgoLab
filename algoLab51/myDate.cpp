#include "myDate.h"

//������
myDate::myDate(int year, int month, int day)
	:year(year), month(month), day(day) {

}

// Accessor functions (������)
int myDate::getDayOfMonth() const {
	return day;
}
int myDate::getMonth() const {
	return month;
}
int myDate::getYear() const {
	return year;
}

// Mutator functions (������)
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
//����
bool myDate::isLeapYear() const {
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return true;
	else
		return false;
}
//0=Sunday, 1=Monday, ..., 6=Saturday
int myDate::getDayOfWeek() const {
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

	int whatDate;

	switch (totalDays % 7)
	{
	case 0: whatDate = 4; break; //��
	case 1: whatDate = 5; break; //��
	case 2: whatDate = 6; break; //��
	case 3: whatDate = 0; break; //��
	case 4: whatDate = 1; break; //��
	case 5: whatDate = 2; break; //ȭ
	case 6: whatDate = 3;		 //��
	}

	return whatDate;
}
//1=Jan.1, 2=Jan.2, ..., 366=Dec.31 (in a leap year)
//int myDate::getDayOfYear() const;
//int getNumHolidays() const; //���ϼ� ���
//int getNumSummerTimeDays()const; //���Ÿ�� ��¥��
//void printCalendarOfMonth() const; // �޷�����ϱ�