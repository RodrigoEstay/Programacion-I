#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, i, temp, k;
	do{
		printf("Ingrese un numero MAYOR QUE 0:\n");
		scanf("%d", &n);
	}while(n<=0);
	int data[n], imp[n]; // Creamos un arreglo para todos los numeros y uno para los impares.
	printf("Ingrese los %d numeros:\n", n);
	for(i=0;i<n;++i){
		scanf("%d", &data[i]);
	}

	/* Este es el mismo algoritmo creado en el problema 3, para mas explicacion sobre
	como funciona este algoritmo revise la informacion en el problema 3.
	El unico cambio que se le efectuo fue el cambio de los signos de mayor o menor en
	los "if" para ordenarlos de menor a mayor en vez de mayor a menor. */

	for(i=0;i<n;++i){
		for(k=i;k<n-i;++k){
			if(data[k]<data[i]){
				temp=data[i];
				data[i]=data[k];
				data[k]=temp;
			}
			if(data[k]>data[n-i-1]){
				temp=data[n-i-1];
				data[n-i-1]=data[k];
				data[k]=temp;
			}
		}
	}
	printf("Pares de menor a mayor: ");

	/* Si el numero es par, se imprime, ya que todos los numeros ya estan ordenados de
	menor a mayor, si el numero es impar se almacena en el arreglo de "imp". */

	for(i=0,k=0;i<n;++i){
		if(data[i]%2==0){
			printf("%d ", data[i]);
		}
		else{
			imp[k]=data[i];
			++k;
		}
	}
	printf("\nImpares de mayor a menor: ");

	/* Ya que ya almacenamos los impares en "imp" ordenados de menor a mayor,
	simplemente los imprimimos desde el final del arreglo hasta el principio
	para que esten ordenados de mayor a menor. */

	for(i=k-1;i>=0;--i){
		printf("%d ", imp[i]);
	}
	printf("\n");
	return 0;
}