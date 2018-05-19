#include "test1.h"

/* writelines: 写输入行 */
void writelines(char *lineptr[], int nlines)
{
	int i;

	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);

	//由于lineptr是数组的名字，可按照指针来对待，初始的*lineptr指向第一行，每增加1就使它前进到下一行的指针，
	//同时nlines计数减1
	//for (nlines-- > 0)
	//	printf("%s\n", *lineptr++);
}
