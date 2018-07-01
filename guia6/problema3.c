#include <stdlib.h>
#include <stdio.h>

// Codigo hecho sin ayuda.

int busquedaBinaria(int* v, int elem, int limInferior, int limSuperior);

// Main para probar la funcion.
int main(){
	int n;
	scanf("%d", &n);
	int v[n], i, lim, e;
	for(i=0;i<n;++i){
		scanf("%d", &v[i]);
	}
	scanf("%d%d", &lim, &e);
	printf("%d\n", busquedaBinaria(v, e, lim, n));
	return 0;
}

// 	Simplemente avanzamos por el vector desde el limite inferior, hasta que el limite
// inferior sea igual al limite superior, si se llega a esta situacion significa que
// no existe el elemento pedido en el rango dado.
// 	Cabe notar que los limites y las posiciones de los elementos se toman como que empiezan
// desde el 1, no desde el 0, es decir que el primer elemento esta en la posicion 1 (no 0).
int busquedaBinaria(int* v, int elem, int limInferior, int limSuperior){
	if(limInferior==limSuperior){
		return -1;
	}
	if(*(v+limInferior-1)==elem){
		return limInferior;
	}
	return busquedaBinaria(v, elem, limInferior+1, limSuperior);
}