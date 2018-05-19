#include "test1.h"
/* 5.8ec需求: 增加5.7ex中对day_of_year和month_day中错误检查 
输入: 请输入month  day: 12 32
      请输入年份: 2018
输出: 输入数据有误！
输入: 请输入年份: 2018
      请输入天数: 366
输出: 输入数据有误！ */

/* day_of_year：从月/日转换为一年的第几天 */
#if 0
int main()
{
	int month = 0, day = 0, year = 0;

	printf("请输入month  day:");
	scanf_s("%d  %d\n", &month, &day);
	printf("请输入年份:");
	scanf_s("%d\n", &year);

	day = day_of_year(year, month, day);

	if( -1 == day)
		printf("输入数据有误！\n");
	else
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

	if( -1 == *pmonth || -1 ==*pday )
		printf("输入数据有误！\n");
	else
		printf("The month_day is:month=%d, day=%d\n", *pmonth, *pday);

	scanf_s("%d\n", pday);
	return 0;
}
#endif

