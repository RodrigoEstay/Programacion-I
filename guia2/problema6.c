#include <stdio.h>
#include <stdlib.h>

/* Programa hecho sin ayuda. */

int main(){
	int n, i, j;
	do{ // Comprobamos que sea positivo el valor.
		printf("Introduzca un numero MAYOR A 0 (ADVERTENCIA, numeros altos pueden deformar la piramide):\n");
		scanf("%d", &n);
	}while(n<=0);
	int pascal1[n], pascal2[n];
	/* Designamos los primeros valores del triangulo de pascal. */
	pascal1[0]=1;
	pascal1[1]=1;
	/* Con este ciclo armamos cada piso del triangulo. */
	for(i=0;i<n;++i){
		/* Con este ciclo hacemos los espacios iniciales de cada linea para que el triangulo
		tome forma. */
		for(j=1;j<n-i;++j){
			printf("   ");
		}
		/* Aqui comprobamos si se tratan de los primeros dos pisos del triangulo,
		y les hacemos casos apartes ya que el algoritmo siguiente no es aplicable a
		estos dos primeros pasos. */
		if(i==0){
			printf("    1");
		}
		if(i==1){
			printf("    1     1");
		}
		if(i>1){
			/* Aqui generamos cada numero del respectivo piso. */
			for(j=0;j<=i;++j){
				/* Nos aseguramos que el principio y final del triangulo sean un 1. */
				if(j==0 || j==i){
					pascal2[j]=1;
				}
				/* Para cada posicion "j" del piso del triangulo, sera igual a la suma
				de los numeros del piso anterior en la misma posicion mas el anterior
				a este. */
				else{
					pascal2[j]=pascal1[j]+pascal1[j-1];
				}
			}
			/*imprimimos los numeros del piso y asignamos los numeros al arreglo del piso
			anterior para ocuparlo en la siguiente iteracion. */
			for(j=0;j<=i;++j){
				pascal1[j]=pascal2[j];
				printf("%5d ", pascal1[j]); //el 5 es para darle forma al triangulo (genera espacios en blanco).
			}
		}
		printf("\n");
	}
	return 0;
}