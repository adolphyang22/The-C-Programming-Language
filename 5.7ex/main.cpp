#include "test1.h"
/* 5.7ex: 二维数组运用，将某月某日转换为某年的第几天或反向转换。 
          解决方案: 用二维数组存储闰年/非闰年每月天数 
输入: 请输入month  day: 4 10
	    请输入年份: 2018
输出: The day_of_year is:100
输入: 请输入年份: 2018
      请输入天数: 100
输出: The month_day is:month=4, day=10  */

/* day_of_year：从月/日转换为一年的第几天 */
#if 0
int main()
{
	int month=0, day=0, year=0;

	printf("请输入month  day:");
	scanf_s("%d  %d\n", &month, &day);
	printf("请输入年份:");
	scanf_s("%d\n", &year);

	day = day_of_year(year, month, day);

	printf("The day_of_year is:%d\n", day);

	scanf_s("%d\n", &day);
	return 0;
}
#endif

/* month_day：将一年的第几天转换为月/日 */
#if 1 
int main()
{
	int year = 0, yearday = 0;
	int a, b;
	int *pmonth, *pday;

	pmonth = &a;
	pday = &b;

	printf("请输入年份:");
	scanf_s("%d\n", &year);
	printf("请输入天数:");
	scanf_s("%d\n", &yearday);


	month_day(year, yearday, pmonth, pday);

	printf("The month_day is:month=%d, day=%d\n", *pmonth, *pday);

	scanf_s("%d\n", pday);
	return 0;
}
#endif
