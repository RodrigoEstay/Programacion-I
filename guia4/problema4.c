#include <stdio.h>
#include <stdlib.h>

/* Programa hecho sin ayuda. */

long long mcd(long long n1, long long n2);

int main(){
	long long n1, n2, m;
	printf("Ingrese dos numeros:\n");
	scanf("%lld%lld", &n1, &n2);
	while(n1==0 || n2==0){
		printf("Entrada invalida. Porfavor compruebe que los numeros sean enteros distintos de 0.\n");
		scanf("%lld%lld", &n1, &n2);
	}
	m=mcd(n1, n2);
	if(m){
		printf("El maximo comun divisor es: %lld\n", m);
	}
	else{
		printf("No tienen maximo comun divisor.\n");
	}
	return 0;
}

/* Primero hacemos que "n1" siempre sea el menor. Luego buscamos un numero menor a "n1" tal que
cumpla que "n1" y "n2" sean divisibles por este numero, luego retornamos dicho numero.
Notar que se ocupo un while en vez de un for, ya que asi evitamos de que cuando "i" llegue
a 0 se realizen los modulos "n1%i" y "n2%i" lo cual dividiria por 0, lo cual mataria el
programa. */

long long mcd(long long n1, long long n2){
	long long temp, i;
	if(n1>n2){
		temp=n2;
		n2=n1;
		n1=temp;
	}
	i=n1;
	while(1){
		if(i==0){
			break;
		}
		if(n1%i==0 && n2%i==0){
			break;
		}
		--i;
	}
	return i;
}