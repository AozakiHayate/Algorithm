#include<bits/stdc++.h>
using namespace std;

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void display(int a[],int n){

	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void bubble(int a[], int n) //ð??????1
{
	for (int i = n; i > 1; i--) 
	{
		for (int j = 1; j < i; j++)
		{
			if (a[j - 1] > a[j])
				swap(a[j - 1], a[j]);
		}
	}
}

void bubble_d(int a[], int n)//??ϰ??ð?ݽ?˳
{
	for (int i = n; i > 1; i--) {
		for (int j = 1; j < i; j++) {
			if (a[j - 1] < a[j])
				swap(a[j - 1], a[j]);
		}
	}
}
void select1(int a[],int n)//ѡ??????
{
	for (int i = 0; i <= n - 2; i++)
	{
		int min = i;
		for (int j = i; j <= n-1; j++)
		{
			if (a[j] < a[min])
				(min = j);
		}
		swap(a[min], a[i]);
	}
} 

void select_d(int a[], int n)//??ϰ??ѡ????˳
{
	for (int i = 0; i < n - 1; i++) {
		int max = i;
		for (int j = i; j < n; j++)
		{
			if (a[max] < a[j]) 
				max=j;
		}
		swap(a[max], a[i]);
	}
}

void insert_swap(int a[], int n)//???????? ????
{
	for(int i=1;i<n;i++)
	{
		for (int j = i; j > 0 && a[j - 1] > a[j];j--)
		{
			swap(a[j - 1], a[j]);
		}
	}
}

void insert_shift(int a[], int n)//???????? shift
{
	for (int i = 1; i < n; i++)
	{
		if (a[i - 1] > a[i])
		{
			int tmp = a[i], j;
			for (j = i; j > 0 && a[j - 1] > tmp; j--)
			{
				a[j] = a[j - 1];
			}
			a[j] = tmp;
		}
	}
}

void quick_r(int a[], int s, int e)//???ŵݹ? ??֪
{
	if (s >= e)
		return;
	int i = s, j = e, x = a[s];
	while (i < j)
	{
		while (i<j && a[j]>x)j--;
		if (i < j) a[i++] = a[j];
		while (i < j && a[i] < x)i++;
		if (i < j) a[j--] = a[i];
	}
	a[i] = x;
	if (s < i - 1)quick_r(a, s, i - 1);
	if (e > i + 1)quick_r(a, i + 1, e);
}

void quicksort(int a[], int n)
{
	quick_r(a, 0, n - 1);
}


void quick_rd(int a[], int s, int e)//???? ??˳ ??ϰ
{
	if (s >= e) return;
	int i = s, j = e, x = a[s];
	while (i < j)
	{
		while (i < j && a[j] < x)j--;
		if (i < j) a[i++] = a[j];
		while (i < j && a[i] > x)i++;
		if (i < j) a[j--] = a[i];
	}
	a[i] = x;
	if (s < i - 1) quick_rd(a, s, i - 1);
	if (e > i + 1) quick_rd(a, i + 1, e);
}
void quicksort_d(int a[], int n)
{
	quick_rd(a, 0, n - 1);
}



void quick111(int a[], int s, int e)//ά???ٿƱ?׼??????
{
	if (s >= e)return;
	int L = s, R = e, mid = a[e];
	while (L < R) {
		while (L < R && a[L] < mid)L++;
		while (L < R && a[R] >= mid)R--;
		swap(a[L], a[R]);
	}
	if (a[L] >= a[e])swap(a[L], a[e]);
	else {
		L++;
		swap(a[L], a[e]);
	}
	if (L) {
		quick111(a, s, L - 1);
		quick111(a, L + 1, e);
	}
}

void quick1(int a[], int n)
{
	quick111(a, 0, n - 1);
}




int main() {
	int test[] = { 3,7,6,5,4,0,2,9};
	int n = sizeof(test)/sizeof(test[0]);
	printf("??ʼ??????Ϊ:");
	display(test,n);
	select1(test, n);
	printf("??????????Ϊ:");

	display(test, n);
	return 0;
}