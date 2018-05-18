#pragma once
#define NUMBER  '0'			/*标示找到一个数*/

int		getop(char[]);
int		getch(void);
void	push(double);
void	ungetch(int);
double	pop(void);
