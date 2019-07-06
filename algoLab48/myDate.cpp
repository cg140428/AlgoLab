#include "myDate.h"

myDate::myDate(int year, int month, int day)
	:y(year), m(month), d(day)
{}

int myDate::getDayOfMonth() const
{
	return d;
}

int myDate::getMonth() const
{
	return m;
}

int myDate::getYear() const
{
	return y;
}

void myDate::setDayOfMonth(int day)
{
	d = day;
}

void myDate::setMonth(int month)
{
	m = month;
}

void myDate::setYear(int year)
{
	y = year;
}

void myDate::setDate(int year, int month, int day)
{
	y = year;
	m = month;
	d = day;
}

bool myDate::isLeapYear() const
{
	return LeapYear(y);
}

bool myDate::LeapYear(int year) const
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return 1;
	else
		return 0;
}

int myDate::dayOfWeek(int year, int month, int day) const
{
	int dayCal = 5;
	for (int a = 1582; a < year; a++)
	{
		if (LeapYear(a))
			dayCal += 2;
		else
			dayCal += 1;
	}

	for (int b = 1; b < month; b++)
	{
		switch (b)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			dayCal += 31; break;
		case 2:
			if (isLeapYear())
				dayCal += 29;
			else
				dayCal += 28;
			break;
		default:
			dayCal += 30;
		}
	}

	dayCal += day - 1;

	dayCal %= 7;

	return dayCal;
}

int myDate::getDayOfWeek() const
{
	return dayOfWeek(y, m, d);
}

int myDate::DayOfYear(int year, int month, int day) const
{
	int sumDay = 0;

	for (int a = 1; a < month; a++)
	{
		switch (a)
		{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			sumDay += 31; break;
		case 2:
			if (LeapYear(year))
				sumDay += 29;
			else
				sumDay += 28;
			break;
		default:
			sumDay += 30;
		}
	}

	sumDay += day;

	return sumDay;
}

int myDate::getDayOfYear() const
{
	return DayOfYear(y, m, d);
}

int myDate::numHolodays(int year) const
{
	int holiNum[15][2] = { 1, 1, 2, 1, 2, 2, 2, 3, 3, 1, 5, 5, 6, 6, 7, 17, 8, 15, 10, 3, 12, 25, 5, 15, 9, 15, 9, 16, 9, 17 };
	int holiday[15] = {};

	for (int a = 0; a < 15; a++)
		holiday[a] = DayOfYear(year, holiNum[a][0], holiNum[a][1]);

	int day = dayOfWeek(year, 1, 1);
	int totalDay = 365;
	int holidaySum = 0;
	int ifLeap = 0;

	if (LeapYear(year))
	{
		totalDay++;
	}

	for (int a = 1; a <= totalDay; a++)
	{
		if (day == 0 || day == 6)
		{
			holidaySum++;
		}
		else
		{

			for (int b = 0; b < 15; b++)
			{
				if (a == holiday[b])
				{
					holidaySum++;
					break;
				}
			}
		}

		day++;
		day %= 7;
	}

	return holidaySum;
}

int myDate::getNumHolidays() const
{
	return numHolodays(y);
}

int myDate::numSummerTimeDays(int year) const
{
	int matchSun = -1;
	int octorSun = -1;
	for (int a = 31; (matchSun == -1) || (octorSun == -1); a--)
	{
		if (matchSun == -1)
		{
			if (dayOfWeek(year, 3, a) == 0)
			{
				matchSun = a;
			}
		}
		if (octorSun == -1)
		{
			if (dayOfWeek(year, 10, a) == 0)
			{
				octorSun = a;
			}
		}
	}

	return (DayOfYear(year, 10, octorSun) - DayOfYear(year, 3, matchSun));
}

int myDate::getNumSummerTimeDays() const
{
	return numSummerTimeDays(y);
}

void myDate::CalendarOfMonth(int year, int month) const
{
	int a = dayOfWeek(year, month, 1);
	int totalDays;
	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		totalDays = 31;
		break;
	case 2:
		if (LeapYear(year))
			totalDays = 29;
		else
			totalDays = 28;
		break;
	default:
		totalDays = 30;
	}

	cout << year << " " << month << endl;

	for (int zerofirst = 0; zerofirst < a; zerofirst++)
	{
		cout << "0 ";
	}

	for (int start = 1; start <= totalDays; start++)
	{
		if (a == 7)
		{
			cout << endl;
			a = 0;
		}
		cout << start << " ";
		a++;
	}

	for (int zeroLast = 7 - a; zeroLast > 0; zeroLast--)
	{
		cout << "0 ";
	}
}

void myDate::printCalendarOfMonth() const
{
	CalendarOfMonth(y, m);
}

