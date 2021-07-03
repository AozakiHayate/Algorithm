#include<bits/stdc++.h>
using namespace std;

int ack(int m, int n)
{
	if (m > 0 && n > 0)ack(m - 1, ack(m, n - 1));
	if (m > 0 && n == 0 )ack(m - 1, 1);
	else if (m == 0)return n + 1;
}


int main()
{
	int m, n,x;
	m = 2, n = 0;
	x=ack(m, n);
	printf("´ð°¸Îª:%d",x);
	return 0;
}