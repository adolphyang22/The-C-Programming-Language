#include "test1.h"
/* day_of_year：从月/日转换为一年的第几天 */

int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = year%4 == 0 && year%100 != 0 || year % 400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];

	return day;
}
