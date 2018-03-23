#include <stdlib.h>
#include <stdio.h>

int main (){
	int num1, num2, num3, num4;
	printf("Introduzca 4 numeros:\n");
	scanf("%d%d%d%d", &num1, &num2, &num3, &num4);
	if(num4>num3 && num3>num2 && num2>num1){
		printf("hola\n");
	}
}