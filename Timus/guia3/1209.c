#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Me han ayudado a interpretar las formulas de este problema.

Podemos observar que las posiciones de los 1 estan en:
1,2,4,7,11,... = 1+(0),1+(0+1),1+(0+1+2),1+(0+1+2+3),1+(0+1+2+3+4),...
lo cual es equivalente a 1+sum(i) con i desde 0 hasta n, donde n es la posicion
del numero "k" en el orden anterior, luego por definicion de esa sumatoria,
y algo de algebra tenemos:

1+sum(i)=1+n*(n+1)/2=(n^2+n+2)/2

entonces "k" debe cumplir que para algun n se de:

k=(n^2+n+2)/2=>2k=n^2+n+2=>0=n^2+n+(2-2k)=>n=(-1+-sqrt(1-4(2-2k)))/2
=>n=(-1+-sqrt(-7+8k))/2

Luego, como dijimos anteriormente, n es la posicion del "k" ingresado, entonces
mientras n sea entero significa que "k" se encuentra en la primera secuencia enunciada
entonces hay un 1 en la posicion "k", con mas algebra tenemos:

2n=-1+-sqrt(-7+8k)=>2n+1=+-sqrt(-7+8k)

Entonces observamos que a la izquierda de la ultima igualdad deberian presentarse solo enteros,
entonces para que se cumpla que n sea entero se debe cumplir que sqrt(-7+8k) sea entero, de esta
manera, para revisar que lo anterior es entero, hacemos que sea una variable "form", y luego 
revisamos si la resta de esa raiz menos la parte entera de esa raiz es cero, si lo es, significa 
que la raiz es un cuadrado perfecto, y de esta manera, un entero. */

int main(){
	long long int N, k, i;
	double form;
	scanf("%lld", &N);
	while(N--){
		scanf("%lld", &k);
		form=(sqrt(-7.0+8.0*(double)k));
		if(form-(int)form==0){
			printf("1");
		}
		else{
			printf("0");
		}
		if(N!=0){
			printf(" ");
		}
		else{
			printf("\n");
		}
	}
	return 0;
}
