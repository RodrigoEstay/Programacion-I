#include <stdio.h>
#include <stdlib.h>

/* El practicante me ayudo a entender el problema. El programa es hecho sin ayuda. */

int main (){
	int n, i, j, j1, i1, iMin, jMin, min;

	/* Validamos la entrada. */

	do{
		printf("Ingrese un numero MAYOR A 1:\n");
		scanf("%d", &n);
	}while(n<=1);
	int original[n][n], distancias[n][n];
	printf("Ingrese %d valores para la matriz %dx%d:\n", n*n, n, n);
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			scanf("%d", &original[i][j]);
		}
	}
	printf("Matriz original:\n");
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			printf("%d\t", original[i][j]);
		}
		printf("\n");
	}

	/* Recorremos la matriz dos veces para encontrar los valores minimos y sus respectivas distancias para cada 
	valor de la matriz. */

	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			/* Asumimos valores iniciales, considerando de que i y j no sean considerados como posiciones 
			asumidas. */
			if(i==n-1 && j==n-1){
				min=abs(original[i][j]-original[n-2][n-2]);
				iMin=n-2;
				jMin=n-2;
			}
			else{
				min=abs(original[i][j]-original[n-1][n-1]);
				iMin=n-1;
				jMin=n-1;
			}
			for(i1=0;i1<n;++i1){
				for(j1=0;j1<n;++j1){
					/* En el caso que llegamos a la posicion original del valor a comparar, nos los saltamos. */ 
					if(i1==i && j1==j){
						continue;
					}
					/* Si se encuentra un nuevo minimo, guardamos el minimo y su posicion. */
					if(min>abs(original[i][j]-original[i1][j1])){
						min=abs(original[i][j]-original[i1][j1]);
						iMin=i1;
						jMin=j1;
					}
					/* Si se encuentra una diferencia igual al minimo pero con una menor distancia, entonces
					guardamos esta nueva distancia minima. */
					else if(min==abs(original[i][j]-original[i1][j1]) && abs(i1-i)+abs(j1-j)<abs(iMin-i)+abs(jMin-j)){
						iMin=i1;
						jMin=j1;
					}
				}
			}
			/* Guardamos la distancia minima respecto a las posiciones de la diferencia minima. */
			distancias[i][j]=abs(iMin-i)+abs(jMin-j);
		}
	}
	printf("Matriz distancias:\n");
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			printf("%d\t", distancias[i][j]);
		}
		printf("\n");
	}
	return 0;
}