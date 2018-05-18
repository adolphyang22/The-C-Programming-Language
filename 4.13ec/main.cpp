#include "test1.h"
/* 4.13ec需求: 编写一个递归版本的reverse(s)函数,将字符串s本身颠倒过来
              该题并不是很适合用递归，用循环可以起到相同效果
输出: 987654321		  */

/*reverse: reverse string s in place */
void reverse(char s[])			//为方便调用，保持reverse函数的用户接口不变，故只有一个入参：字符串s
{
	void reverser(char s[], int i, int len);

	reverser(s, 0, strlen(s));
}

/* reverser: reverse string s in place: recursive */
void reverser(char s[], int i, int len)
{
	int c, j;			//i是指字符串左端算起的索引，j是指字符串从右端算起的索引

	j = len - (i + 1);
	if (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		reverser(s, ++i, len);		//每次调用时字符串左端算起的索引i就加1
	}
}

int main()
{
	char s[10] = "123456789";
	int j = 0;

	reverse(s);

	printf("%s\n", s);

	scanf_s("%d\n", &j);
	return 0;
}

