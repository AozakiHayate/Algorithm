#include<bits/stdc++.h>
using namespace std;

typedef struct Lstack {
	int data;
	Lstack * next;
}Lstack;

Lstack* push(Lstack* top, int v) {
	Lstack* st = new Lstack;
	st->data = v;
	st->next = top;
	top = st;
	return top;
}

Lstack* pop(Lstack* top) 
{
	if (top) {
		Lstack* p = top;
		top = top->next;
		printf("����ջ��Ԫ�أ�%d  ", p->data);
		if (top) {
			printf("ջ��Ԫ��ĿǰΪ��%d\n", top->data);
		}
		else {
			printf("ջĿǰΪ��\n"); 
		}
		free(p);
	}
	else printf("ջ��û��Ԫ��\n");
	return top;
}

int main() {
	Lstack* stack = NULL;
	stack = push(stack, 2);
	stack = push(stack, 4);
	stack = push(stack, 6);
	stack = push(stack, 8);
	stack = pop(stack);
	stack = pop(stack);
	stack = pop(stack);
	stack = pop(stack);
	stack = pop(stack);
	stack = pop(stack);
	return 0;

}