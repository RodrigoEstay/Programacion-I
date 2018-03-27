#include <stdlib.h>
#include <stdio.h>

/* Ocupamos un switch, asi saltamos entre casos e imprimimos el numero de
de veces indicado. */

int main (){
	int num;
	printf("Ingrese un numero entre 1 y 10:\n");
	scanf("%d", &num);
	if(num<=0 || num>10){
		printf("ERROR NUMERO INGRESADO INVALIDO, PROGRAMA TERMINADO.\n");
		return 0;
	}
	switch(num){
		case 10:
		printf("paranguacutilimicuaro\n");
		case 9:
		printf("paranguacutilimicuaro\n");
		case 8:
		printf("paranguacutilimicuaro\n");
		case 7:
		printf("paranguacutilimicuaro\n");
		case 6:
		printf("paranguacutilimicuaro\n");
		case 5:
		printf("paranguacutilimicuaro\n");
		case 4:
		printf("paranguacutilimicuaro\n");
		case 3:
		printf("paranguacutilimicuaro\n");
		case 2:
		printf("paranguacutilimicuaro\n");
		case 1:
		printf("paranguacutilimicuaro\n");
	}
	return 0;
}