/*5.5ec需求: 编写库函数strncpy、strncat 和strncmp，这些函数只处理它们字符串参数的最多前n 个字符 
             解决方案: 
             strncpy(a,b,n)函数定义2个指针，将b的前10位拷贝覆盖到a的前n位，
			                         若b长度<n则将a终止，b>n时只覆盖a的前n位，a后面不变
                               输出: a=0987654321123  b=0987654321
					   strncat(a,b,n)函数调用strncpy,strncpy入参a将变为strncat入参a+字符串a的长度
					                      即调用strncpy将字符串b复制到字符串a末尾字符之后来实现拼接
					                      输出: a=hello,world!  b=world!
					   strncmp(a,b,n)函数比较a和b的前n个字符，比较前n个字符中第1个不相同的字符，
					                      若a<b返回-1，a>b返回1，a前n个字符等于b或者a长度<n且每个字符都等于b则返回0
					                      输出: i=-1  (a=hello2214,b=hello2233,第一个不相同的字符) */

#include "test1.h"
 
#if 0
int main()    //strncpy版本
{
	char a[20];
	char b[20];

	memset(a, 0x00, sizeof(a));
	memset(b, 0x00, sizeof(b));

	strcpy_s(a, "1234567890123");
	strcpy_s(b, "0987654321");

	strncpy_test(a, b, 10);

	printf("a=%s  ", a);
	printf("b=%s\n", b);

	scanf_s("%s\n", &a, sizeof(a));
	return 0;
}
#endif

#if 0
int main()   //strncat版本
{
	char a[20];
	char b[10];

	memset(a, 0x00, sizeof(a));
	memset(b, 0x00, sizeof(b));

	strcpy_s(a, "hello,");
	strcpy_s(b, "world!");

	strncat_test(a, b, sizeof(b));

	printf("a=%s  ", a);
	printf("b=%s\n", b);

	scanf_s("%s\n", &a, sizeof(a));
	return 0;
}
#endif

#if 1
int main()   //strncmp版本
{
	char a[10];
	char b[10];
	int i = 12345;

	memset(a, 0x00, sizeof(a));
	memset(b, 0x00, sizeof(b));

	strcpy_s(a, "hello2214");
	strcpy_s(b, "hello2233");
	
	i=strncmp(a, b, 10);

	printf("i=%d\n", i);

	scanf_s("%s\n", &a, sizeof(a));
	return 0;
}
#endif