ostream &operator <<(ostream &outStream, const myDate& date)
{
	if (date.d < 10)
		cout << '0';
	cout << date.d << '/';

	if (date.m < 10)
		cout << '0';
	cout << date.m << '/';

	cout << date.y;

	return outStream;
}

istream &operator >>(istream &inStream, myDate& date)
{
	int year, month, day;
	inStream >> year >> month >> day;

	date.d = day;
	date.m = month;
	date.y = year;

	return inStream;
}


myDate operator +(int num, const myDate& date)
{
	return date.operator +(num);
}

int myDate::operator-(const myDate& date) const
{
	return daySum(y, m, d) - daySum(date.y, date.m, date.d);
}

int myDate::daySum(int year, int month, int day) const
{
	int sum = 0;
	sum += (year - 1) / 4;
	sum -= (year - 1) / 100;
	sum += (year - 1) / 400;
	sum += (year - 1) * 365;

	sum += DayOfYear(year, month, day);

	return sum;
}

myDate myDate::operator+(int num) const
{
	int sum = daySum(y, m, d) + num;
	myDate Date = sumToDate(sum);

	if (Date.y < 1582)
		Date.setDate(1582, 1, 1);

	return Date;
}

myDate myDate::sumToDate(int num) const
{
	int y = 0;
	int n;
	myDate date;

	y += (num / 366);
	n = num % 366;

	n += y;
	n -= y / 4;
	n += y / 100;
	n -= y / 400;

	while (1)
	{
		if (n == 366)
		{
			if (LeapYear(y + 1))
			{
				break;
			}
		}
		else if (365 > n)
		{
			break;
		}

		if (LeapYear(y + 1))
		{
			y++;
			n -= 366;
		}
		else
		{
			y++;
			n -= 365;
		}
	}

	if (n == 0)
	{
		date.y = y;
		date.m = 12;
		date.d = 31;
		return date;
	}
	else
	{
		for (int a = 1; a <= 12; a++)
		{
			int day;

			switch (a)
			{
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				day = 31;
				break;
			case 2:
				if (LeapYear(y + 1))
					day = 29;
				else
					day = 28;
				break;
			default:
				day = 30;
			}

			if (n < day)
			{
				date.y = y + 1;
				date.m = a;
				date.d = n;
				break;
			}
			else
				n -= day;
		}
		return date;
	}
}

myDate myDate::operator -(int num) const
{
	int sum = daySum(y, m, d) - num;
	myDate Date = sumToDate(sum);

	if (Date.y < 1582)
		Date.setDate(1582, 1, 1);

	return Date;
}

myDate& myDate::operator++()
{
	int sum = daySum(y, m, d) + 1;
	myDate Date = sumToDate(sum);

	setDate(Date.y, Date.m, Date.d);

	return *this;
}

myDate& myDate::operator--()
{
	int sum = daySum(y, m, d) - 1;
	myDate Date = sumToDate(sum);

	setDate(Date.y, Date.m, Date.d);

	return *this;
}

myDate myDate::operator++(int)
{
	myDate returnVal(y, m, d);
	int sum = daySum(y, m, d) + 1;
	myDate Date = sumToDate(sum);

	setDate(Date.y, Date.m, Date.d);

	return returnVal;
}

myDate myDate::operator--(int)
{
	myDate returnVal(y, m, d);
	int sum = daySum(y, m, d) - 1;
	myDate Date = sumToDate(sum);

	setDate(Date.y, Date.m, Date.d);

	return returnVal;
}

myDate& myDate::operator = (const myDate& date)
{
	y = date.y;
	m = date.m;
	d = date.d;

	return *this;
}

myDate& myDate::operator += (int num)
{
	*this = *this + num;

	return *this;
}

myDate& myDate::operator -= (int num)
{
	*this = *this - num;

	return *this;
}

bool myDate::operator >(const myDate& date) const
{
	if (daySum(y, m, d) > daySum(date.y, date.m, date.d))
		return true;
	else
		return false;
}

bool myDate::operator >=(const myDate& date) const
{
	if (daySum(y, m, d) >= daySum(date.y, date.m, date.d))
		return true;
	else
		return false;
}

bool myDate::operator <(const myDate& date) const
{
	if (daySum(y, m, d) < daySum(date.y, date.m, date.d))
		return true;
	else
		return false;
}

bool myDate::operator <=(const myDate& date) const
{
	if (daySum(y, m, d) <= daySum(date.y, date.m, date.d))
		return true;
	else
		return false;
}

bool myDate::operator ==(const myDate& date) const
{
	if (daySum(y, m, d) == daySum(date.y, date.m, date.d))
		return true;
	else
		return false;
}

bool myDate::operator !=(const myDate& date) const
{
	if (daySum(y, m, d) != daySum(date.y, date.m, date.d))
		return true;
	else
		return false;
}