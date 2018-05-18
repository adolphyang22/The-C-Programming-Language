#include "test1.h"

#if 0
/* strcpy: 将t复制到s； 数组下标版本 */
void strcpy(char *s, char *t)
{
	int i;

	i = 0;
	while ((s[i] = t[i]) != '\0')
		i++;
}
#endif

#if 0
/* strcpy: 将t复制到s； 指针版本1 */
void strcpy(char *s, char *t)
{
	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
}
#endif

#if 0
/* strcpy: 将t复制到s； 指针版本2 */
void strcpy(char *s, char *t)
{
	while ((*s++ = *t++) != '\0')	//先取指针t当前指向的字符放入指针s指向的位置，再指针t和s均移向下一位置，
		                            //由于前面是表达式，!='\0'的判断多余
		;
}
#endif

#if 1
/* strcpy: 将t复制到s； 指针版本3 */
void strcpy(char *s, char *t)
{
	while (*s++ = *t++)		//将字符从t复制到s，直到包含t结尾的'\0'为止
		;
}
#endif
