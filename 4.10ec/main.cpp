#include "test1.h"

/* 4.10ec需求: 使用getline函数一次性读入整个行，不需要使用getch和ungets函数 
               解决方案：使用getline函数取代getch和ungets函数，
			             引入数组line保存每次读入的一整行输入,变量li是数组line中下一个字符的索引 */

/* 逆波兰运算器 */
int main()
{
	int type = 0;
	double op2 = 0.0;
	char s[MAXOP];			/* 判断输入是否是数字以及是否结束并收集的缓冲区 */

	memset(s, 0x00, sizeof(s));
	memset(buf, 0x00, sizeof(buf));
	memset(val, 0x00, sizeof(val));
	memset(line, 0x00, sizeof(line));

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

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int c = 0, i = 0;

	if (line[li] == '\0')	/* getop函数到达输入行的末尾或者尚未读入第一个输入行，调用getline读入一个输入行 */
		if (getline(line, MAXLINE) == 0)
			return EOF;
		else
			li = 0;

	while ((s[0] = c = line[li++]) == ' ' || c == '\t')
		;
	s[1] = '\0';
	
	if (!isdigit(c) && c != '.')
		return c;		/* not a number */
	i = 0;

	if (isdigit(c))		/* collect integer part */
		while (isdigit(s[++i] = c = line[li++]))
			;
	if (c == '.')		/* collect fraction part */
		while (isdigit(s[++i] = c = line[li++]))
			;
	s[i] = '\0';
	li--;
	return NUMBER;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i, j;

	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
	{
		if (i < lim - 2)
		{
			s[j] = c;		/* line still in bounderies */
			++j;
		}
	}

	if (c == '\n')
	{
		s[j] = c;
		++j;
		++i;
	}
	s[j] = '\0';
	return i;
}

