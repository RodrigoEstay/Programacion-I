#include <stdio.h>
#include <stdlib.h>

int main (){
	int n, i, j, k;
	printf("Ingrese un numero MAYOR QUE 2:\n");
	do{
		scanf("%d", &n);
	}while(n<=2);
	int num[n];
	printf("Ingrese los %d numeros:\n", n);
	for(i=0;i<n;++i){
		scanf("%d", &num[i]);
	}
	printf("Las combinaciones posibles de 3 numeros de los %d numeros ingresados son:\n", n);
	for(i=0;i<n-2;++i){
		for(j=i+1;j<n-1;++j){
			for(k=j+1;k<n;++k){
				printf("%d %d %d\n", num[i], num[j], num[k]);
			}
		}
	}
	return 0;
}