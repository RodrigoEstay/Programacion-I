#include <stdio.h>
#include <stdlib.h>

/* Tenemos que existen 4 casos, cuando hay 0 bistecs, mas espacio para bistecs en la sarten que la cantidad de
bistecs, cuando los bistecs que sobran son menores o igual que la mitad de los bistecs que caben en la sarten
 y cuando es el caso contrario al anterior. */ 

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	if(n==0)
		printf("0\n");
	else if(k>n)
		printf("2\n");
	else if(n%k==0)
		printf("%d\n", (n*2)/k);
	else if(n%k<=k/2)
		printf("%d\n", (n/k)*2+1);
	else
		printf("%d\n", (n/k)*2+2);
	return 0;
}

/* Cabe destacar que en los ultimos dos casos lo que ocurre es que si sobran bistecs en la penultima "cocinada"
 y los que sobran son menor o igual a la mitad de lo que cabe en la sarten, se puede optimizar el tiempo de 
 coccion de estos ultimos dos grupos, ya que reemplazando bistecs a medio cocer con los crudos, y luego 
 sacando los ya cocidos por los que sacamos antes, ahorraremos un minuto, quitando un minuto a la formula
 del penultimo caso.

 y a la formula se le suma 2 minutos ya que como en n/k se trunca al entero, tendremos que perdemos un minuto
 gracias a la formula, y luego al multiplicar por dos terminamos perdiendo 2 minutos, los cuales se deben sumar
 al final. */