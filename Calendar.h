#include "MyDate.h"



class Calendar
{
private:
	int indextest = 0;
	const int ArraySize = 30;
	MyDate myDateList[30];
public:
	Calendar() {};
	int putValue(const MyDate& newDate, int num);
	int setDate(const MyDate& newDate, int num);
	bool isFree(int num);
	int firstFree();
	int insert(const MyDate& newDate);
	int oldest();
	int datesNum(const MyDate& newDate);
	void deleteAll();
	int deleteDate(int num);
	char* print();
	void sortDates();

	~Calendar() {};
};

