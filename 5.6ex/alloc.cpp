#include "test1.h"

char *alloc(int n)	/* 返回指向n个字符的指针 5.4ex */
{
	if (allocbuf + ALLOCSIZE - allocp >= n){	/* 满足 */
		allocp += n;
		return allocp - n;	/* 分配前p所指的位置 */
	}
	else
		return 0;
}
