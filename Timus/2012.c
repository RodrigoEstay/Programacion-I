#include <stdlib.h>
#include <stdio.h>

int main (){
	int f, queda;
	scanf("%d", &f);
	queda=5*45-((12-f)*45);
	if(queda>=0)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}