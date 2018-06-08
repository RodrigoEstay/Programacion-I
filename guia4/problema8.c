#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Programa hecho sin ayuda

int caracteresComunes(char* cadena1, char* cadena2);

int main(){ // main es para probar la funcion.
	char cadena1[1000], cadena2[1000];
	printf("Introduzca dos palabras separadas por un espacio:\n");
	scanf("%s%s", cadena1, cadena2);
	printf("%d caracteres comunes\n", caracteresComunes(cadena1,cadena2));
	return 0;
}

int caracteresComunes(char* cadena1, char* cadena2){
	char comunes[260]; // En esta cadena se almacenaran los caracteres comunes encontrados.
	int i, j, k, contComunes=0, esNuevo;
	int n1=strlen(cadena1), n2=strlen(cadena2);
	// Para cada caracter de la cadena1 buscamos si tiene un igual en la cadena2.
	for(i=0;i<n1;++i){
		for(j=0;j<n2;++j){
			// Si se encuentra un caracter nuevo, revisamos si es que se ha encontrado antes.
			if(*(cadena1+i)==*(cadena2+j)){
				esNuevo=1;
				for(k=0;k<contComunes;++k){
					if(*(cadena1+i)==*(comunes+k)){
						esNuevo=0;
						break;
					}
				}
				// Si nunca se ha encontrado ese caracter, significa que es nuevo, asi que lo almacenamos
				// y aumentamos el contador de caracteres comunes.
				if(esNuevo){
					*(comunes+contComunes)=*(cadena1+i);
					++contComunes;
				}
				break;
			}
		}
	}
	return contComunes; // Retornamos el contador de caracteres comunes.
}