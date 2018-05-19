#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Programa hecho sin ayuda. */

int main(){
	char line[10000], line2[5000], temp;
	int n, i, j;
	scanf("%[^\n]", line);
	getchar(); // El getcgar es para saltarnos el '\n' al final de la primera linea.
	scanf("%[^\n]", line2);

	/* Obtenemos el largo de la linea 2 y luego vamos reemplazando el ultimo valor de
	la linea con el primero, el segundo con el penultimo, y asi hasta invertir la linea
	completamente, luego hacemos lo mismo con la linea 1. */

	n=strlen(line2);
	for(i=0;i<n/2;++i){
		temp=line2[i];
		line2[i]=line2[n-i-1];
		line2[n-i-1]=temp;
	}
	n=strlen(line);
	for(i=0;i<n/2;++i){
		temp=line[i];
		line[i]=line[n-i-1];
		line[n-i-1]=temp;
	}

	/* Ya que el "n" almacena el valor del largo de la linea 1, lo ocupamos para empezar a
	concatenar las dos lineas, desde el final de la linea 1 empezamos a poner los valores de
	la linea 2, cuando termina de poner valores, asignamos a la siguiente posicion el vector
	nulo para terminar el string. */

	for(i=n,j=0;line2[j]!='\0';++i,++j){
		line[i]=line2[j];
	}
	line[i]='\0';

	// Recorremos el arreglo resultante e imprimimos las vocales tanto mayusculas como minusculas.

	for(i=0;line[i]!='\0';++i){
		if(line[i]=='A' || line[i]=='E' || line[i]=='I' || line[i]=='O' || line[i]=='U' ||
		   line[i]=='a' || line[i]=='e' || line[i]=='i' || line[i]=='o' || line[i]=='u'){
			printf("%c", line[i]);
		}
	}
	printf("\n");
	return 0;
}