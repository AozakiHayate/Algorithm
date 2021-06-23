#include<bits/stdc++.h>
using namespace std;
int Mr = 0, Mer = 0;
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

void Q_r(int a[], int s,int e)
{
	if (s >= e)return;
	int i = s, j = e, x = a[s];
	while (i < j) {
		while (i < j && a[j] >= x)j--;
		if (i < j)a[i++] = a[j];
		while (i < j && a[i] <= x)i++;
		if (i < j)a[j--] = a[i];
	}
	a[i] = x;
	if (s < i - 1)Q_r(a, s, i - 1);
	if (e > i + 1)Q_r(a, i + 1, e);
}
void Qsort(int a[], int n)
{
	Q_r(a, 0,n - 1);
}
void merge(int a[], int s, int m, int e, int p[])
{
	Mer++;
	int i = s, j = m+1,k=0;
	while (i <= m && j <= e) {
		if (a[i] < a[j])p[k++] = a[i++];
		else p[k++] = a[j++];
	}
	while (i <= m)p[k++] = a[i++];
	while (j <= e)p[k++] = a[j++];

	for (i = 0; i < k; i++) {
		a[s + i] = p[i];
	}

}
void merge_r(int a[], int s, int e, int p[])
{
	Mr++;
	if (s >= e)return;
	
	int m = (s + e) / 2;
	merge_r(a, s, m , p);
	merge_r(a, m+1, e, p);
	merge(a, s, m, e, p);
}
void mergesort(int a[], int n)
{
	int* p = new int[n];
	merge_r(a, 0, n - 1, p);
}

void heap2_down(int a[], int last)
{

}
void heap2_up(int a[], int idx)
{

}
void heap2(int a[], int n) {
	for (int i = 0; i < n; i++)
		heap2_up(a, i);
}
int main()
{
	int tts[] = { 3,7,6,5,4,0,2,9 };
	int n = sizeof(tts) / sizeof(tts[0]);
	printf("初始化数组为:");
	display(tts, n);

	mergesort(tts, n);
	printf("排序后数组为:");

	display(tts, n);

	printf("M-sort:%d\n", Mr);
	printf("Merge:%d\n", Mer);
	return 0;
}