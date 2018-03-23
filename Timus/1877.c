#include <stdlib.h>
#include <stdio.h>

int main (){
	int lock1, lock2;
	scanf("%d%d", &lock1, &lock2);
	if(lock1%2==0 || lock2%2==1)
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}