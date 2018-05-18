/* 5.2ex: 从缓冲区中获取输入和压回缓冲区 */
#include "test1.h"

char buf[BUFSIZE];		/* 供ungetch使用的缓冲区 */
int bufp = 0;			/* buf的下一个空闲位置 */

int getch(void)				/* 取一个字符(可能是压回的字符) */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

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
