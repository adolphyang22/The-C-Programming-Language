#include "test1.h"
/* 5.6ex: 指针数组(指向指针的指针) 每个数组元素都是一个指针，可指向不同的存储内容，
          在做字符串之间排序时可通过切换数组元素的顺序来代替对存储内容的移动排序，效率更高开销内存空间更小 
		  解决方案： step1:读取输入的所有文本行
			    step2:将他们排序 (通过指针数组内数组元素的排序来完成)
			    step3:按照顺序打印出来
输入:       a
	    w
	    ab
	    ad
	    e
输出:       a
            ab
	    ad
	    e
	    w */

char *lineptr[MAXLINES];	/* 指向文本行的指针,包含5000个元素的数组，每一个元素都是指向字符的指针 */

/* 将输入行排序 */
int main()
{
	int nlines;	/* 读入的输入行数 */

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0){
		qsort_test(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
	}else{
		printf("error: input too big to sort\n");
		return 1;
	}	

	scanf_s("%d\n", &nlines);
	return 0;
}

