#include "test1.h"

/* 5.7ec需求: 重写函数readlines，将文本行存放在由main 提供的数组中，而不是调用alloc 来获得存储
              解决方案: 在main.cpp中定义linestor数组，用指针p指向linestor的第一个元素
测试案例同5.6ex */

char *lineptr[MAXLINES];	/* 指向文本行的指针,包含5000个元素的数组，每一个元素都是指向字符的指针 */
char linestor[ALLOCSIZE];

/* 将输入行排序 */
int main()
{
	int nlines;	/* 读入的输入行数 */

	memset(linestor, 0x00, sizeof(linestor));

	if ((nlines = readlines(lineptr, linestor, MAXLINES)) >= 0) {
		qsort_test(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
	}
	else {
		printf("error: input too big to sort\n");
		return 1;
	}

	scanf_s("%d\n", &nlines);
	return 0;
}
