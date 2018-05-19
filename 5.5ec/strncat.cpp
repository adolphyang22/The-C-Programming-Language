#include "test1.h"

/* strncat: concatenate n characters of t to the end of s */
void strncat_test(char *s, char *t, int n)
{
	void strncpy_test(char *s, char *t, int n);

	strncpy_test(s + strlen(s), t, n);
}
