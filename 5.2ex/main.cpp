/* 5.2ex: 将输入的char型转换为int存放在数组中，用数组各元素地址做指针来承接输入转换后的char型
输入: 1
      12
	    123   ( WINDOWS调试时，按enter换新行，再按Ctrl+Z，再换新行，代表结束符EOF )
输出: array[0]=1
      array[1]=12
	    array[2]=123
	    array[3]=0
	    .....  (输入只有3行，后续全为初始值)*/

#include "test1.h"

int main()
{
	int n, array[SIZE];
	
	memset(array, 0x00, sizeof(array));

	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		;

	for (n = 0; n < SIZE; n++)
	{
		printf("array[%d]=%d\n", n, array[n]);
	}

	scanf_s("%d\n", &n);
	return 0;
}

