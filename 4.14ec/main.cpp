/* 4.14需求: 定义宏swap(t,x,y), 以交换t类型的两个参数 
输出: x=4309405809, y=342342 */

#include "test1.h"

#define swap(t, x, y)	{	t  _z;\
							_z = y;\
							y = x;\
							x = _z;}

int main()
{
	char *x, *y;

	x = "342342";
	y = "4309405809";

	swap(char *, x, y);

	printf("x=%s, y=%s\n", x, y);

	scanf_s("%d\n", &x);
	return 0;
}
