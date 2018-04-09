#include <stdio.h>
#include <stdlib.h>

int main (){
	int n[3], i, j, k, eigenvalues=0;
	scanf("%d", &n[0]);
	int a[n[0]];

	/* Los siguientes 3 ciclos for son para escanear los "n" valores dados
	para cada caso, los asignamos a 3 arreglos diferentes en cada ciclo. */

	for(i=0;i<n[0];++i){
		scanf("%d", &a[i]);
	}
	scanf("%d", &n[1]);
	int b[n[1]];
	for(i=0;i<n[1];++i){
		scanf("%d", &b[i]);
	}
	scanf("%d", &n[2]);
	int c[n[2]];
	for(i=0;i<n[2];++i){
		scanf("%d", &c[i]);
	}

	/* Comparamos todos los valores del arreglo "b" con los del arreglo "a". */

	for(i=0;i<n[0];++i){
		for(j=0;j<n[1];++j){

			/* Si algun valor del arreglo "a" es igual al del arreglo "b"
			vemos si algun valor del arreglo "c" es tambien igual a este valor,
			en tal caso sumamos un "eigenvalue". */

			if(a[i]==b[j]){
				for(k=0;k<n[2];++k){
					if(a[i]==c[k]){
						++eigenvalues;
					}
				}
			}
		}
	}
	printf("%d\n", eigenvalues);
	return 0;
}