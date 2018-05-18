/* 5.4ex: 模仿堆动态分配内存*/

#include "test1.h"

char *alloc(int n)	/* 返回指向n个字符的指针 */
{
	if (allocbuf + ALLOCSIZE - allocp >= n)	/* 满足 */ //检查是否有足够的空间满足n个字符的请求，
		                                               //若足够则allocp的新值最多为allocbuf的末尾元素加1
	{
		allocp += n;
		return allocp - n;	/* 分配前p所指的位置 */	//返回指向一整段字符的起始位置的指针(因为函数定义是char*型)
	}
	else  /* 没有足够空间 */
	{	
		return 0;	//零值不是一个有效的数据地址，因此返回零值可作为异常事件的信号
		//指针与整数不能互换。零值是唯一的例外，零值常量可以被赋给一个指针，而指针可以与零值常量相比较。
		//零值常用符号常量NULL替换，更清晰的标示出这是用于指针的特殊赋值
	}
}

void afree(char *p)		/* 释放p指向的存储 */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
	{
		allocp = p;
	}
}
