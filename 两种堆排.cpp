#include<bits/stdc++.h>
using namespace std;
int R = 0;

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

int heap1_down(int p[])
{
	int ret = p[1],last= p[p[0]--];
	int i, child;
	for (i = 1; i * 2 <= p[0]; i = child) {
		child = i * 2;
		if (child + 1 <= p[0] && p[child] > p[child + 1])
			child++;
		if (last < p[child])break;
		else p[i] = p[child];
	}
	p[i] = last;
	return ret;
}

void heap1_up(int p[], int add)
{
	int i = ++p[0];
	for (; i > 1 && p[i / 2] > add; i = i / 2)
		p[i] = p[i / 2];
	p[i] = add;
}

void heap1(int a[], int n)
{
	int* p = new int[n + 1];
	p[0] = 0;
	for (int i = 0; i < n; i++)
		heap1_up(p, a[i]);
	for (int i = 0; i < n; i++)
		a[i] = heap1_down(p);
}

void heap2_down(int a[], int last)
{
	int  curr = a[last];
	swap(a[0], a[last]);
	int i = 0, child;
	for (; i * 2 + 1 < last; i = child) {
		child = i * 2 + 1;
		if (child + 1 < last && a[child] < a[child + 1])
			child++;
		if (curr > a[child])break;
		else a[i] = a[child];
	}
	a[i] = curr;
	
}

void heap2_up(int a[], int idx)
{
	int i = idx, add = a[idx];
	for (; i && a[(i - 1) / 2] < add; i = (i - 1) / 2)
		a[i] = a[(i - 1) / 2];
	a[i] = add;
}

void heap2(int a[],int n)
{
	for (int i = 1; i < n; i++)
		heap2_up(a, i);
	for (int i = n; i > 0; i--)
		heap2_down(a, i - 1);
}

int main()
{
	int tts[] = { 3,7,6,5,4,0,2,9 };
	int n = sizeof(tts) / sizeof(tts[0]);
	printf("初始化数组为:");
	display(tts, n);

	heap1(tts, n);
	printf("排序后数组为:");

	display(tts, n);
	return 0;
}