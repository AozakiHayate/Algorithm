#include<bits/stdc++.h>
using namespace std;

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void display(int a[], int n) {

	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
void mid3(int a[], int low, int high)
{
	int mid = (low + high) / 2;
	if (a[mid] > a[high])swap(a[mid], a[high]);
	if (a[low] > a[high])swap(a[low], a[high]);
	if (a[mid] > a[low])swap(a[mid], a[low]);

}

void quick_r(int a[], int s, int e)
{
	if (s >= e) return;
	mid3(a,s,e);
	int i = s, j = e, x = a[s];
	while (i < j)
	{
		while (i<j && a[j]>x)j--;
		if (i < j)a[i++] = a[j];
		while (i<j && a[i]<x)i++;
		if (i < j)a[j--] = a[i];
	}
	a[i] = x;
	if (s < i - 1)quick_r(a, s, i - 1);
	if (e > i + 1)quick_r(a, i + 1, e);
}

void quick0(int a[], int n)
{
	quick_r(a, 0, n - 1);
}

void merge(int a[],int s,int m,int e,int p[])
{
	int i = s, j = m + 1, k = 0;
	while (i <= m && j <= e)
	{
		if (a[i] < a[j])p[k++] = a[i++];
		else p[k++] = a[j++];
	
	}
	while (i <= m) p[k++] = a[i++];
	while (j<=e) p[k++] = a[j++];


	for (i = 0; i < k; i++)
	{
		a[s + i] = p[i];
	}
	
}

void merge_r(int a[],int s,int e,int p[])
{
	if (s >= e) return;
	int m = (s + e) / 2;
	merge_r(a, s, m, p);
	merge_r(a, m + 1, e, p);
	merge(a,s,m,e,p);

}


void merge_sort(int a[], int n)
{
	int* p = new int[n];
	merge_r(a, 0, n - 1, p);

}


int main() {
	int test[] = { 3,7,6,5,4,0,2,9,1,8 };
	int n = sizeof(test) / sizeof(test[0]);
	printf("初始化数组为:");
	display(test, n);
	merge_sort(test, n);
	printf("排序后数组为:");

	display(test, n);
	return 0;
}