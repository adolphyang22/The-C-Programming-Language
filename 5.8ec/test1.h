#include <stdio.h>

static char daytab[2][13] = {
	{ 0,	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0,	31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

int day_of_year(int, int, int);
void month_day(int, int, int *, int *); 
