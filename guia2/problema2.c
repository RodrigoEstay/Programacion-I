#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Programa hecho sin ayuda. */

int main(){
	int n, i;
	do{ // Escaneamos el input hasta que se introduzca un "n" positivo o igual a 0 y menor a 32 para
		// que no se produzca un overflow.
		printf("Ingrese un numero que NO SEA NEGATIVO y menor a 32 (debido a overflow):\n");
		scanf("%d", &n);
	}while(n<0 || n>31);
	if(n==0){
		printf("No puefo imprimir las 0 primeras potencias de 2.\n");
		return 0;
	}
	if(n==1){
		printf("La primera potencia de 2:\n");
	}
	else{
		printf("Las %d primeras potencias de 2:\n", n);
	}
	for(i=0;i<n;++i){ // Imprimimos las "n" primeras potencias de 2 con la funcion pow.
		printf("%d ", (int)pow(2,i)); // Hacemos casting a int.
	}
	printf("\n");
	return 0;
}