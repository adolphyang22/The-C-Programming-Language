#include <stdio.h>
#include <string.h>
#include <math.h>	/* for fmod()*/
#include <stdlib.h>	/* for atof() */
#include <ctype.h>

#define MAXOP 100			/* max size of  operand or operator */
#define NUMBER '0'			/* signal that a number was found */
#define MAXVAL 100			/* max deep for stack val */
#define BUFSIZE 100

int sp = 0;					/* 栈的下一个空闲位置 */
int bufp = 0;				/* buf中的下一个空闲位置 */
char buf[BUFSIZE];			/* 供unget函数使用的缓冲区 */
double val[MAXVAL];			/* 存放值的栈 */


int getop(char[]);
int getch(void);
void ungetch(int);
void clear(void);
void push(double);
double pop(void);


