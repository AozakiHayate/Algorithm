#include<stdio.h>
int main() {
	int a[7] = { 44,67,34,88,234,567,4 };	
	int i = 0,max = a[i];
	while (i < 7) {
		if (a[i] > max)max = a[i];
		i++;	
	}
	return 0;
}