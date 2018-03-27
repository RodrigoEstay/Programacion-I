#include <stdlib.h>
#include <stdio.h>

/* Primero separamos los numeros en pares que comparamos y asi definimos un par
mayor y uno menor, luego comparamos estos pares para saber que numero es el
primero, el ultimo, y los de en medio, finalmente comparamos los del medio
para obtener el orden de menor a mayor. */

int main (){
	int num1, num2, num3, num4;
	printf("Introduzca 4 numeros:\n");
	scanf("%d%d%d%d", &num1, &num2, &num3, &num4);
	int mayor1, mayor2, menor1, menor2, enmedio1, primero, ultimo, enmedio2;
	printf("Los numeros de menor a mayor:\n");
	if(num1>num2)
		mayor1=num1, menor1=num2;
	else
		menor1=num1, mayor1=num2;
	if(num3>num4)
		mayor2=num3, menor2=num4;
	else
		menor2=num3, mayor2=num4;
	if(mayor1>mayor2)
		primero=mayor1, enmedio1=mayor2;
	else
		enmedio1=mayor1, primero=mayor2;
	if(menor1>menor2)
		enmedio2=menor1, ultimo=menor2;
	else
		ultimo=menor1, enmedio2=menor2;
	if(enmedio1<enmedio2)
		printf("%d %d %d %d\n", ultimo, enmedio1, enmedio2, primero);
	else
		printf("%d %d %d %d\n", ultimo, enmedio2, enmedio1, primero);
	return 0;
}