#include <stdlib.h>
#include <stdio.h>

/* Programa hecho sin ayuda. */

int main (){
	int n, k, ai, i, surv=0, left=0;
	scanf("%d%d", &n, &k);
	for(i=0;i<n;++i){ // Escaneamos la cantidad de booms booms de cada cargamento para cada bloque.

		/* Para cada cantidad de booms booms de cada cargamento, nos fijamos si
		es menor a la cantidad de androides en cada bloque, en tal caso, sumamos
		la resta de entre estos a la cantidad de supervivientes, en el caso contrario
		sumamos los booms booms restantes a "left". */

		scanf("%d", &ai);
		if(k-ai>0){
			surv=surv+k-ai;
		}
		else{
			left=left+ai-k;
		}
	}
	printf("%d %d\n", left, surv);
	return 0;
}