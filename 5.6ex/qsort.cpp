#include "test1.h"

/* qsort: 快速排序, 将v[left]...v[right]排为递增次序 */
void qsort_test(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right)	/* 如果数组元素小于2个 */
		return;		/* 则什么也不做 */

	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0) //对不同输入字符串进行逐位判断大小，例如abd>abc>ab
			swap(v, ++last, i);
	swap(v, left, last);
	qsort_test(v, left, last - 1);
	qsort_test(v, last + 1, right);
}

/* swap: 将v[i]和v[j]互换 */
void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
