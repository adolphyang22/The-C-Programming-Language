#include <stdio.h>
#include <stdlib.h>			/*为了使用atof()函数*/
#include <ctype.h>
#include <string.h>
#include <math.h>			/*为了使用fmod()函数*/


#define  MAXOP  100			/*操作数或运算符的最大长度*/
#define NUMBER  '0'			/*标示找到一个数*/
#define MAXVAL 100			/*栈val的最大深度*/
#define BUFSIZE 100

int		sp = 0;				/*栈的下一个空闲位置*/
char	buf = 0;		   
double	val[MAXVAL];		/*存放值的栈*/


int		getop(char[]);
int		getch(void);
void	push(double);
void	ungetch(int);
double	pop(void);
