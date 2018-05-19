#include "test1.h"

/* getline: 将一行文本读取到s中， 并返回其长度 */
int getline1(char[], int);

//将输入的文本行存储到由main函数提供的一个数组中，而不是存储到调用alloc分配的存储空间中。改写后函数运行速度加快
/* readlines: 读取输入行 */
int readlines(char *lineptr[], char *linestor,  int maxlines)
{
	int len, nlines;
	char line[MAXLEN];
	char *p = linestor;
	char *linestop = linestor + MAXSTOR;

	nlines = 0;
	while ((len = getline1(line, MAXLEN)) > 0)
		if (nlines >= maxlines || p +len > linestop)
			return -1;
		else {
			line[len - 1] = '\0'; /* 删除换行符 */
			strcpy_s(p, sizeof(line), line);
			lineptr[nlines++] = p;
			p += len;
		}
		return nlines;
}
