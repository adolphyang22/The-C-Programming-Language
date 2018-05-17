#include <stdio.h>
#include <math.h>		/* for atof() */
#include <stdlib.h>			/*为了使用atof()函数*/
#include <ctype.h>
#include <string.h>

#define MAXOP 100		/* max size of operand or operator */
#define NUMBER '0'		/* signal that a number was found */
#define MAXVAL 100		/*deep length of stack val */
#define BUFSIZE 100

int		sp = 0;				/*栈的下一个空闲位置*/
int		bufp = 0;			/*buf中的下一个空闲位置*/
char	buf[BUFSIZE];		/*供unget函数使用的缓冲区*/
double	val[MAXVAL];		/*存放值的栈*/

int		getop(char[]);
int		getch(void);
void	push(double);
void	ungetch(int);
double	pop(void);
