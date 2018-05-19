#include <stdio.h>
#include <stdlib.h>

/* Programa hecho sin ayuda 

Primero escaneamos hasta el salto de linea y luego revisamos si se encuentran
caracteres en el intervalo de mayusculas o minusculas, si es que no se cumple
ninguno de esos casos, entonces analizamos el caracter anterior, siempre y cuando
"i" sea distinto de 0 (para no ingresar a un lugar de memoria que no deberiamos),
asi si es que el caracter anterior era una letra, se trataba de una palabra.
Hacemos lo mismo cuando se llega al cambio de linea (cuando se termina el ciclo). */

int main(){
	char line[1000];
	int i, mayus=0, minus=0, words=0;
	scanf("%[^\n]", line);
	for(i=0;line[i]!='\0';++i){
		if(line[i]>='A' && line[i]<='Z'){
			++mayus;
		}
		else if(line[i]>='a' && line[i]<='z'){
			++minus;
		}
		else if(i!=0){
			if((line[i-1]>='a' && line[i-1]<='z') || (line[i-1]>='A' && line[i-1]<='Z')){
				++words;
			}
		}
	}
	if((line[i-1]>='a' && line[i-1]<='z') || (line[i-1]>='A' && line[i-1]<='Z')){
		++words;
	}

	/* Notemos que el numero de caracteres scaneados es igual al "i" sin contar el salto de linea. */

	printf("Mayusculas:\t%d\nMinusculas:\t%d\nPalabras:\t%d\nCaracteres\t%d\n", mayus, minus, words, i);
	return 0;
}