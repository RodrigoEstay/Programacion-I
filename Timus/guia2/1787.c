#include <stdlib.h>
#include <stdio.h>

int main (){
	int n, a, sum=0, ai, i;
	scanf("%d%d", &n, &a);
	for(i=0;i<a;++i){ // Escaneamos el numero de autos para cada minuto.
		scanf("%d", &ai);

		/* Si la cantidad de autos supera el numero de autos que pueden pasar
		por minuto, significa que esa cantidad de autos se acomulan para el 
		siguiente minuto, en caso contrario no se acomulan autos para el siguiente
		minuto. */

		if(ai-n+sum>0){ 
			sum=ai-n+sum;
		}
		else{
			sum=0;
		}
	}
	printf("%d\n", sum); // Imprimimos la cantidad de autos que quedaron acomulados.
	return 0;
}