#include "test1.h"

/* getline: 将一行文本读取到s中， 并返回其长度 */
int getline_test(char [], int);

/* readlines: 读取输入行 */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = getline_test(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)  //分配存储空间，每一输入文本行均存放在allocbuf数组中
			return -1;
		else {
			line[len - 1] = '\0'; /* 删除换行符 */
			strcpy_s(p, sizeof(line), line);
			lineptr[nlines++] = p; //lineptr数组指针，每个元素存放的是每一文本行存储空间的首地址
		}
		return nlines;
}

