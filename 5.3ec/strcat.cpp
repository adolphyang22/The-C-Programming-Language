#include "test1.h"

/* strcat: concatenate t to the end of s; pointer version */
void stract1(char *s, char *t)
{
	printf("&s=%p\n", &s); /* 这里查看形参s和t的内存地址，入栈时是指针变量
	                          可看出s的内存地址比在main中打印的入参数组a首地址要小，
				    因为栈空间存放函数变量且向地址下生长，a先入栈在高地址，s后入栈在低地址*/
	printf("&t=%p\n", &t); /* 函数参数入栈顺序从右向左，先入t在高地址，后入s在低地址
	                         t的地址值比s高4位，因为指针在32位系统内存中占4个字节*/


	while (*s)
	{
		printf("&s=%p\n", &(*s)); //查看数组a中"hello,"各元素内存地址，从main.cpp中a的首地址开始递增
		                          //函数栈中分配数组时，数组首地址在内存低位
		s++;                  
	}
	while (*s++ = *t++)
	{
		printf("s=%p\n", s); //这里内存地址值是数组a首地址加字符串"hello,"长度后的地址(比首地址高)
		printf("t=%p\n", t); //这里内存地址值是数组b首地址开始直到数组b字符串结束
	}
}
