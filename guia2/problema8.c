#include <stdio.h>
#include <stdlib.h>

int main (){
	int matrix[4][4], i, j, subDet1, subDet2, subDet3, subDet4;
	printf("Introduzca los 16 datos de la matriz 4x4:\n");
	for(i=0;i<4;++i){
		for(j=0;j<4;++j){
			scanf("%d", &matrix[i][j]);
		}
	}

	/* Ya que siempre sera una matriz 4x4, ocupamos la definicion de determinantes por submatrices,
	por lo tanto calculamos las 4 submatrices y las multiplicamos por su respectivo factor. */

	subDet1=matrix[1][1]*matrix[2][2]*matrix[3][3]+matrix[1][2]*matrix[2][3]*matrix[3][1]
		   +matrix[1][3]*matrix[2][1]*matrix[3][2]-matrix[1][3]*matrix[2][2]*matrix[3][1]
		   -matrix[1][1]*matrix[2][3]*matrix[3][2]-matrix[1][2]*matrix[2][1]*matrix[3][3];
	subDet2=matrix[1][0]*matrix[2][2]*matrix[3][3]+matrix[1][2]*matrix[2][3]*matrix[3][0]
		   +matrix[1][3]*matrix[2][0]*matrix[3][2]-matrix[1][3]*matrix[2][2]*matrix[3][0]
		   -matrix[1][0]*matrix[2][3]*matrix[3][2]-matrix[1][2]*matrix[2][0]*matrix[3][3];
	subDet3=matrix[1][0]*matrix[2][1]*matrix[3][3]+matrix[1][1]*matrix[2][3]*matrix[3][0]
		   +matrix[1][3]*matrix[2][0]*matrix[3][1]-matrix[1][3]*matrix[2][1]*matrix[3][0]
		   -matrix[1][1]*matrix[2][0]*matrix[3][3]-matrix[1][0]*matrix[2][3]*matrix[3][1];
	subDet4=matrix[1][0]*matrix[2][1]*matrix[3][2]+matrix[1][1]*matrix[2][2]*matrix[3][0]
		   +matrix[1][2]*matrix[2][0]*matrix[3][1]-matrix[1][2]*matrix[2][1]*matrix[3][0]
		   -matrix[1][1]*matrix[2][0]*matrix[3][2]-matrix[1][0]*matrix[2][2]*matrix[3][1];
	printf("El determinante es: %d\n", matrix[0][0]*subDet1-matrix[0][1]*subDet2+matrix[0][2]*subDet3-matrix[0][3]*subDet4);
	return 0;
}