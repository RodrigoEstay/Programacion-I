#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	double a, b;
	scanf("%lf%lf", &a, &b);
	printf("%d %lf\n", (a-(int)a)==0, b-(int)b);
	return 0;
}