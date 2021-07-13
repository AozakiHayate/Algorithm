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

void bubble(int a[], int n)
{
	for (int i = n; i > 1; i--) {
		for (int j = 1; j < i; j++) {
			if (a[j - 1] > a[j])swap(a[j - 1], a[j]);
		}
	}
}

void select(int a[], int n)
{
	
	for (int i = 0; i < n-1; i++) {
		int min=i;
		for (int j = i; j < n-1; j++) {
			if (a[min] > a[j])
				min = j;
		}
		swap(a[i], a[min]);
	}
}
void heap1_up(int p[],int add)
{
	int i = ++p[0];
	for (; i > 1 && add < p[i / 2]; i /= 2)
		p[i] = p[i / 2];
	p[i] = add;
}
int heap1_down(int p[])
{
	int ret = p[1], last = p[p[0]--];
	swap(p[1], p[last]);
	int i, child;
	for (i = 1; i * 2 <= p[0]; i = child) {
		child = i * 2;
		if (child + 1 <= p[0] && p[child + 1] < p[child])
			child++;
		if (last < p[child])break;
		else p[i] = p[child];
	}
	p[i] = last;
	return ret;
}

void heap1(int a[], int n)
{
	int* p = new int[n + 1];
	p[0] = 0;
	for (int i = 0; i < n; i++)
		heap1_up(p, a[i]);
	for (int j = 0; j < n; j++)
		a[j] = heap1_down(p);
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