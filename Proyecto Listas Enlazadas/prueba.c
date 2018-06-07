#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *a;
	a=fopen("datos.txt", "w+");
	int n;
	fscanf(a, "%d", &n);
	printf("%d\n",n);	
	fclose(a);
	return 0;
}