#include "test1.h"

/* strend: return 1 if string t occurs at the end of s */
int strend(char *s, char *t)
{
	char *bs = s;	/*remember begining of strs */
	char *bt = t;

	for (; *s; s++)		/* end of the string s */
		;
	for (; *t; t++)		/* end of the string t */
		;
	for (; *s == *t; s--, t--)
		if (t == bt || s == bs)		//该条件把t出现在s尾部和s出现在t尾部的两种情况都筛出来了
			break;					/* at the begining of  a str */
	
	if (*s == *t && t == bt && *s != '\0')	/*该条件通过t==bt&&*s!='\0'只筛出了t出现在s尾部的情况，
		                                      排除了s出现在t尾部的情况,但可能s和t相同 */
		return 1;
	else
		return 0;
}
