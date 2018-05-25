#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* El ayudante ma ayudo con la existencia de limts.h y el paso de matrices entre
funciones. */

int determinante(int n, int m1[n][n]);

int main(){ // este main es solo para probar la funcion.
	int n;
	scanf("%d", &n);
	int m1[n][n], i, j, det;
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			scanf("%d", &m1[i][j]);
		}
	}
	det=determinante(n,m1);
	printf("%d\n", det);
	return 0;
}

/* Calculamos las matrices para cuando n={2,3} con el metodo del triangulo, y cuando n=4
lo haceos por submatrices, en caso que "n" no es ninguno de estos valores, entonces hacemos
que retorne INT_MIN la cual es una constante definida por limits.h que tiene el valor minimo
que puede tomar int. */

int determinante(int n, int m1[n][n]){
	int det;
	if(n==2){
		det=m1[0][0]*m1[1][1]-m1[1][0]*m1[0][1];
	}
	else if(n==3){
		det=m1[0][0]*m1[1][1]*m1[2][2]+m1[0][1]*m1[1][2]*m1[2][0]
		   +m1[0][2]*m1[1][0]*m1[2][1]-m1[2][0]*m1[1][1]*m1[0][2]
		   -m1[2][1]*m1[1][2]*m1[0][0]-m1[2][2]*m1[1][0]*m1[0][1];
	}
	else if(n==4){
		int subDet1, subDet2, subDet3, subDet4;
		subDet1=m1[1][1]*m1[2][2]*m1[3][3]+m1[1][2]*m1[2][3]*m1[3][1]
	  		   +m1[1][3]*m1[2][1]*m1[3][2]-m1[1][3]*m1[2][2]*m1[3][1]
			   -m1[1][1]*m1[2][3]*m1[3][2]-m1[1][2]*m1[2][1]*m1[3][3];
		subDet2=m1[1][0]*m1[2][2]*m1[3][3]+m1[1][2]*m1[2][3]*m1[3][0]
		   	   +m1[1][3]*m1[2][0]*m1[3][2]-m1[1][3]*m1[2][2]*m1[3][0]
		       -m1[1][0]*m1[2][3]*m1[3][2]-m1[1][2]*m1[2][0]*m1[3][3];
		subDet3=m1[1][0]*m1[2][1]*m1[3][3]+m1[1][1]*m1[2][3]*m1[3][0]
		       +m1[1][3]*m1[2][0]*m1[3][1]-m1[1][3]*m1[2][1]*m1[3][0]
		       -m1[1][1]*m1[2][0]*m1[3][3]-m1[1][0]*m1[2][3]*m1[3][1];
		subDet4=m1[1][0]*m1[2][1]*m1[3][2]+m1[1][1]*m1[2][2]*m1[3][0]
		       +m1[1][2]*m1[2][0]*m1[3][1]-m1[1][2]*m1[2][1]*m1[3][0]
		       -m1[1][1]*m1[2][0]*m1[3][2]-m1[1][0]*m1[2][2]*m1[3][1];
		det=m1[0][0]*subDet1-m1[0][1]*subDet2+m1[0][2]*subDet3-m1[0][3]*subDet4;
	}
	else{
		det=INT_MIN;
	}
	return det;
}