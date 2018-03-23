#include <stdio.h>
#include <stdlib.h>

int main (){
	int n, k;
	scanf("%d%d", &n, &k);
	if(n==0)
		printf("0\n");
	else if(k>n)
		printf("2 juju\n");
	else 
		printf("%d\n", (n*2)/k+1);
	return 0;
}