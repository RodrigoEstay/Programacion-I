#include <stdio.h>
#include <stdlib.h>

int main (){
	int n, i, j, j1, i1, iMin, jMin;
	printf("Ingrese un numero MAYOR A 0:\n");
	scanf("%d", &n);
	int original[n][n], distancias[n][n];
	printf("Ingrese %d valores para la matriz:\n", n*n);
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			scanf("%d", original[i][j]);
		}
	}
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			min=original[i][j];
			for(i1=0;i1<n;++i1){
				for(j1=0;j1<n;++j1){
					if(min>abs(original[i][j]-original[i1][j1])){
						min=abs(original[i][j]-original[i1][j1]);
						iMin=i1;
						jMin=j1;
					}
				}
			}
			distancias[i][j]=i1-i+j1-j;
		}
	}
	return 0;
}