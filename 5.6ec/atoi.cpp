#include "test1.h"

/* atoi: convert s to integer; pointer version */
//s[i]等价于*s, s[i++]等于*s++
#if 0
int atoi_test(char *s)
{
	int n, sign;

	for (; isspace(*s); s++)	/* skip white space */
		;
	sign = (*s == '-') ? -1 : 1;

	if (*s == '+' || *s == '-')		/* skip sign */
		s++;

	for (n = 0; isdigit(*s); s++)
		n = 10 * n + *s - '0';

	return sign * n;
}
#endif

/* itoa: convert n to characters in s; poniter version */
#if 0
void itoa_test(int n, char *s)
{
	int sign;
	char *t = s;	/* save pointer to s */ //字符指针t被初始化为指向字符串s的第一个元素

	if ((sign = n) < 0)	/* record sign */
		n = -n;			/* make n positive */

	do {				/* generate digits in reverse order */
		*s++ = n % 10 + '0';	/* get next digit */
	} while ((n /= 10) > 0);	/* delete it */
	
	if (sign < 0)
		*s++ = '-';

	*s = '\0';
	reverse_test(t); //将字符串s反转，因为s指针已指向最后一个字符，入参采用之前记录的指向字符串s第一个字符的指针t
}
#endif

/* atof1: convert string s to double; pointer version */
double atof_test(char *s)
{
	double val, power;
	int sign;

	for ( ; isspace(*s); s++ )
		;
	
	sign = ( *s == '-' ) ? -1 : 1;
	
	if ( *s == '+' || *s == '-' )
		s++;
	
	for ( val = 0.0; isdigit(*s); s++ )
		val = 10.0 * val + (*s - '0');

	if ( *s == '.' )
		s++;

	for ( power = 1.0; isdigit(*s); s++ )
	{
		val = 10.0 * val + (*s - '0');
		power *= 10.0;
	}

	return sign * val / power;
}
