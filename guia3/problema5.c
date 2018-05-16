#include <stdlib.h>
#include <stdio.h>

/* Programa hecho sin ayuda, solo con la ayuda de la calculadora de windows(en modo programador).

EXPLICACION DE LOS NUMEROS OCUPADOS(a la derecha estan sus valores en bits en 4 bytes):
255 		= 00000000 00000000 00000000 11111111 
65280 		= 00000000 00000000 11111111 00000000
16711680   	= 00000000 11111111 00000000 00000000
4278190080 	= 11111111 00000000 00000000 00000000

De esta manera solo comparamos el caracter escaneado con cada uno de los bytes del numero
escaneado, ya que al aplicar el operador & al numero escaneado con cada uno de estos numeros
anteriores y luego mover los bits para eliminar los bytes de solo 0, obtendremos un numero
correspondiente a cada byte del numero escaneado (num). si es contenido en alguno de estos
imprimimos que es contenido.*/

int main(){
	int num;
	char c;
	printf("Ingrese un entero:\n");
	scanf("%d", &num);
	getchar();
	printf("Ingrese un caracter:\n");
	scanf("%c", &c);
	if(c==(num&255)){
		printf("Contenido\n");
	}
	else if(c==((num&65280)>>8)){
		printf("Contenido\n");
	}
	else if(c==((num&16711680)>>16)){
		printf("Contenido\n");
	}
	else if(c==((num&4278190080)>>24)){
		printf("Contenido\n");
	}

	/* En el caso que no esta contenido, hacemos una suma del caracter "c" movido 3, 2, 1
	y 0 bytes hacia la izquierda, lo cual es equivalente a multiplicarlo por 2 por n veces,
	donde n serian los numeros anteriores. Al terminar este proceso se concatenara 4 veces
	el caracter "c".
	Se hace casting a int a cada "c" ocupada ya que en char no se pueden almacenar mas de
	 1 byte, asi no se podrian realizar estas sumas. */

	else{
		int conc=((int)c<<24)+((int)c<<16)+((int)c<<8)+c;
		printf("Al concatenar a 4 veces se obtiene:\n%d\n", conc);
	}
	return 0;
}