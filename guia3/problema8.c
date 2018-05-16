#include <stdio.h>
#include <stdlib.h>

/* Programa hecho sin ayuda.

NOTA: el orden de los bytes que denote es de iquierda a derecha.

ya que char solo aguanta un byte de memoria, al asignarle un numero de mayor
cantidad de bytes, este char solo almacenara el ultimo byte del numero, asi
vamos imrpimiendo lo pedido en cada byte, ya que nos vamos moviendo de a un 
byte y haciendo casting a char para que nos diga el ultimo byte. */ 

int main(){
	int num;
	printf("Ingrese un numero entero:\n");
	scanf("%d", &num);
	printf("primer byte:\t%c %d\n", (char)(num>>24), (char)(num>>24));
	printf("segundo byte:\t%c %d\n", (char)(num>>16), (char)(num>>16));
	printf("tercer byte:\t%c %d\n", (char)(num>>8), (char)(num>>8));
	printf("cuarto byte:\t%c %d\n", (char)(num), (char)(num));
	return 0;
}