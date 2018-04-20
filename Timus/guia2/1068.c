#include <stdlib.h>
#include <stdio.h>

/* Programa hecho sin ayuda. */

int main (){
	int n, neg=0, sum=0, i;
	scanf("%d", &n);
	if(n==0){ // En el caso de que "n=0", se tendra que la respuesta es 1.
		printf("1\n");
		return 0;
	}

	/* Si el "n" ingresado es menor a n entonces hacemos que n sea positivo
	para que funcione el ciclo de mas adelante, y hacemos "neg=1", para que
	se cumpla el if de despues. */

	if(n<0){
		n=abs(n);
		neg=1;
	}
	for(i=1;i<=n;++i){ //Sumamos todos los numeros de 1 a "n".
		sum+=i;
	}

	/* En el caso de que el "n" ingresado era negativo se ejecutara el if siguiente
	que transformara la suma a negativo y luego le restamos 1, ya que la suma va de
	"n" a 1, por lo tanto se le suma 1 al final, lo cual en este casoes restarle 1 al
	positivo. */

	if(neg){
		sum=-(sum-1);
	}
	printf("%d\n", sum);
	return 0;
}