#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: 取下一个运算符或数值操作数 */
int getop(char s[])
{
	int i = 0, c = 0;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if (!isdigit(c) && c != '.' && c != '-')
		return c;		/* 不是数字 */
	if (c == '-')
	{
		if (isdigit(c = getch()) || c == '.')
			s[++i] = c;	/* 负数 */
		else
		{
			if (c != EOF)
				ungetch(c);
			return '-';	/* 负数标志 */
		}
	}
	if (isdigit(c))		/* 收集整数部分 */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/* 收集小数部分 */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
