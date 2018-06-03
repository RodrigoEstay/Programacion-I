#include <stdio.h>
#include <stdlib.h>

// Programa hecho sin ayuda.

int longitudPalabraMasLarga(int n, char crucigrama[n][n]);

int main(){ // Main para revisar la funcion de la funcion.
	int n, i, j;
	printf("Tamaño?\n");
	scanf("%d", &n);
	getchar();
	printf("Ingrese los %d valores\n", n*n);
	char mat[n][n];
	for(i=0;i<n;++i){ // Escaneamos los caracteres ignarando los saltos de linea.
		for(j=0;j<n;++j){
			scanf("%c", &mat[i][j]);
			if(mat[i][j]=='\n'){
				--j;
				continue;
			}
		}
	}
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			printf("%c", mat[i][j]);
		}
		printf("\n");
	}
	printf("la palabra mas larga es de %d letras.\n", longitudPalabraMasLarga(n,mat));
	return 0;
}

int longitudPalabraMasLarga(int n, char crucigrama[n][n]){
	int i, j, cont1, cont2, maxLen=0; // Asumimos que la palabra mas larga es de 0 caracteres.
	// Estos ciclos revisan a la vez el largo de las palabra tantos horizontales como verticales.
	for(i=0;i<n;++i){
		// Reiniciamos los contadores.
		cont1=0;
		cont2=0;
		for(j=0;j<n;++j){
			// Revisa el largo de la palabra horizontal al encontrarse con un - y si es mas largo
			// que el maximo largo registrado, se guarda como el nuevo largo maximo. Luego se reinicia
			// el contador horizontal.
			if(crucigrama[i][j]=='-'){
				if(cont1>maxLen){
					maxLen=cont1;
				}
				cont1=0;
			}
			else{
				++cont1; // Para cada caracter distinto de - sumamos el contador horizontal.
			}
			// Revisa el largo de la palabra vertical al encontrarse con un - y si es mas largo
			// que el maximo largo registrado, se guarda como el nuevo largo maximo. Luego se reinicia
			// el contador vertical.
			if(crucigrama[j][i]=='-'){
				if(cont2>maxLen){
					maxLen=cont2;
				}
				cont2=0;
			}
			else{
				++cont2; // Para cada caracter distinto de - sumamos el contador horizontal.
			}
		}
		// Revisamos el largo de las palabras, ya que al salir del ciclo se trata de las palabras
		// que llegaban hasta el final de la matriz, actualizamos el largo maximo si es necesario.
		if(cont1>maxLen){
			maxLen=cont1;
		}
		if(cont2>maxLen){
			maxLen=cont2;
		}
	}
	return maxLen;
}