#include "test1.h"

/*逆波兰运算器,在4.3ex的基础上增加了对取模运算符的处理和增加了对负数的处理.
*先输入数字再输入操作符,
将输入数字依次压栈，遇到+ - * /操作符时将栈顶2个数字弹出栈做相应运算，并将结果压入栈中，遇到换行符将运算结果弹出显示
*输入: 5 3 %
*输出: 2 (运算结果为5对3的取余)
*输入: -2 3 +
*输出: 1 (符号和数字间须紧联，否则会被识别为减操作)*/

/* 逆波兰运算器 */
int main()
{
	int type = 0;
	double op2 = 0.0;
	char s[MAXOP];			/* 判断输入是否是数字以及是否结束并收集的缓冲区 */

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


/* push： 把f压入栈中 */
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
		return c;		/* 不是数字 */
	if (c == '-')
	{
		if (isdigit(c = getch()) || c == '.')
			s[++i] = c;	/* 负数 */
		else
		{
			if (c != EOF)
				ungetch(c);
			return '-';	/* 负数标志 */
		}
	}
	if (isdigit(c))		/* 收集整数部分 */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/* 收集小数部分 */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}


int getch(void)				/* 取一个字符(可能是压回的字符) */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)			/* 将字符压回输入中 */
{
	if (bufp >= BUFSIZE)
	{
		printf(" ungetch:压回字符过多\n");
	}
	else
	{
		buf[bufp++] = c;
	}
}
