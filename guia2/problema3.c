#include <stdio.h>
#include <stdlib.h>

/* Programa hecho sin ayuda. */

int main(){
	int n, i, temp, k, sum;
	do{ // Nos aseguramos que el "n" ingresado sea mayor a 0.
		printf("Ingrese un numero MAYOR QUE 0:\n");
		scanf("%d", &n);
	}while(n<=0);
	int data[n];
	printf("Ingrese los %d numeros:\n", n);
	for(i=0;i<n;++i){
		scanf("%d", &data[i]);
	}

	/* Lo siguiente es un algoritmo creado para ordenar los numeros de mayor a menor, lo que
	se hace es ir comparando los elementos de los extremos del arreglo con los del centro,
	haciendo que el elemento del extremo derecho (data[n-i-1], el "-1" esta porque los arreglos
	empiezan del 0) sea el menor del grupo, mientras el del extremo izquierdo (data[i]) es el mayor,
	realizando un intercambio cada vez que se encuentra un elemento menor o mayor, y a medida que
	el "i" aumenta, el grupo se va achicando hasta que ya se ordenaron todos los elementos. */

	for(i=0;i<n;++i){
		for(k=i;k<n-i;++k){
			if(data[k]>data[i]){
				temp=data[i];
				data[i]=data[k];
				data[k]=temp;
			}
			if(data[k]<data[n-i-1]){
				temp=data[n-i-1];
				data[n-i-1]=data[k];
				data[k]=temp;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d ",data[i] );
	}printf("\n");
	for(i=0, sum=0;i<n;++i){
		sum+=data[i]; // Calculamos la suma de todos los datos para luego sacar el promedio.
	}
	
	/* Como se dijo anteriormente, el menor de los elementos va a ser el elemento del extremo
	derecho, mientras el mayor va a ser el del extremo izquierdo, "sum/n" sera el promedio
	truncado a la unidad, finalmente usamos un operador ternario para ver si la cantidad de
	elementos ingresados es par o impar, si es par significa que la mediana sera igual al 
	promedio de los dos elementos del medio, en caso de que "n" sea impar solo habra un
	elemento en el medio, y ese sera la mediana. */

	printf("El menor:\t%d\nEl mayor:\t%d\nEl promedio:\t%d\nLa mediana:\t%d\n", data[n-1], 
		data[0], sum/n, (n%2==0)?(data[n/2]+data[n/2-1])/2:data[n/2]);
	printf("NOTA: Los valores anteriores estan truncados a la unidad.\n");
	return 0;
}
