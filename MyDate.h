#pragma once
#include <iostream>
#include "string.h"


using namespace std;

class MyDate
{
private:
	int indextest = 0;
	int _day;
	int _month;
	int _year;

	bool isValidDate(int day, int month, int year);
	bool isValidDay(int day, int month);
	bool isValidMonth(int month);
	bool isValidYear(int year);
	int addDays(int days);


public:
	 int getDay() const { return _day; }
	 int getMonth() const { return _month; }
	 int getYear() const { return _year; }

	MyDate();
	MyDate(int day, int month, int year);
	void DateZero();
	void init();
	int set(int day, int month, int year);
	int setDay(int day);
	int setMonth(int month);
	int setYear(int year);
	bool isBefore(const MyDate& newDate);
	int delay(int num);
	int bringForward(int num);
	char* print();
	

	~MyDate() {};
};


