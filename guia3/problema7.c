#include <stdlib.h>
#include <stdio.h>

/* Programa hecho sin ayuda. 

Escaneamos cada uno como string, luego avanzamos los string desde la posicion 2 ya que
desde alli empieza el numero, luego vamos asignandole al numero correspondiente el
numero que era anteriormente mas el valor del caracter contenido en la posicion en la
que se va del string menos el valor del caracter '0', (notese que el algoritmo funciona
ya que los N1 y N2 se incicializan con valor inicial 0) de esta manera se obtiene el
numero de cada string, luego se imprime el menor. */

int main(){
	char s1[100], s2[100];
	int N1=0, N2=0, i;
	scanf("%s%s", s1, s2);
	for(i=2;s1[i]!='\0';++i){
		N1=N1*10+s1[i]-'0';
	}
	for(i=2;s2[i]!='\0';++i){
		N2=N2*10+s2[i]-'0';
	}
	printf("El menor es:\n%d\n", (N1>N2)?N2:N1);
	return 0;
}