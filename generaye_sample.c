#include <stdio.h>
#include "libft.h"


void swap(int *x1, int *x2)
{
	int x = *x1;
	*x1 = *x2;
	*x2 = x;
}
void per(int *arr, int st, int ls)
{
	int i;

	i = 0;
	if(st == ls)
	{
		int k;
		for(k = 0; k < ls; k++)
		{
			printf("%d ",arr[k]);
		}
		printf("\n");
	}
	else
	{
		for(i = st; i < ls; i++)
		{
			swap(arr + st,arr + i);
			per(arr,st + 1,ls);
			swap(arr + st,arr + i);
		}
	}
}
//
//int main()
//{
//	int arr[]={44, 79, 85, 73, 33, 19, 1, 23, 76, 40, 83, 39, 100, 51, 58, 12, 41, 67, 72, 77, 9, 92, 97, 91, 11, 96, 34, 57, 43, 95, 26, 13, 24, 62, 32, 69, 52, 47, 54, 20, 89, 94, 70, 66, 74, 37, 15, 22, 63, 38, 93, 84, 98, 55, 80, 42, 50, 82, 75, 78, 61, 7, 81, 35, 6, 87, 8, 71, 18, 99, 14, 45, 68, 53, 5, 90, 4, 21, 2, 48, 27, 16, 64, 65, 31, 28, 3, 86, 30, 25, 59, 56, 60, 17, 36, 10, 29, 88, 46, 49};
//	int st=0;
//	int ls=101;
//	per(arr, st, ls);
//}