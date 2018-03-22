#include <stdlib.h>
#include <stdio.h>

int main (){
	int num1, num2, num3;
	printf("Introduzca 3 numeros:\n");
	scanf("%d%d%d", &num1, &num2, &num3);
	if(num1<0)
		printf("%d ", num1);
	if(num2<0)
		printf("%d ", num2);
	if(num3<0)
		printf("%d ", num3);
	return 0;
}