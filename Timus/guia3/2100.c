#include <stdio.h>
#include <stdlib.h>

/* Programa hecho sin ayuda. */

/* almacenamos la cantidad total de invitados en "total", al principio
le sumamos los "n" invitados y los que se van a casar (2), luego para cada
string escaneado, le buscamos si tiene un "+", lo cual significa que trae
un invitado, asi que sumamos 1 a "total", luego si son exactamente 13,
sumamos uno mas por lo especificado en el problema. */

int main(){
	char guest[26];
	int n, total=0, i;
	scanf("%d", &n);
	total=total+n+2;
	while(n--){
		scanf("%s", guest);
		for(i=0;guest[i]!='\0';++i){
			if(guest[i]=='+'){
				++total;
			}
		}
	}
	if(total==13){
		++total;
	}
	printf("%d\n",total*100); // Lo multiplicamos por 100 por el precio por dummy.
	return 0;
}