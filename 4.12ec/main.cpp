/* 4.11ec需求: 利用printd思想编写一个递归版本的itoa函数，通过递归调用把整数转换为字符串
                解决方案: 在itoa函数中递归调用itoa, 每次入参取输入int型数除10的各位数值 
输出: 12340  (用%s输出的是将int型数转换为字符串后的值) */

#include "test1.h"

/* itoa: convert(使转变，转换) n to characters in s; recursive(递归的，循环的) */
void itoa(int n, char s[])
{
	static int i;

	if (n / 10)
	{
		itoa(n / 10, s);
	}
	else
	{
		i = 0;
		if (n < 0)
			s[i++] = '-';
	}
	s[i++] = abs(n) % 10 + '0';  /* abs函数在stdlib库内，取n的绝对值 */
	s[i] = '\0';
}

int main()
{
	int i = 1;
	char s[10];

	memset(s, 0x00, sizeof(s) * 10);
	
	itoa(12340, s);

	printf("%s\n", s);

	scanf_s("%d\n", &i);
}
