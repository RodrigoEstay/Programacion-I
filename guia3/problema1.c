#include <stdio.h>
#include <stdlib.h>

/* Programa hecho sin ayuda. */

/* Validamos la entrada y luego ocupamos %c para caracter, %u para entero
sin signo, %o para octal y %x para hexadecimal. */

int main(){
	int num;
	do{
		printf("Ingrese un numero entre 0 y 255:\n");
		scanf("%d", &num);
	}while(num<0 || num>255);
	printf("Caracter:\t\t%c\n", num);
	printf("Entero sin signo:\t%u\n", num);
	printf("Numero octal:\t\t%o\n", num);
	printf("Numero hexadecimal:\t%x\n", num);
	return 0;
}