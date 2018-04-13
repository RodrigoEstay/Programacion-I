#include <stdio.h>
#include <stdlib.h>

int main (){
	int matrix[4][4], i, j, detSubMat[4], det=0;
	printf("Introduzca los 16 datos de la matriz:\n");
	for(i=0;i<4;++i){
		for(j=0;j<4;++j){
			scanf("%d", &matrix[i][j]);
		}
	}
	for(i=0;i<4;++i){
		
	}
	det=detSubMat[0]*detSubMat[3]-detSubMat[2]*detSubMat[1];
	printf("El determinante es: %d\n", det);
	return 0;
}