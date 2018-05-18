/* 5.5ex: 数组/指针版本strcpy, 数组/指针版本strcmp 
输出: iflag=54,a=123456,b=12345,[i>0则a>b, i=0则a=b, i<0则a<b] */

#include "test1.h"

#if 0
int main() //strcpy: 数组下标版本
{
	char a[10], b[10];

	memset(a, 0x00, sizeof(a));
	memset(b, 0x00, sizeof(b));

	strcpy(a, "hello");
	strcpy(b, a);

	printf("b=%s", b);

	scanf_s("%s", &a, 10);
	return 0;

}
#endif

#if 0
int main() //strcpy：指针版本
{
	char *a, *b;
	char *c = "hello!";
	char i = '0';

	a = &i;
	b = &i;

	strcpy(a, c);
	strcpy(b, a);

	printf("b=%s", b);

	scanf_s("%s", a, 10);
	return 0;

}
#endif

#if 1
int main() //strcmp: 数组下标版本
{
	char a[10], b[10];
	int iflag;

	memset(a, 0x00, sizeof(a));
	memset(b, 0x00, sizeof(b));

	strcpy(a, "123456");
	strcpy(b, "12345");

	iflag=strcmp(a, b);

	printf("iflag=%d,a=%s,b=%s [i>0则a>b, i=0则a=b, i<0则a<b]", iflag, a, b);

	scanf_s("%s", &a, 10);
	return 0;

}
#endif
