#include "test1.h"

/* 4.6ec需求: 给逆波兰计算器程序增加处理变量的命令(提供26个具有单个英文字母变量名的变量很容易),  
              增加一个变量存放最近打印的值 
输入: 3 A = 2 A +
输出: 5  (3 A = 命令将A的值赋为3, 在本次函数执行结束前可直接使用该变量值)
输入: v 1 +
输出: 6  (上一步执行的结果5压入栈中，遇到v会将v的值赋为5, v 1 + 相当于5+1=6, 在本次执行结束前各变量生命周期将持续	*/

/* reverse Polish calculator */
int main()
{
	int i = 0, type = 0, var = 0;
	double op2 = 0.0, v = 0.0;
	char s[MAXOP];
	double variable[26];

	memset(s, 0x00, sizeof(s));
	memset(buf, 0x00, sizeof(buf));
	memset(val, 0x00, sizeof(val));

	for (i = 0; i < 26; i++)
	{
		variable[i] = 0.0;
	}

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
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '=':
			pop();
			if (var >= 'A' && var <= 'Z')
				variable[var - 'A'] = pop();
			else
				printf("error: no variable name\n");
			break;
		case '\n':
			v = pop();
			printf("\t%.8g\n", v);
			break;
		default:
			if (type >= 'A' && type <= 'Z')
				push(variable[type - 'A']);
			else if (type == 'v')
				push(v);
			else
				printf("error: unknown command %s\n", s);
			break;
		}
		var = type;
	}
	return 0;
}


/* push： put f into stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error:栈满，不能将%g压栈\n", f);
}

/* pop: put out the top of stack */
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


/* getop: get next number or operator */
int getop(char s[])
{
	int i = 0, c = 0;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if (!isdigit(c) && c != '.' && c != '-')
		return c;		/* not number */
	if (c == '-')
	{
		if (isdigit(c = getch()) || c == '.')
			s[++i] = c;	/* negative number */
		else
		{
			if (c != EOF)
				ungetch(c);
			return '-';	/* negative operator */
		}
	}
	if (isdigit(c))		/* collect integer */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/* collect decimal */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}


int getch(void)				/* get one cahracter(maybe come from ungetch) */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)			/* put character c into input */
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
