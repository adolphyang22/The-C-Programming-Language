#include "test1.h"

/* getop: get next operator or numeric operand; pointer ver */
int getop_test(char *s)
{
	int c;

	while ((*s = c = getch_test()) == ' ' || c == '\t')
		;

	*(s + 1) = '\0';	//相当于s[1]='\0',不修改指针取值而实现了相同操作

	if (!isdigit(c) && c != '.')
		return c;	/* not a number */

	if (isdigit(c))	/*collect integer part */
		while (isdigit(*++s = c = getch_test()))
			;

	if (c == '.')
		while ( isdigit(*++s = c = getch_test()) )
			;

	*s = '\0';

	if (c != EOF)
		ungetch_test(c);

	return NUMBER;
}

char buf[BUFSIZE];	/* 供unget函数使用的缓冲区 */
int bufp = 0;		/* buf中的下一个空闲位置 */

int getch_test(void)		/* 取一个字符（可能是压回的字符）*/
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch_test(int c)	/* 将字符压回到输入中 */
{
	if (bufp >= BUFSIZE)
		printf("ungetch:压回字符太多\n");
	else
		buf[bufp++] = c;
}
