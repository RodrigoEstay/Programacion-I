#include <stdio.h>
#include <stdlib.h>

/* Programa hecho sin ayuda. 

Para revisar si el primer decimal es mayor a 4, multiplicamos el flotante por 10 y luego
le hacemos casting a long long int (ya que el numero flotante puede ser mayor a lo que 
puede almacenar int) y de esta manera nos desacemos de los demas decimales, le aplicamos
modulo con 10, y obtendremos el valor del primer decimal, si este es menor a 4 imprimimos
el entero de "num", si no le sumamos uno. */

int main(){
	float num;
	scanf("%f", &num);
	printf("Redondeado al entero: %lld\n", ((long long int)(num*10)%10>4)?(long long int)num+1:(long long int)num);
	return 0;
}