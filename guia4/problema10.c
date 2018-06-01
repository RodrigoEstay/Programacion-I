#include <stdio.h>
#include <stdlib.h>

void modificarMatriz(int n, int m, int mat1[n][m]);

/* main es paa probar la funcion. */

int main(){
	int n, m, i, j;
	printf("De que dimensiones es su matriz? (nxm)\n");
	scanf("%d %d", &n, &m);
	int mat[n][m];
	printf("Ingrese los %d valores\n", n*m);
	for(i=0;i<n;++i){
		for(j=0;j<m;++j){
			scanf("%d", &mat[i][j]);
		}
	}
	printf("Cambiando valores...\n");
	modificarMatriz(n,m,mat);
	for(i=0;i<n;++i){
		for(j=0;j<m;++j){
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}

/* Simplemente recorremos la matriz cambiando los 1 por -1. */

void modificarMatriz(int n, int m, int mat1[n][m]){
	int i, j;
	for(i=0;i<n;++i){
		for(j=0;j<m;++j){
			if(mat1[i][j]==1){
				mat1[i][j]=-1;
			}
		}
	}
}