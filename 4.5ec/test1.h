#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


#define MAXOP 100
#define NUMBER '0'	/* signal that a number was found */
#define NAME 'n'	/* signal that a name was found */
#define MAXVAL 100  /* deep length of stack val */
#define BUFSIZE 100
#define j2h(x) (3.1415926*(x)/180.0) 

int  sp = 0;			/* next free space of stack */
int	 bufp = 0;			/* next free space of  buf */
char buf[BUFSIZE];		/* buffer space for unget func */
double val[MAXVAL];		/* the stack to put values */

int getop(char[]);
int getch(void);
void push(double);
double pop(void);
void mathfunc(char[]);
void  ungetch(int);




