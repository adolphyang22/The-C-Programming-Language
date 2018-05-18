#include <stdio.h>

#define ALLOCSIZE 10000		/* 可用空间的大小 */

static char allocbuf[ALLOCSIZE];	/* 用于分配的存储 */

//定义allocp为字符型指针，并初始化为指向allocbuf的开头，这也就是程序一开始时的第一个空闲位置。
//由于数组名也是第0个元素的地址，该声明也可写为
//static char *allocp=&allocbuf[0];
static char *allocp = allocbuf;		/* 头一个空闲的位置，等同于上一行 */	




