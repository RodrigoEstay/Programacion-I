#include <stdlib.h>
#include <stdio.h>

/* Como el ladron parte del codigo 0000 y empieza a subir, y ademas que el dueño
de la bicicleta cambia el seguro todos los dias entre 2 seguros y ademas parte
con el seguro 1, podemos darnos cuenta de que el ladron siempre intentara con
numeros pares para el seguro 1 y con numeros impares para el seguro 2, entonces
si estos no cumplen esas condiciones, el ladron nunca robara la bicicleta. */

int main (){
	int lock1, lock2;
	scanf("%d%d", &lock1, &lock2);
	if(lock1%2==0 || lock2%2==1)
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}