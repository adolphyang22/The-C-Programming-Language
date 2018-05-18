/* 4.11ex: 用递归来处理快速排序，先对无序数组选取一个元素，以其为界将其他元素分为左右俩子集，
           子集内分别再递归执行该过程
		   进一步了解常用排序算法原理及实现，知道每种算法复杂度及原因
输出最后结果: 0 1 2 3 4 (每一步递归排序均会打印当前结果)
              0 1 2 3 4 5 6 7 8 9 (原数组规模增大后时间复杂度按O(n*n)规模增加) */

#include "test1.h"

#define MAXNUM 10

/* qsort: 将v[left]....v[right]按递增次序排序,取每个子数组的中间元素进行划分 */
void  qsort(int v[], int left, int right)
{
	int   i, last, j;
	void  swap(int v[], int i, int j);

	for (j = 0; j <= MAXNUM-1; j++)
	{
		printf("s[%d] =%d ", j, v[j]);
	}
	printf("\n");
	if (left >= right)	/* 假如数组元素少于2个 */
		return;			/* 则不做任何操作      */

	swap(v, left, (left + right) / 2);	 /* 将划分元素移动到序列中间 */
	for (j = 0; j <= MAXNUM-1; j++)
	{
		printf("s[%d] =%d ", j, v[j]);
	}
	printf("\n");
	last = left;						 /* 至子序列的最左边 */

	for (i = left + 1; i <= right; i++)	/* 对其余元素进行划分 */
	{
		if (v[i] < v[left])
		{
			swap(v, ++last, i);
			for (j = 0; j <= MAXNUM-1; j++)
			{
				printf("s[%d] =%d ", j, v[j]);
			}
			printf("\n");
		}
	}

	swap(v, left, last); 

	qsort(v, left, last - 1); //递归对左序列排序，左序列排序内部递归，结束时表明第一次划分的左序列已排序完成
	qsort(v, last + 1, right);//递归对右序列排序，右序列排序内部递归，结束时表明第一次划分的右序列已排序完成
}

/* swap: 将v[i]与v[j]互换 */
void swap(int v[], int i, int j)
{
	int tmp;

	tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

int main()
{
	int i = 0;
    int s[MAXNUM] = { 3,1,9,0,8,6,2,4,5,7 };
	//int s[MAXNUM] = {4,1,0,3,2};

	qsort(s, 0, MAXNUM-1);

	scanf_s("%d", &i); //保证调试窗口不会运行结果后自动关闭，也可在工程右键属性-连接器-系统-子系统中选择控制台模式
	return 0;
}
