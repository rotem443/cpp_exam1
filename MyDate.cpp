#include "MyDate.h"
#include <string> 


/*
 This function Check if the day, month and year is valid.
 Return true if valid, else false.
*/
bool MyDate::isValidDate(int day, int month, int year)
{	
	// Check if the date is valid
	return isValidMonth(month) && isValidYear(year) && isValidDay(day, month);
}

/*
 Check if the day is valid.
 Febuary is between 1-28 else it between 1-30
*/
bool MyDate::isValidDay(int day, int month)
{
	// Check if the it febuary and between 1-28 or not febuary and between 1-30
	return ((day > 0) && ((month == 2 && day <= 28) || (month != 2 && day <= 30)));
}

/*
 Check if month between 1-12
*/
bool MyDate::isValidMonth(int month)
{
	// Check if the month is valid
	return (month >= 1 && month <= 12);
}

/*
	Check if year is valid between 1900-2100	
*/
bool MyDate::isValidYear(int year)
{
	return (year >= 1900 && year <= 2100);
}

/*
Function add or remove days 
update and return 0 it it valid,
otherwise -1 and not update
*/
int MyDate::addDays(int days)
{
	if (days <= 358 && days >= -358)
	{
		int newYear;
		int newMonth;
		int newDay;
		int timeInDays;
		
		timeInDays = this->_year * 358;
		timeInDays += this->_month * 30;

		// feb have 2 days less
		if (this->_month > 2)
		{
			timeInDays -= 2;
		}

		timeInDays += this->_day;

		// add the new days (if minus or plus)
		timeInDays += days;

		// not floor number
		newYear = (timeInDays / 358);

		// get the floor number
		timeInDays -= (newYear * 358);

		// after feb cause i dont remove 1 month
		if (timeInDays > 88)
		{
			timeInDays += 2;
		}

		newMonth = (timeInDays / 30);
		timeInDays -= (newMonth * 30);

		newDay = timeInDays;

		/// check if not after the date that it could be
		if (isValidDate(newDay, newMonth, newYear))
		{			
			this->_day = newDay;
			this->_month = newMonth;
			this->_year = newYear;

			return 0;
		}
	}
	
	return -1;
}

/*
Update the date to 0
*/
void MyDate::DateZero()
{	
	this->_day = 0;
	this->_month = 0;
	this->_year = 0;
}

/*
	Defult ctor empty date
*/
MyDate::MyDate()
{
	this->_year = 0;
	this->_month = 0;
	this->_day = 0;
}

/*
	Ctor with all date parameters
*/
MyDate::MyDate(int day, int month, int year)
{
	if (isValidDate(day, month, year))
	{
		this->_day = day;
		this->_month = month;
		this->_year = year;
	}
	else
	{
		DateZero();
	}
}

/*
	init the date to the day
*/
void MyDate::init()
{
	this->_day = 20;
	this->_month = 4;
	this->_year = 2017;
}

/*
	Set The date by the params
*/
int MyDate::set(int day, int month, int year)
{
	int toReturn = 0;

	// Check if the date is valid	
	if (isValidDate(day, month, year))
	{
		this->_day = day;
		this->_month = month;
		this->_year = year;		
	}
	else
	{
		toReturn = -1;
	}

	return toReturn;
}

/*
	Set the day of the date by the param
*/
int MyDate::setDay(int day)
{	
	// Check if the day is valid
	if (isValidDay(day, this->_month))
	{
		this->_day = day;

		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set the month of the date by the param
	check if the date valid
*/
int MyDate::setMonth(int month)
{
	// Check if the month is valid and the dat is valid
	if (isValidMonth(month) && isValidDay(this->_day, month))
	{
		this->_month = month;

		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set the year of the curr date
*/
int MyDate::setYear(int year)
{
	if (isValidYear(year))
	{
		this->_year = year;
		
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Find the first date 
*/
bool MyDate::isBefore(const MyDate& newDate)
{
	// Check for same years
	if (this->_year != newDate._year)
	{
		// return true if on this object the year is earlier
		return (this->_year < newDate._year);
	}
	// if same year and not same month
	else if (this->_month != newDate._month)
	{
		// return true if the month eariler
		return (this->_month < newDate._month);
	}
	// if same year and month
	else
	{
		return (this->_day < newDate._day);
	}

}

/*
	make the dates be more late by num days
*/
int MyDate::delay(int num)
{	
	return addDays(num);
}

/*
	 make the dates be more earlier by num days
*/
int MyDate::bringForward(int num)
{	
	return addDays(-1 * num);
}

/*
	return string by format "DD/MM/YYYY"
*/
char* MyDate::print()
{	
	// Creating string variables to the date variables  
	std::string str_day = std::to_string(this->_day);
	std::string str_month = std::to_string(this->_month	);
	std::string str_year = std::to_string(this->_year);


	//Concreate all the the sting together with '/' between them
	std::string str_date = "";
	str_date = str_day + "/" + str_month + "/" + str_year;


	//Copy and then Access the string char array
	char *cstr = new char[str_date.length() + 1];
	
	for (int i = 0; i<str_date.length() + 1; i++)
	{
		cstr[i] = str_date[i];
	}

	return cstr;
}