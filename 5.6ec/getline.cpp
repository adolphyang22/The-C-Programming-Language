#include "test1.h"

/* getline: read a line into s, return length */
int getline_test(char *s, int lim)	//输入参数是一个指向字符数组的指针
{
	int c;
	char *t = s;	//指针s将指向字符数组的第一个字符，这个地址将被保存在指针t中

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;

	if (c == '\n')
		*s++ = c;

	*s = '\0';
	return s - t;
}
