#include "test1.h"
/* day_of_year：从月/日转换为一年的第几天 */
//增加错误检查

int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	if (month < 1 || month > 12)
		return -1;

	if (day < 1 || day > daytab[leap][month])
		return -1;

	for (i = 1; i < month; i++)
		day += daytab[leap][i];

	return day;
}
