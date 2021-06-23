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

void Q_r(int a[], int s, int e)
{
	if (s >= e)
		return;
	int i = s, j = e, x = a[i];
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

void Q_s(int a[], int n)
{
	Q_r(a, 0, n - 1);
}

void Merge(int a[], int s, int m, int e, int p[])
{
	int i = s, j = m + 1,k=0;
	while (i <= m && j <= e)
	{
		if (a[i] < a[j])p[k++] = a[i++];
		else p[k++] = a[j++];
	}
	while(i <= m)p[k++] = a[i++];
	while(j <= e)p[k++] = a[j++];
	for (i = 0; i < k; i++)
	{
		a[s + i] = p[i];
	}
}

void M_r(int a[], int s, int e, int p[])
{
	if (s >= e)return;
	int m = (s + e) / 2;
	M_r(a, s, m, p);
	M_r(a, m + 1, e, p);
	Merge(a, s, m, e, p);
}

void M_s(int a[], int n)
{
	int* p = new int[n];
	M_r(a, 0, n - 1, p);
}

void heap2_up(int a[],int idx) {
	int i=idx,add = a[idx];
	for (; i && a[(i - 1) / 2] < add;i= (i - 1) / 2)
		a[i] = a[(i - 1) / 2];
	a[i] = add;
}
void heap2_down(int a[], int last) {
	int curr = a[last];
	swap(a[0], a[last]);
	int i=0, child;
	for (; i * 2+1 < last; i = child) {
		child = i * 2+1;
		if (child+1<last && a[child] < a[child + 1])
			child++;
		if (curr > a[child])
			break;
		else a[i] = a[child];
	}
	a[i] = curr;

}

void heap2(int a[], int n) {
	for (int i = 0; i < n; i++)
		heap2_up(a, i);
	for (int i = n; i > 0; i--)
		heap2_down(a, i-1);

}
int main()
{
	int tts[] = { 3,7,6,5,4,0,2,9 };
	int n = sizeof(tts) / sizeof(tts[0]);
	printf("初始化数组为:");
	display(tts, n);
	heap2(tts, n);
	printf("排序后数组为:");

	display(tts, n);
	return 0;
}