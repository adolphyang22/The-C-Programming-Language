#include "test1.h"

/* reverse: reverse string s in place */
void reverse_test(char *s)		//指针s的初值指向字符串的第一个字符
{
	int c;
	char *t;

	for (t = s + (strlen(s) - 1); s < t; s++, t--)	//字符指针t的初值指向字符串的最后一个字符(不包括字符结束符'\0')
	{
		c = *s;
		*s = *t;
		*t = c;
	}
}
