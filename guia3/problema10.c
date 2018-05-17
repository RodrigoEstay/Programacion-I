#include <stdio.h>
#include <stdlib.h>

/* Programa hecho sin ayuda.

Revisamos si cada caracter del string es una letra, si esta es mayuscula
le restamos la diferencia del valor de A y a lo cual lo dejara siendo la
misma letra pero en minuscula, hacemos lo mismo con las letras minusculas
pero en vez de restar la diferencia la sumamos. 

Notamos que este programa solo funciona con palabras sin espacio en blanco
si se quiere que funcione con espacios en blanco cambiamos el %s de la linea
20 por un %[^EOF], que escanea hasta el final del archivo. (pero no se si se
 puede usar)*/

int main(){
	char word[1000];
	int i;
	printf("Ingrese una cadena de caracteres:\n");
	scanf("%s", word);
	for(i=0;word[i]!='\0';++i){
		if(word[i]>='A' && word[i]<='Z'){
			word[i]-=('A'-'a');
		}
		else if(word[i]>='a' && word[i]<='z'){
			word[i]+=('A'-'a');
		}
	}
	printf("%s\n", word);
	return 0;
}