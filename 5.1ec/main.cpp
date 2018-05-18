/*5.1ex需求: 5.2ex中若getint输入的单独+/-(不带数字的单个符号)，则即为0，修正，遇到单个+/-时压回到输入中
			 解决方案: 修改getint函数, 遇到符号字符时保存到变量d中并读入下一个字符，
			           若下一个字符既不是数字也不是EOF, 则将新读入的字符压回输入缓冲区，
					   再将保存在d中的符号压回，并返回符号并表明情况
输入: +1
      -2
	  -123
输出: array[0]=1
	  array[1]=-2
	  array[2]=-123
	  array[3]=0
	  ....
输入: +
输出: array[0]=0
	  .... (若输入单个符号则返回修正) */

#include "test1.h"

/* 将输入的char型转换为int存放在数组中 */
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
