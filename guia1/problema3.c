#include <stdlib.h>
#include <stdio.h>

int main (){
	int num1, num2, num3;
	printf("Ingrese 3 numeros:\n");
	scanf("%d%d%d", &num1, &num2, &num3);
	if(num1-num2<(num3*num3)/num1)
		printf("Cumple invariante\n");
	return 0;
}