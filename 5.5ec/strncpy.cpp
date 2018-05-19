#include "test1.h"

/* strncpy: copy n characters from t to s */
void strncpy_test(char *s, char *t, int n)
{
	while (*t && n-- > 0)	//将t逐字节拷贝到s，直到t到末尾或者n位考完，若t长度大于n，则只拷贝t的前n位到s，s剩下的字符不变
		*s++ = *t++;

	while (n-- > 0)		//如果t长度小于n，则在拷贝完t的字符后直接将s终止
		*s++ = '\0';
}
