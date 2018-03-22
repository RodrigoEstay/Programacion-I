#include <stdio.h>
#include <stdlib.h>

int main (){
	int num1, num2;
	printf("Ingrese dos numeros enteros:\n");
	scanf("%d%d", &num1, &num2);
	if(num2>num1)
		printf("El doble del mayor:\n%d\n", num2*2);
	else
		printf("El doble del mayor:\n%d\n", num1*2);
	return 0;
}