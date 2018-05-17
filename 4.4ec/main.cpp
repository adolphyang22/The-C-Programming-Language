#include "test1.h"

/* 4.4ec需求: 逆波兰运算器,在4.3ec的基础上添加几个栈操作命令，分别用于在不弹出元素的情况下打印栈顶元素； 
              复制栈顶元素；交换栈顶两个元素的值。另外增加一个命令用于清空栈 
* ?: 打印栈顶元素, d: 复制栈顶元素再压入栈中, s: 交换两个栈顶元素的值， c: 清空栈
输入: 2 3 ? +
输出: 3 (输入为?时不管计算结果，直接打印栈顶元素3)
      5 (?执行一次后失效，继续运算结果并返回)
输入: 3 d +
输出: 6 (d复制栈顶元素值再压入一次，执行后失效，继续运算结果并返回)
输入: 5 3 s -
输出: -2 (原本运算顺序为5-3得2, s将5和3在栈中交换顺序, 变为3-5得-2)
输入: 4 c
输出: 报栈空的错误 (c将栈清空，造成返回无值)  */


/* reverse Polish calculator */
 int  main()
{
	int type = 0;
	double op1 = 0.0, op2 = 0.0;
	char s[MAXOP];		/* 判断输入是否是数字以及是否结束并收集的缓冲区 */

	memset(s, 0x00, sizeof(s));
	memset(buf, 0x00, sizeof(buf));
	memset(val, 0x00, sizeof(val));

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
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push(fmod(pop(), op2));
			else
				printf("error: zero divisor\n");
			break;
		case '?':		/* print top element of the stack */
			op2 = pop();
			printf("\t%.8g\n", op2);
			push(op2);
			break;
		case 'c':		/* clear the stack */
			clear();
			break;
		case 'd':		/* duplicate top elem, of the stack */
			op2 = pop();
			push(op2);
			push(op2);
			break;
		case 's':		/* swap the top two elements */
			op1 = pop();
			op2 = pop();
			push(op1);
			push(op2);
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

/* clear: clear the stack */
void clear(void)
{
	sp = 0;
}

/* push：把f压入栈中 */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error:栈满，不能将%g压栈\n", f);
}

/* pop: 弹出并返回栈顶的值 */
double pop(void)
{
	if (sp > 0)
	{
		return val[--sp];
	}
	else
	{
		printf("error:栈空\n");
		return 0.0;
	}
}

/* getop: 取下一个运算符或数值操作数 */
int getop(char s[])
{
	int i = 0, c = 0;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if (!isdigit(c) && c != '.' && c != '-')
		return c; /* 不是数字 */
	if (c == '-')
	{
		if (isdigit(c = getch()) || c == '.')
			s[++i] = c;  /* 负数 */
		else
		{
			if (c != EOF)
				ungetch(c);
			return '-';	/* 减号标志 */
		}
	}
	if (isdigit(c))		/* 收集整数部分 */
		while (isdigit(s[++i] = c = getch()))
			;
	if(c == '.')		/* 收集小数部分 */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}


int getch(void)			/* 取一个字符（可能是压回的字符）*/
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)		/* 将字符压回输入中 */
{
	if (bufp >= BUFSIZE)
	{
		printf("ungetch:压回字符过多\n");
	}
	else
	{
		buf[bufp++] = c;
	}
}
