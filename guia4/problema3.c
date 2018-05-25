#include <stdio.h>
#include <stdlib.h>

/* Programa hecho sin ayuda. */

long long mcm(long long n1, long long n2);

int main(){
	long long n1, n2, m;
	printf("Ingrese dos numeros:\n");
	scanf("%lld%lld", &n1, &n2);
	while(n1<=0 || n2<=0){
		printf("Entrada invalida. Porfavor compruebe que los numeros sean naturales distintos de 0.\n");
		scanf("%lld%lld", &n1, &n2);
	}
	m=mcm(n1, n2);
	printf("El minimo comun multiplo es: %lld\n", m);
}

/* Primero hacemos que el "n1" siempre sea el mayor, luego vamos avanzando de a una unidad desde "n1",
hasta encontrar un numero que sea divisible por "n1" y "n2", luego retornamos ese numero. */

long long mcm(long long n1, long long n2){
	long long temp, i;
	if(n2>n1){
		temp=n1;
		n1=n2;
		n2=temp;
	}
	for(i=n1;i%n1!=0 || i%n2!=0;++i){}
	return i;
}