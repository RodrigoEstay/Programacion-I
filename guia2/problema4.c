#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Programa hecho sin ayuda. */

int main(){
	int i, n, comp=0;
	printf("Ingrese un numero entero:\n");
	scanf("%d", &n);
	if(n<0){ // Si es negativo trabajamos con su valor absoluto.
		n=abs(n);
	}
	if(n==0 || n==1){ // Por definicion el 0 y 1 no son nada.
		printf("No es ni primo ni compuesto.\n");
		return 0;
	}
	for(i=2;i<sqrt(n);++i){ // Analizamos hasta la raiz para mas eficiencia.
		if(n%i==0){
			printf("Es compuesto.\n");
			return 0;
		}
	}
	printf("Es primo.\n"); // Si no se encontro divisor entonces es primo.
	return 0;
}
