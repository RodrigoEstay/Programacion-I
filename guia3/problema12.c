#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Programa hecho sin ayuda. 

Al declarar las variables notemos el largo maximo de las palabras es 200 y el numero maximo
de paabras es 400. */

int main(){
	char words[400][200], c;
	int lines=-2, wordLetter=0, wordPos=0, i, j, repeat;
	while(1){
		c=getchar(); // Obtenemos caracter a caracter.
		if(!lines){ // Si lines llega a 0 terminamos.
			break;
		}

		/* Si se encuentran letras mayusculas las pasamos a minusculas, de esta manera
		mas adelante no importaran si se hayan escrito con mayusculas o minusculas las
		palabras, aun asi se compararan correctamente. Notemos que considero palabras
		que solo estan escritas con letras de nuestro alfabeto (sin considerar la ñ). */

		if(c>='A' && c<='Z'){ 
			words[wordPos][wordLetter]=c-('A'-'a');
			++wordLetter;
		}
		else if(c>='a' && c<='z'){
			words[wordPos][wordLetter]=c;
			++wordLetter;
		}

		/* Si es que no se trata de una letra, podria tratarse del cambio de linea
		si es asi aumentamos el contador del cambio de linea, si este contador llega
		a 0 se termina el ciclo, asi solo se escanearan dos lineas (ya que al principio
		declaramos "lines" con el valor de -2). Luego si la letra en la que se iba es la
		primera, significa que el caracter escaneado se escaneo antes que cualquier
		palabra, asi evitamos de crear una palabra con solo un vector nulo poniendo un
		continue. Luego, si no se cumplen los casos anteriores, terminamos la palabra con
		un vector nulo y seguimos con la siguiente palabra, desde la primera letra. */

		else{
			if(c=='\n'){
				++lines;
			}
			if(wordLetter==0){
				continue;
			}
			words[wordPos][wordLetter]='\0';
			wordLetter=0;
			++wordPos;
		}
	}

	/* Luego, para cada palabra almacenada, la comparamos con todas las palabras almacenadas
	antes de esta, si se encuentra una palabra que es igual, decimos que se repite, y luego
	si es que la palabra no se repite, esta se imprime. */

	for(i=0;i<wordPos;++i){
		repeat=0;
		for(j=0;j<i;++j){
			if(!strcmp(words[j], words[i])){
				repeat=1;
				break;
			}
		}
		if(!repeat){
			printf("%s\n", words[i]);
		}
	}
	return 0;
}