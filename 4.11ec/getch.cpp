#include <stdio.h>

#define BUFSIZE 100

static char buf[BUFSIZE];		/* 供ungetch使用的缓冲区 */
static int bufp = 0;			/* buf的下一个空闲位置 */

int getch(void)				/* 取一个字符(可能是压回的字符) */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

#if 0
void ungetch(int c)			/* 将字符压回输入中 */
{
	if (bufp >= BUFSIZE)
	{
		printf(" ungetch:压回字符过多\n");
	}
	else
	{
		buf[bufp++] = c;
	}
}
#endif
