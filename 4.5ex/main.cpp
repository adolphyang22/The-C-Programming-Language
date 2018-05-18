/* 4.5ec：组织分割成各文件，计算主控放在main.cpp内，push()和pop()放在stack.cpp内，
                            getop()放在getop.cpp内，getch()和ungetch()放在getch.cpp内
    4.6ec: 将stack.cpp中的全局变量sp和val，getch.cpp中的全局变量buf和bufp， 利用static声明隐藏起来 
           静态声明用于内部变量时产生内部静态变量，内部静态变量是某个特定函数的局部变量，
		   但一直存在，不会随着每次函数调用而产生和消亡 
           内部静态变量提供了仅在单个函数内使用的、连续的存储空间 */

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

