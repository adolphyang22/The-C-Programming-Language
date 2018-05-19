#include "test1.h"

/* strncmp: compare at most n characters of t with s */
int strncmp_test(char *s, char *t, int n)
{
	for (; *s == *t; s++, t++)
		if (*s == '\0' || --n <= 0)  //将字符串t和s的前n个字符作比较
			return 0;
	
	return *s - *t;
}
