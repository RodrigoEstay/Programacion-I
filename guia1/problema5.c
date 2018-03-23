#include <stdlib.h>
#include <stdio.h>

/* No hay mucha ciencia, solo se revisan los numeros ingresados a ver si cumple
uno de todos los casos posibles. */

int main (){
	int num1, num2, num3;
	printf("Introduzca 3 numeros:\n");
	scanf("%d%d%d", &num1, &num2, &num3);
	if (num1<0 && num2<0 && num3<0)
		printf("todos\n");
	else if (num1>0 && num2>0 && num3>0)
		printf("ninguno\n");
	else if (num1>0 && num2<0 && num3<0)
		printf("al menos dos\n");
	else if (num1<0 && num2>0 && num3<0)
		printf("al menos dos\n");
	else if (num1<0 && num2<0 && num3>0)
		printf("al menos dos\n");
	else if (num1>0 && num2>0 && num3<0)
		printf("al menos uno\n");
	else if (num1<0 && num2>0 && num3>0)
		printf("al menos uno\n");
	else if (num1>0 && num2<0 && num3>0)
		printf("al menos uno\n");
	else
		printf("ERROR\n");
	return 0;
}