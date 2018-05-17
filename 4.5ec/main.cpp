#include "test1.h"

/* 4.5ec需求: 给逆波兰计算器程序增加访问sin、cos、exp与pow库函数的操作。
输入: 1.5707963 sin
输出: 1  (pi/2值约等于1.5707963，由于math.h提供的sin函数接口入参是弧度制，
          可以自行定义宏先将入参的角度值转换为弧度值再计算#define j2h(x) (3.1415926*(x)/180.0) )
输入: 0 cos
输出: 1  (cos0的值等于1)
输入: 1 exp
输出: 2.7182818  (math.h提供的exp函数对自然常数e求幂)
输入: 2 3 pow
输出:8  (math.h提供的pow函数求入参1的入参2次幂)  */

/* reverse Polish calculator */
int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF)
	{
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case NAME:
			mathfunc(s);
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


/* mathfunc: check string s for supported math functions */
void mathfunc(char s[])
{
	double op2;
	if (strcmp(s, "sin") == 0)
		//push(sin(j2h(pop())));   //为角度值计算正弦时可使用j2h宏转换入参 
		push(sin(pop()));
	else if (strcmp(s, "cos") == 0)
		//push(cos(j2h(pop())));  //为角度值计算余弦时可使用j2h宏转换入参 
		push(cos(pop()));
	else if (strcmp(s, "exp") == 0)
		push(exp(pop()));
	else if (strcmp(s, "pow") == 0) 
	{
		op2 = pop();
		push(pow(pop(), op2)); //函数入参从左往右入栈，若直接pow(pop(),pop())则先将输入的幂作为底入栈
	}
	else
		printf("error:%s not supported\n", s);
}


/* getop: get next operator, numeric operand, or math func */
int getop(char s[])
{
	int c = 0, i = 0;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if (islower(c))		/* command or NAME */
	{
		while (islower(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c != EOF)
			ungetch(c);		/* went one char too far */
		if (strlen(s) > 1)
			return NAME;	/* >1 char; it is NAME */
		else
			return c;		/* it may be a command */
	}
	if (!isdigit(c) && c != '.')
		return c;			/* not a number */
	if (isdigit(c))			/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')			/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

/* push: 把f压入栈中 */
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

int getch(void)		/* 取一个字符(可能是压回的字符) */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)	/* 将字符压回输入中 */
{
	if (bufp >= BUFSIZE)
	{
		printf("ungetch: 压回字符过多\n");
	}
	else
	{
		buf[bufp++] = c;
	}
}
