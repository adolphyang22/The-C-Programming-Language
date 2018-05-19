/* 5.6ec需求: 用指针代替数组下标，重写getline/atoi/itoa/strindex/gettop函数 */

#include "test1.h"

//getline函数指针版本测试(获取输入的一行，存入指针中并显示长度)
#if 0
int main()
{
	char *s;
	int i;
	char b = '0';

	s = &b;	//指针在使用前一定要初始化

	i = getline_test(s, 100);

	printf("s=%s\n", s);
	printf("i=%d\n", i);

	scanf_s("%d\n", &i);
	return 0;

}
#endif

//atoi函数指针版本测试(字符串转换为int型)
#if 0
int main()
{
	char *s = "-123345";
	int i = 0;

	i = atoi_test(s);

	printf("i=%d\n", i);

	scanf_s("%d\n", &i);
	return 0;
}
#endif

//itoa函数指针版本测试(int型转换为字符串)
#if 0
int main()
{
	char *s = NULL;
	int i = 345;
	char k[10] = {'0'};
	
	s = k;

	itoa_test(i ,s);

	printf("s=%s\n", s);

	scanf_s("%d\n", &i);
	return 0;
}
#endif

//atof函数指针版本测试(将字符串转换为float型)
#if 0
int main()
{
	char *s = NULL;
	double i = 0;
	char k[10] = {"1234.567"};

	s = k;

	i = atof_test(s);

	printf("i=%lf\n", i);

	scanf_s("%d\n", &i);
	return 0;
}
#endif

//strindex函数指针版本测试(返回t在s中位置)
#if 0
int main()
{
	char *s = NULL;
	char *t = NULL;
	char k[10] = "1234567";
	char i[10] = "123456";
	int j = 1000;

	s = k;
	t = i;

	j = strindex_test(k, i);

	printf("j=%d\n", j);

	scanf_s("%s\n", &i, 4);
	return 0;
}
#endif

#if 1
int main()
{
	char s[100];
	char c = 0;

	while ((c = getop_test(s)) != EOF)
	{
		if (c == '\n')
			printf("s=%s\n", s);
	}

	scanf_s("%s\n", &c, 4);
	return 0;
}
#endif 
