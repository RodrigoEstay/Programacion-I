#include <stdlib.h>
#include <stdio.h>

int main (){
	int num1, num2, num3;
	printf("Introduzca 3 numeros:\n");
	scanf("%d%d%d", &num1, &num2, &num3);
	if((num1%2==0 && num2%2==0 && num3%2==0) || (num1%2==1 && num2%2==1 && num3%2==1))
		printf("uniforme.\n");
	else
		printf("variadito.\n");
	return 0;
}