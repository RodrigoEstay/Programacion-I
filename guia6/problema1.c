#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Codigo hecho solo.

int esPalindromo(char* palabra, int tam);

// main es para probar el funcionamiento de la funcion.
int main(){
	char pal[10000];
	scanf("%s", pal);
	printf("%s.\n", (esPalindromo(pal,strlen(pal)))?"Si":"No");
	return 0;
}

// Comparamos el primer elemento de la palabra con el ultimo, si son iguales puede tratarse
// de un palindromo, asi que quitamos el primer y ultimo elemento de la palabra y lo mandamos
// a la funcion. Asi sigue hasta que el tamaño de la funcion sea de dos o uno, o que no se
// cumpla que es palindromo.
int esPalindromo(char* palabra, int tam){
	if(tam==1){
		return 1;
	}
	if(palabra[0]!=palabra[tam-1]){ // Si estos elementos son distintos, no es palindromo.
		return 0;
	}
	// Como este else depende del if anterior, solo se ejecutara cuando queden dos elementos
	// que son iguales.
	else if(tam==2){
		return 1;
	}
	char temp[tam-1];
	strcpy(temp, (palabra+1)); // Eliminamos primera letra.
	temp[tam-2]='\0'; // Eliminamos la ultima letra.
	esPalindromo(temp,tam-2);
}