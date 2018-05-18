/* 5.2ec需求: 编写getint 的浮点数变体getfloat。getfloat 的函数返回值应为什么类型？
      解决方案: 定义float型数组array, 对浮点数的整数和小数分别读取并转换保存到*pn指向的地址中(array数组元素地址)
			            getfloat返回值为EOF或者紧跟在浮点数后的那个字符的ASCII值，因此应用int类型
输入: 1.0001
      -1.0001
	  +2.333
输出: array[0]=1.000100
	  array[1]=-1.000100
	  array[2]=2.333000
	  array[3]=0.000000
      .....            */
			  
#include "test1.h"		  
			  
/*将输入的char型转换为int存放在数组中 */
int main()
{
	int n;
	float array[SIZE];

	memset(array, 0x00, sizeof(array));

	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
		;

	for (n = 0; n < SIZE; n++)
	{
		printf("array[%d]=%f\n", n, array[n]);
	}

	scanf_s("%d\n", &n);
	return 0;
}
