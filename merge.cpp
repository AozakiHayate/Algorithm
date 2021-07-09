#include<stdio.h>

void merge(int a[], int m, int b[], int n, int c[], int o)
{
	if (o < m + n)
		return;
	int i = 0, j = 0, k = 0;
	while (i < m && j < n)
	{
		if (a[i] < b[j]) c[k++] = a[i++];

		else c[k++] = b[j++];
	}
	while (i < m) c[k++] = a[i++];
	while (j < n) c[k++] = b[j++];
}

int main()
{
	int a[3] = { 1,3,5 }, b[4] = { 2,4,6,8 };
	int c[7];
	int m = 3, n = 4, o = 7;
	merge(a, m, b, n, c, o);
	int i;
	for (i = 0; i < o; i++)
	{
		printf("%d ", c[i]);
	}
	printf("\n");

	return 0;
}

