#include <stdio.h>
#include <stdlib.h>

int main (){

	/* El arreglo "prec" almacenara los ultimos dos numeros de la sucesion,
	y tambien introducimos los primeros dos terminos de la sucesion.*/

	int n, prec[2]={0,1}, sum=0, i;
	do{ // Aqui seguiremos escaneando "n" hasta que introduzcan uno positivo.
		printf("Introduzca un numero POSITIVO:\n");
		scanf("%d", &n);
	}while(n<=0);
	if(n==1){
		printf("El primer termino de la sucesion de Fibonacci es:\n");
	}
	else{
		printf("los primeros %d terminos de la sucesion de Fibonacci son:\n", n);
	}
	for(i=0;i<n;++i){
		if(i<2){ // Con este if nos aseguramos que se impriman los primeros terminos.
			printf("%d ", prec[i%2]);
		}
		else{ //Le vamos asignando los terminos a la posicion 1 o 0 de "prec".
			sum=prec[1]+prec[0];
			prec[i%2]=sum;
			printf("%d ", sum);
		}
	}
	printf("\n");
	return 0;
}