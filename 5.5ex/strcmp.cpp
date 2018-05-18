#include "test1.h"

#if 0
/* 如果s<t 返回<0, 如果s==t 返回0，如果s>t 返回>0    数组下标版本 */
int strcmp(char *s, char *t)
{
	int i;

	for (i = 0; s[i] == t[i]; i++)
		if (s[i] == '\0')
			return 0;

	return s[i] - t[i];
}
#endif

#if 1
/* strcmp：如果s<t 返回<0，如果s==t 返回0，如果s>t 返回>0   指针版本 */
int strcmp(char *s, char *t)
{
	for (; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;

	return *s - *t;
}
#endif
