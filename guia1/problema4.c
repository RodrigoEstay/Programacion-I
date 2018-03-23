#include <stdlib.h>
#include <stdio.h>

/* Ocupamos la variable "temp" para almacenar el numero que va a ser el primero
en cambiarse, asi al cambiarlo por el otro numero no se pierde el dato guardado
por el primero. consiguiendo un swap exitoso. */

int main (){
	int num1, num2, temp;
	printf("Ingrese 2 numeros:\n");
	scanf("%d%d", &num1, &num2);
	if((num1<0 && num2>=0) || (num2<0 && num1>=0)){
		printf("Intercambiando numeros...\n");
		temp=num1;
		num1=num2;
		num2=temp;
	}
	else
		printf("No se cumple criteria para intercambio.\n");
	printf("num1=%d\nnum2=%d\n", num1, num2);
	return 0;
}