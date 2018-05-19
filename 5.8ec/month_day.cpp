#include "test1.h"

/* month_day：将一年的第几天转换为月/日 */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	if (year < 1) {
		*pmonth = -1;
		*pday = -1;
		return;
	}

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];

	if (i > 12) { 
		*pmonth = -1;
		*pday = -1;
	}
	else {
		*pmonth = i;
		*pday = yearday;
	}
}
