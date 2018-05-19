#include "test1.h"

/*5.4ec需求: 编写函数strend(a,b)，如果字符串b出现在字符串a的尾部，该函数返回1；否则返回0.
             解决方案: 新定义两个指针指向字符串，先循环指针到字符串末尾，
			       再同时递减指针，比较两个字符串末尾各字符是否相同。注意要排除a出现在b尾部的情况(b比a长)
输出: i=1  (字符串b=lo出现在字符串a=hello的尾部) */

int main()
{
	char a[10];
	char b[10];
	int i=2;

	strcpy_s(a, "hello");
	strcpy_s(b, "lo"); //若b=hhello或b=helloo都返回0

	i=strend(a, b);

	printf("i=%d\n", i);

	scanf_s("%d\n", &i);
	return 0;
}
