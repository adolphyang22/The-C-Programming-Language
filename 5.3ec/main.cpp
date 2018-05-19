/* 5.3ec需求: 编写 strcat函数的指针版本，strcat(s,t)将字符串t复制到s的末尾处
              解决方案: 两个指针分别指向两个字符串，指向字符串s的指针先循环到字符串末尾，
		       再循环将指向字符串t的指针逐位附加到字符串s指针的末尾，直到指向字符串t的指针指向字符串结束符
		       最后打印指针即可得到拼接后的值
输出: hello,world!  (原字符串是常量, 分配在静态变量区, 内容不会变
                     定义的a/b数组变量分配在栈区, 函数运行时自动分配内存, 拼接时变的是数组存储空间内的内容*/

#include "test1.h"

int main()
{
	char a[15] = {0};
	char b[15] = {0};

	strcpy_s(a, "hello,");
	strcpy_s(b, "world!");

	printf("&a=%p\n", &a); //查看数组首地址即指针在栈中的内存地址
	printf("a=%s\n", a);   //查看数组中存放的内容
	printf("*a =%c\n", *a); //查看数组首地址即指针当前存放的内容
	printf("&b=%p\n", &b);  //变量a先定义，先入函数栈，在高地址，b后入函数栈，在低地址
	printf("b=%s\n", b);   
	printf("*b =%c\n", *b); 


	stract1(a, b);

	printf("a=%s\n", a);

	scanf_s("%c\n", &a, sizeof(a));
	return 0;

}

