#include <stdio.h>
#include <stdlib.h>

/* Programa hecho sin ayuda. */

int main (){
	int n, i, j, k;
	/* Validamos la entrada. */
	printf("Ingrese un numero MAYOR QUE 2:\n");
	do{
		scanf("%d", &n);
	}while(n<=2);
	int num[n];
	printf("Ingrese los %d numeros:\n", n);
	for(i=0;i<n;++i){
		scanf("%d", &num[i]);
	}
	/* Aqui avanzamos por 3 posiciones distintas del arreglo, i que va desde el inicio hasta la posicion
	ante penultia, j que va desde la siguiente posicion de i hasta la penultima y k que va desde la 
	siguiente posicion de j hasta la ultuma. Y si mientras imprimimos los valores en estas posiciones, 
	terminaremos imprimiendo todas las posibles combinaciones de 3 de estos numeros, ya que no importa
	el orden de estas combinaciones. */
	printf("Las combinaciones posibles de 3 numeros de los %d numeros ingresados son:\n", n);
	for(i=0;i<n-2;++i){
		for(j=i+1;j<n-1;++j){
			for(k=j+1;k<n;++k){
				printf("%d %d %d\n", num[i], num[j], num[k]);
			}
		}
	}
	return 0;
}