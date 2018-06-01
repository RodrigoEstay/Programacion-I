#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Programa hecho sin ayuda.

char palindromo(char* cadena1);

int main(){ // main es para revisar el funcionamiento de la funcion.
	char cadena1[1000];
	printf("Ingrese la palabra a ser analizada:\n");
	scanf("%s", cadena1);
	if(palindromo(cadena1)){
		printf("Es palindromo.\n");
	}
	else{
		printf("No es palindromo.\n");
	}
	return 0;
}
char palindromo(char* cadena1){
	int n=strlen(cadena1), i; // Primero obtenemos el largo de la palabra.
	/* Luego revisamos para la primera mitad de los caracteres de la cadena si son iguales a los 
	caracteres del otro lado de la palabra, si no lo son altiro devolvemos el 0, pero si lo son
	se va a terminar el ciclo y se devolvera un 1. */
	for(i=0;i<n/2;++i){
		if(*(cadena1+i)!=*(cadena1+(n-1-i))){
			return 0;
		}
	}
	return 1;
}