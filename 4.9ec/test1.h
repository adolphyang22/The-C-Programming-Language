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
int		bufp = 0;			/* next free position in buf */
int 	buf[BUFSIZE];		/*buffer for ungetch */  /*用char定义的话会导致EOF(-1)存入buf时由0xFFFF转换为0xFF，再由char转换为int时，
													 0xFF可能变成0xFFFF(十进制-1)，也可能转换成0x00FF(十进制255)。 所以若想对EOF处理，
													 则该用int定义buf而不是char */
double	val[MAXVAL];		/*存放值的栈*/


int		getop(char[]);
int		getch(void);
void	push(double);
void	ungetch(int);
double	pop(void);
