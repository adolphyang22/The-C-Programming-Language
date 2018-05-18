/*5.3ex: 返回字符串s的长度
         当一个数组名被传递给函数时，实际传递的是起始元素的位置。在该函数中，对应参数是一个局部变量，
		 因此一个数组名参数是一个指针，即一个存放地址的变量*/

#include "test1.h"

/* strlens: 返回字符串s的长度 */
int strlens(char *s)
{
	int n;

	for (n = 0; *s != '\0'; s++)  //s是一个数组名，作为函数参数中是一个指针，存放数组首位地址
		n++;
	return n;
}

int main()
{
	int i = 0;
	i = strlens("hello,world");

	printf("strlens[]=%d\n", i);

	scanf_s("%d", &i);
	return 0;
}
