#include "Calendar.h"


int Calendar::putValue(const MyDate & newDate, int num)
{
	// Check if the num smaller than the array size and bigget than zero	
	if (num >=0 && num < ArraySize)
	{		
		myDateList[num].set(newDate.getDay(), newDate.getMonth(), newDate.getYear());
		return 0;
	}
	
	return -1;
}

int Calendar::setDate(const MyDate & newDate, int num)
{
	// Check if the num smaller than zero or bigger than array size
	if (num <= 0 || num > ArraySize)
	{		
		return -1;
	}
	
	myDateList[num-1].set(newDate.getDay(), newDate.getMonth(), newDate.getYear());
	
	return 0;
}

bool Calendar::isFree(int num)
{
	// Check if num bigger than zero and smaller equal than array size
	if (num >= 1 && num <= ArraySize)
	{
		MyDate date;
		
		// Check if defualt time is same or before the area
		if (myDateList[num-1].getDay() == date.getDay() &&
			myDateList[num-1].getMonth() == date.getMonth() &&
			myDateList[num-1].getYear() == date.getYear())
		{			
			return true;
		}
		
	}
	
	return false;
}

int Calendar::firstFree()
{
	// Go over the size of array
	for (int i = 1; i <= ArraySize; i++)
	{
		if (isFree(i))
		{
			return i;
		}
	}
	return -1;
}

int Calendar::insert(const MyDate & newDate)
{
	int FirstIndex = firstFree();

	// Check if the first index different from -1
	if (FirstIndex != -1)
	{
		setDate(newDate, FirstIndex);
	}

	return FirstIndex;
}

int Calendar::oldest()
{	
	int index = 0;
	MyDate date = myDateList[index];

	// Go over each date in the calender
	for (int i = 1; i <= ArraySize; i++)
	{
		// if is free value
		if (isFree(i))
		{
			return -1;
		}
		else
		{
			if (myDateList[i-1].isBefore(date))
			{
				date = myDateList[i-1];
				index = i;
			}
		}
	}
	return index;
}

int Calendar::datesNum(const MyDate& newDate)
{	
	int count = 0;
	for (int i = 1; i <= ArraySize; i++)
	{
		MyDate dates = newDate;
		if (myDateList[i-1].getDay() == dates.getDay() &&
			myDateList[i-1].getMonth() == dates.getMonth() &&
			myDateList[i-1].getYear() == dates.getYear())
		{
			count++;
		}
	}
	return count;
}

void Calendar::deleteAll()
{
	
	for (int i = 1; i <= ArraySize; i++)
	{
		deleteDate(i);
	}
}

int Calendar::deleteDate(int num)
{
	
	if (num >= 1 && num < ArraySize)
	{		
		myDateList[num-1].DateZero();
		
		return  0;
	}
	else
		
		return -1;
}

char* Calendar::print() {
	int i;		
	MyDate newDate;	
	std::string empty_str = "";
	empty_str = "Empty Calendar";
	
	//If all of number of dates that are equal to 0 is 30 then all
	// the array is empty
	if (datesNum(newDate) == ArraySize) {
		
		//Copy and then Access the string char array
		char *cstr2 = new char[empty_str.length() + 1];
		for (i = 0; i < empty_str.length() + 1; i++)
			cstr2[i] = empty_str[i];
		return cstr2;
	}


	//The array is not empty
	else {
		
		std::string calendar_str = "";
		
		//Go over all the array and making the string of the calendar
		for (int i = 1; i <= ArraySize; i++) {
			
			//Making sure the current date is not empty
			if (isFree(i) == false)
				calendar_str = calendar_str + myDateList[i-1].print()+ " ";
		}
		
		//Copy and then Access the string char array
		char *cstr = new char[calendar_str.length()];
		
		// Go over the calendar
		for (i = 0; i < calendar_str.length()-1; i++)
			cstr[i] = calendar_str[i];
		cstr[calendar_str.length()-1] = '\0';
		return cstr;
	}
}

void Calendar::sortDates()
{	
	int i, j;
	for (i = 1; i<ArraySize; ++i)
	{
		for (j = 0; j<(ArraySize - i); ++j)
			if (myDateList[j + 1].isBefore(myDateList[j]))
			{
				MyDate tmp = myDateList[j];
				myDateList[j] = myDateList[j + 1];
				myDateList[j + 1] = tmp;

			}
	}

	bool isThereEmpty = true;
	
	while (isThereEmpty)
	{
		if (isFree(1))
		{
			MyDate tmp = myDateList[0];
			for (i = 0; i < ArraySize - 1; ++i)
			{
				myDateList[i] = myDateList[i + 1];
			}
			myDateList[ArraySize - 1] = tmp;
		}
		else
		{
			isThereEmpty = false;
		}
	}
}

