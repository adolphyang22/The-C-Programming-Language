#include "test1.h"

/* strindex: return index of t in s, -1 of none */
int strindex_test(char *s, char *t)
{
	char *b = s;	/* begining of string s */
	char *p, *r;

	for (; *s != '\0'; s++)
	{
		for (p = s, r = t; *r != '\0' && *p == *r; p++, r++) 
			;
		if (r > t && *r == '\0') //表示t从第一位到最后一位都在s中逐序对应，找到了t在s中的位置
			return s - b;
	}

	return -1;
}
