#include <stdio.h>

#include <string.h>


#define MAXLINES 5000	/* 能被排序的最大行数 */
#define MAXLEN 1000		/* 任一输入行的最大长度 */
#define ALLOCSIZE 10000	/* 可用空间的大小 */

char *alloc(int);

static char allocbuf[ALLOCSIZE];	/* 用于分配的存储 */
static char *allocp = allocbuf;		/* 头一个空闲的位置 */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort_test(char *lineptr[], int left, int right);




