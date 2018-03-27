#include <stdlib.h>
#include <stdio.h>

/* Es un poco confusa la sentencia "el primero restado del segundo" pero espero
que sea el segundo menos el primero, en el programa solo aplicamos la formula,
t en el caso de que son iguales, comparamos si el modulo de division es mayor
a 0, en tan caso se cumple invariante. */

int main (){
	int num1, num2, num3;
	printf("Ingrese 3 numeros:\n");
	scanf("%d%d%d", &num1, &num2, &num3);
	if((num2-num1<(num3*num3)/num1) || ((num2-num1==(num3*num3)/num1) && (0<(num3*num3)%num1)))
		printf("Cumple invariante\n");
	return 0;
}