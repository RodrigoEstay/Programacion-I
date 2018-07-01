#include <stdlib.h>
#include <stdio.h>

// Programa hecho sin ayuda.

int elementoMayorRecursivo(int* lista, int tam);

// main para probar la funcion.
int main(){
	int n;
	scanf("%d", &n);
	int i, lista[n];
	for(i=0;i<n;++i){
		scanf("%d", &lista[i]);
	}
	printf("%d\n", elementoMayorRecursivo(lista, n));
	return 0;
}

// 	Simplemente comparamos el elemento mayor de la cola con el de la cabeza, entonces mandamos la
// cola como otra lista a la misma funcion, se sigue de esta manera hasta que hayan 2 elementos o
// menos, si son 2, se retorna el mayor de estos, si es uno, significa que el tamaño inicial de la
// lista era de 1, asi que retornamos el unico elemento.
int elementoMayorRecursivo(int* lista, int tam){
	if(tam<=2){
		if(tam==1){
			return *lista;
		}
		if(*lista>*(lista+1)){
			return *lista;
		}
		else{
			return *(lista+1);
		}
	}
	int mayorCola=elementoMayorRecursivo(lista+1, tam-1);
	if(mayorCola>*lista){
		return mayorCola;
	}
	else{
		return *lista;
	}
}