#include <stdio.h>
#include <stdlib.h>			/*为了使用atof()函数*/
#include <ctype.h>
#include <string.h>
#include <math.h>			/*为了使用fmod()函数*/

#define  MAXOP  100			/*操作数或运算符的最大长度*/
#define NUMBER  '0'			/*标示找到一个数*/
#define MAXVAL 100			/*栈val的最大深度*/
#define BUFSIZE 100
#define MAXLINE	100

int		sp = 0;				/*栈的下一个空闲位置*/
int		bufp = 0;			/*buf中的下一个空闲位置*/
char	buf[BUFSIZE];		/*供unget函数使用的缓冲区*/
double	val[MAXVAL];		/*存放值的栈*/
int		li = 0;             /* input line index 为防止外部变量被getop以外的函数修改，可定义为static型 */
char	line[MAXLINE];		/* one input line 为防止外部变量被getop以外的函数修改，可定义为static型　*/


int		getop(char[]);
void	push(double);
double	pop(void);
int     getline(char line[], int limit);
