#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Programa hecho sin ayuda. */

/* Primero inicializamos un arreglo con el conteo de cada tipo de pinguino, luego dos arreglos, 
uno almacenara siempre la palabra "penguin", y el otro el tipo del pinguino para cada caso, y el
ultimo arreglo almacena los 3 nombres de los tipos de penguinos.
Luego para los "n" casos, escaneamos dos strings, el que nos interesa es el tipo, asi que lo
comparamos con cada tipo, si es igual a alguno aumentamos su respectivo contador.
Luego buscamos el valor maximo y lo imprimimos. */

int main(){
	int n, countType[3]={0,0,0};
	scanf("%d", &n);
	char penguin[10], type[15], types[3][14]={"Little", "Macaroni", "Emperor"};
	while(n--){
		scanf("%s %s", type, penguin);
		if(!strcmp(type,types[0])){
			countType[0]+=1;
		}
		else if(!strcmp(type,types[1])){
			countType[1]+=1;
		}
		else if(!strcmp(type,types[2])){
			countType[2]+=1;
		}
	}
	int max=0;
	for(n=0;n<3;++n){
		if(countType[max]<countType[n]){
			max=n;
		}
	}
	printf("%s Penguin\n", types[max]);
	return 0;
}