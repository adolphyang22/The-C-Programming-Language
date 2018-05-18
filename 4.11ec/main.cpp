/* 4.11ec需求: 通过使用内部静态变量， 修改getop函数，使其不再需要使用ungetch函数
               解决方案: 在getop函数中增加一个内部static变量lastc来存放本应该被重新压入输入缓冲区的字符
			             当调用getop函数时，先检查变量lastc中是否保存有前一个字符，若没有则调用getch读取新字符
						 若有则将lastc保存的前一个字符复制到变量c并将静态变量lastc清零
						 getop应先检查完当前字符c后才需要重新读取一个新字符
						 所以对第一个while循环做改动，先判断c是否为空，再调用getch读入新字符 */
             
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "calc.h"

#define  MAXOP  100			/*操作数或运算符的最大长度*/

/* 逆波兰运算器 */
int main()
{
	int type = 0;
	double op2 = 0.0;
	char s[MAXOP];			/* 判断输入是否是数字以及是否结束并收集的缓冲区 */

	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error:除零溢出\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push(fmod(pop(), op2));
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error:未知命令%s\n", s);
			break;
		}
	}
	return 0;
}
